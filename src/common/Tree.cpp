#include "Tree.hpp"

using namespace common;

void Tree::accept(Visitor &visitor)
{
    visitor.visit(*this);
}