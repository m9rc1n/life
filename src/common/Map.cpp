#include "Map.hpp"

void common::Map::accept(Visitor &visitor)
{
    visitor.visit(*this);
    // instead of: for(std::vector<common::MapObject*>::iterator iter = objects.begin(); iter != objects.begin(); ++iter)
    for(auto iter: objects)
    {
        visitor.visit(*iter);
    }
}
