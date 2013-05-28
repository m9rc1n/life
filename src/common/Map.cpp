#include "Map.hpp"


using namespace common;

void common::Map::accept(Visitor &visitor)
{
    visitor.visit(*this);
}
