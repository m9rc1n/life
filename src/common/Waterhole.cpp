#include "Waterhole.hpp"

using namespace common;

void Waterhole::accept(Visitor &visitor)
{
    visitor.visit(*this);
}
