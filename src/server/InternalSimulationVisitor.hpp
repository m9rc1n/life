#ifndef INTERNALSIMULATIONVISITOR_HPP
#define INTERNALSIMULATIONVISITOR_HPP

#include "../common/Visitor.hpp"
#include "AwarenessDetector.hpp"

class InternalSimulationVisitor : public common::Visitor
{
public:
    InternalSimulationVisitor(common::Creature &visited_creature, common::Map *visited_map, double time_interval);

    virtual void visit(common::Map &);
    virtual void visit(common::MapObject &);
    virtual void visit(common::Creature &);
    virtual void visit(common::Predator &predator);
    virtual void visit(common::Herbivore &herbivore);
    virtual void visit(common::Waterhole &);
    virtual void visit(common::Lair &);
    virtual void visit(common::Tree &);

private:
    void addToListOfKnownObjects(common::MapObject &object);

    common::Creature &visited_creature_;
    common::Map *visited_map_;
    double time_interval_;
};

#endif // INTERNALSIMULATIONVISITOR_HPP
