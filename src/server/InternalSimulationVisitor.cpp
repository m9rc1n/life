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
    if(visited_creature_.getIdentifier() == predator.getIdentifier())
    {
        return;
    }
    bool aware = AwarenessDetector::isAware(visited_creature_, predator);
    if(aware)
    {
        addToListOfKnownObjects(predator);
    }
}
void InternalSimulationVisitor::visit(common::Herbivore &herbivore)
{
    if(visited_creature_.getIdentifier() == herbivore.getIdentifier())
    {
        return;
    }
    bool aware = AwarenessDetector::isAware(visited_creature_, herbivore);
    if(aware)
    {
        addToListOfKnownObjects(herbivore);
    }
}
void InternalSimulationVisitor::visit(common::Waterhole &waterhole)
{
    bool aware = AwarenessDetector::isAware(visited_creature_, waterhole);
    if(aware)
    {
        addToListOfKnownObjects(waterhole);
    }
}
void InternalSimulationVisitor::visit(common::Lair &lair)
{
    bool aware = AwarenessDetector::isAware(visited_creature_, lair);
    if(aware)
    {
        addToListOfKnownObjects(lair);
    }
}
void InternalSimulationVisitor::visit(common::Tree &tree)
{
    bool aware = AwarenessDetector::isAware(visited_creature_, tree);
    if(aware)
    {
        addToListOfKnownObjects(tree);
    }
}

void InternalSimulationVisitor::addToListOfKnownObjects(common::MapObject &object)
{
    visited_creature_.setObjectKnown(object);
}
