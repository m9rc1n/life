#include "SimulationVisitor.hpp"
#include "../common/Config.hpp"
#include "../common/MaslovPyramid.hpp"
#include <vector>

using namespace server;

SimulationVisitor::SimulationVisitor(double time_interval):
    time_interval_(time_interval)
{
}

void SimulationVisitor::visit(common::Map &map)
{
    visited_map_ = &map;
}

void SimulationVisitor::visit(common::Predator &predator)
{
    if(predator.isDead()) return;

    if(predator.isSleeping())
    {
        predator.updateSleepTime(time_interval_);
        return;
    }
    if(predator.isProcreating())
    {
        predator.updateProcreatingTime(time_interval_);
        return;
    }

    predator.updateListOfKnownObjects(time_interval_);

    InternalSimulationVisitor internal_visitor(predator, visited_map_, time_interval_);
    visited_map_->accept(internal_visitor); // this updates predator.knownObjects

    common::MaslovPyramid *predators_pyramid = common::Config::getInstance()->predators_pyramid;

    if(!predators_pyramid)
    {
        predators_pyramid = new common::MaslovPyramid(1,2,3,4,5);
    }

    std::vector<server::Action*> actions;
    ActionPerformVisitor action_visitor(predator, visited_map_, time_interval_, actions);
    visited_map_->accept(action_visitor);

    server::Action::compare cmp;
    std::sort(actions.begin(), actions.end(), cmp);

    std::sort(actions.begin(), actions.end(), server::Action::compare());

    bool action_performed = 0;

    for(auto iter = actions.begin(); iter != actions.end() and not action_performed; ++iter)
    {
        action_performed = (*iter)->perform(time_interval_);
    }

    predator.makeHungry(time_interval_/45000);
    predator.makeThirsty(time_interval_/45000);
    predator.makeTired(time_interval_/45000);
    predator.makeOlder(time_interval_/15000);
    predator.updateTimeToProcreate(time_interval_/25000);

    if(!action_performed)
    {
        if(predator.isActive())
        {
            predator.setInactive();
        }
        predator.doSomething(time_interval_);
    }
    else
    {
        predator.setActive();
    }

    normalizeXY(predator);
}

void SimulationVisitor::visit(common::Herbivore &herbivore)
{
    if(herbivore.isDead()) return;

    if(herbivore.isSleeping())
    {
        herbivore.updateSleepTime(time_interval_);
        return;
    }

    if(herbivore.isProcreating())
    {
        herbivore.updateProcreatingTime(time_interval_);
        return;
    }

    herbivore.updateListOfKnownObjects(time_interval_);

    InternalSimulationVisitor internal_visitor(herbivore, visited_map_, time_interval_);
    visited_map_->accept(internal_visitor);

    common::MaslovPyramid *herbivores_pyramid = common::Config::getInstance()->herbivores_pyramid;

    if(!herbivores_pyramid)
    {
        herbivores_pyramid = new common::MaslovPyramid(1,2,3,4,5);
    }

    std::vector<server::Action*> actions;
    ActionPerformVisitor action_visitor(herbivore, visited_map_, time_interval_, actions);
    visited_map_->accept(action_visitor);

    server::Action::compare cmp;
    std::sort(actions.begin(), actions.end(), cmp);

    bool action_performed = 0;

    for(auto iter = actions.begin(); iter != actions.end() and not action_performed; ++iter)
    {
        action_performed = (*iter)->perform(time_interval_);
    }

    herbivore.makeHungry(time_interval_/45000);
    herbivore.makeThirsty(time_interval_/45000);
    herbivore.makeTired(time_interval_/45000);
    herbivore.makeOlder(time_interval_/15000);
    herbivore.updateTimeToProcreate(time_interval_/25000);

    if(!action_performed)
    {
        if(herbivore.isActive())
        {
            herbivore.setInactive();
        }
        herbivore.doSomething(time_interval_);
    }
    else
    {
        herbivore.setActive();
    }

    normalizeXY(herbivore);
}

void SimulationVisitor::normalizeXY(common::Creature &creature)
{
    int w = common::Config::getInstance()->getMapWidth();
    int h = common::Config::getInstance()->getMapHeight();

    int x = creature.getX();
    int y = creature.getY();

    int sgn = (rand() % 5) - 2; // od -2 do 2

    if(x < 1.8)
    {
        creature.rotateByAngleInDegrees(sgn * 45);
        creature.moveTo(2, creature.getY());
    }
    if(y < 1.8)
    {
        creature.rotateByAngleInDegrees(sgn * 45);
        creature.moveTo(creature.getX(), 2);
    }
    if(x > w - 1.8)
    {
        creature.rotateByAngleInDegrees(sgn * 45);
        creature.moveTo(w-2, creature.getY());
    }
    if(y > h - 1.8)
    {
        creature.rotateByAngleInDegrees(sgn * 45);
        creature.moveTo(creature.getX(), h-2);
    }
}

void SimulationVisitor::visit(common::Waterhole &)
{
    // nothing, passive object
}

void SimulationVisitor::visit(common::Lair &)
{
    // nothing, passive object
}

void SimulationVisitor::visit(common::Tree &tree)
{
    // tree grows
    tree.growLeafs(time_interval_);
}

void SimulationVisitor::visit(common::MapObject &)
{
    // nothing here (abstract type)
}

void SimulationVisitor::visit(common::Creature &)
{
    // nothing here (abstract type)
}
