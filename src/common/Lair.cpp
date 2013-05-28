#include "Lair.hpp"

using namespace common;


void Lair::accept(Visitor &visitor)
{
    visitor.visit(*this);
}

void Lair::draw()
{}
