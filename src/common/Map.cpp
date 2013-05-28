#include "Map.hpp"

void common::Map::accept(Visitor &visitor)
{
    visitor.visit(*this);
}
