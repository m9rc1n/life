#include "ActionPerformVisitor.hpp"

ActionPerformVisitor::ActionPerformVisitor(common::Creature &visited_creature, common::Map *visited_map, double time_interval, std::vector<server::Action*> &actions):
    visited_creature_(visited_creature),
    visited_map_(visited_map),
    time_interval_(time_interval),
    actions_(actions)
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
    if(visited_creature_.knows(predator))
    {
        if(visited_creature_type_ == PREDATOR)
        {
            actions_.push_back(new server::ProcreatingAction(visited_creature_.getMaslovPyramid()->getProcreatingPriority(), visited_creature_, predator));
        }
        else
        {
            actions_.push_back(new server::RunningAction(visited_creature_.getMaslovPyramid()->getHuntingOrRunningPriority(), visited_creature_, predator));
        }
    }
}
void ActionPerformVisitor::visit(common::Herbivore &herbivore)
{
    if(visited_creature_.knows(herbivore))
    {
        if(visited_creature_type_ == PREDATOR)
        {
            actions_.push_back(new server::HuntingAction(visited_creature_.getMaslovPyramid()->getHuntingOrRunningPriority(), visited_creature_, herbivore));
        }
        else
        {
            actions_.push_back(new server::ProcreatingAction(visited_creature_.getMaslovPyramid()->getProcreatingPriority(), visited_creature_, herbivore));
        }
    }
}
void ActionPerformVisitor::visit(common::Waterhole &waterhole)
{
    if(visited_creature_.knows(waterhole))
    {
        actions_.push_back(new server::DrinkingAction(visited_creature_.getMaslovPyramid()->getDrinkingPriority(), visited_creature_, waterhole));
    }
}
void ActionPerformVisitor::visit(common::Lair &lair)
{
    if(visited_creature_.knows(lair))
    {
        actions_.push_back(new server::SleepingAction(visited_creature_.getMaslovPyramid()->getSleepingPriority(), visited_creature_, lair));
    }
}
void ActionPerformVisitor::visit(common::Tree &tree)
{
    if(visited_creature_.knows(tree) and visited_creature_type_ == HERBIVORE)
    {
        actions_.push_back(new server::EatingAction(visited_creature_.getMaslovPyramid()->getEatingPriority(), visited_creature_, tree));
    }
}
