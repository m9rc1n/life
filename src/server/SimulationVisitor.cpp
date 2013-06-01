#include "SimulationVisitor.hpp"
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

    InternalSimulationVisitor internal_visitor(predator, visited_map_);
    visited_map_->accept(internal_visitor);

}

void SimulationVisitor::visit(common::Herbivore &herbivore)
{
    InternalSimulationVisitor internal_visitor(herbivore, visited_map_);
    visited_map_->accept(internal_visitor);

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
