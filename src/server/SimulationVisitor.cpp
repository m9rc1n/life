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

    bool action_performed = 0;

    for(auto iter = actions.begin(); iter != actions.end() and not action_performed; ++iter)
    {
        action_performed = (*iter)->perform(time_interval_);
    }

    predator.makeHungry(time_interval_);
    predator.makeThirsty(time_interval_);
    predator.makeTired(time_interval_);
}

void SimulationVisitor::visit(common::Herbivore &herbivore)
{
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

    bool action_performed = 0;

    for(auto iter = actions.begin(); iter != actions.end() and not action_performed; ++iter)
    {
        action_performed = (*iter)->perform(time_interval_);
    }

    herbivore.makeHungry(time_interval_);
    herbivore.makeThirsty(time_interval_);
    herbivore.makeTired(time_interval_);
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
