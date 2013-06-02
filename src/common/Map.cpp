#include "Map.hpp"

void common::Map::accept(Visitor &visitor)
{
    visitor.visit(*this);
    // instead of: for(std::vector<common::MapObject*>::iterator iter = objects.begin(); iter != objects.begin(); ++iter)
    // visitor.visit(**iter);

    for(std::vector<common::MapObject *>::iterator iter = objects.begin(); iter != objects.end(); ++iter)
    {
        (*iter)->accept(visitor);
    }
}
