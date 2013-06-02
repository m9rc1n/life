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
