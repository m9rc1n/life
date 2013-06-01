#include "InternalSimulationVisitor.hpp"

InternalSimulationVisitor::InternalSimulationVisitor(common::Creature &visited_creature, common::Map *visited_map):
    visited_creature_(visited_creature),
    visited_map_(visited_map)
{
}

void InternalSimulationVisitor::visit(common::Map &)
{
}
void InternalSimulationVisitor::visit(common::MapObject &)
{
    // abstract class, nothing to do here
}
void InternalSimulationVisitor::visit(common::Creature &)
{
    // abstract class, nothing to do here
}
void InternalSimulationVisitor::visit(common::Predator &)
{
}
void InternalSimulationVisitor::visit(common::Herbivore &)
{
}
void InternalSimulationVisitor::visit(common::Waterhole &)
{

}
void InternalSimulationVisitor::visit(common::Lair &)
{
}
void InternalSimulationVisitor::visit(common::Tree &)
{
}