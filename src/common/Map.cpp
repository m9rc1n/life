#include "Map.hpp"

void common::Map::accept(Visitor &visitor)
{
    visitor.visit(*this);
    // instead of: for(std::vector<common::MapObject*>::iterator iter = objects.begin(); iter != objects.begin(); ++iter)
    // visitor.visit(**iter);

    Predator *predzio = new Predator(52.9, 24.4);

    Tree * dzewo = new Tree(52.1, 23.3);

    visitor.visit(*predzio);
    visitor.visit(*dzewo);

    for(auto iter: objects)
    {
        visitor.visit(*iter);
    }
}
