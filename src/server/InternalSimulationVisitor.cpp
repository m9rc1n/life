#include "InternalSimulationVisitor.hpp"

InternalSimulationVisitor::InternalSimulationVisitor(common::Creature &visited_creature, common::Map *visited_map, double time_interval):
    visited_creature_(visited_creature),
    visited_map_(visited_map),
    time_interval_(time_interval)
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
void InternalSimulationVisitor::visit(common::Predator &predator)
{
    bool aware = AwarenessDetector::isAware(visited_creature_, predator);


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
