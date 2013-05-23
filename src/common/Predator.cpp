#include "Predator.hpp"

using namespace common;

void Predator::accept(Visitor &visitor)
{
    visitor.visit(*this);
}