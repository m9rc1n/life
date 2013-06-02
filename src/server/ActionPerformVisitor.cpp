#include "ActionPerformVisitor.hpp"
#include "ActionPerformVisitor.hpp"

ActionPerformVisitor::ActionPerformVisitor(common::Creature &visited_creature, common::Map *visited_map, double time_interval):
    visited_creature_(visited_creature),
    visited_map_(visited_map),
    time_interval_(time_interval)
{
    if(dynamic_cast<common::Predator *>(&visited_creature_))
    {
        visited_creature_type_ = PREDATOR;
    }
    else
    {
        visited_creature_type_ = HERBIVORE;
    }
}

void ActionPerformVisitor::visit(common::Map &)
{
}
void ActionPerformVisitor::visit(common::MapObject &)
{
    // abstract class, nothing to do here
}
void ActionPerformVisitor::visit(common::Creature &)
{
    // abstract class, nothing to do here
}
void ActionPerformVisitor::visit(common::Predator &predator)
{
}
void ActionPerformVisitor::visit(common::Herbivore &herbivore)
{
}
void ActionPerformVisitor::visit(common::Waterhole &waterhole)
{
}
void ActionPerformVisitor::visit(common::Lair &lair)
{
}
void ActionPerformVisitor::visit(common::Tree &tree)
{
}
