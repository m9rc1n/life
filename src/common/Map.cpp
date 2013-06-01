#include "Map.hpp"

void common::Map::accept(Visitor &visitor)
{
    visitor.visit(*this);
    // instead of: for(std::vector<common::MapObject*>::iterator iter = objects.begin(); iter != objects.begin(); ++iter)
    // visitor.visit(**iter);

    Predator *predzio = new Predator(1, 1);

    Tree * dzewo = new Tree(3, 3);

    visitor.visit(*predzio);
    visitor.visit(*dzewo);

    for(auto iter: objects)
    {
        visitor.visit(*iter);
    }
}
