#include "Herbivore.hpp"

using namespace common;


void Herbivore::accept(Visitor &visitor)
{
    visitor.visit(*this);
}