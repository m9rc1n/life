#ifndef INTERNALSIMULATIONVISITOR_HPP
#define INTERNALSIMULATIONVISITOR_HPP

#include "../common/Visitor.hpp"

class InternalSimulationVisitor : public common::Visitor
{
public:
    InternalSimulationVisitor(common::Creature &visited_creature, common::Map *visited_map);

    virtual void visit(common::Map &);
    virtual void visit(common::MapObject &);
    virtual void visit(common::Creature &);
    virtual void visit(common::Predator &);
    virtual void visit(common::Herbivore &);
    virtual void visit(common::Waterhole &);
    virtual void visit(common::Lair &);
    virtual void visit(common::Tree &);

private:
    common::Creature &visited_creature_;
    common::Map *visited_map_;
};

#endif // INTERNALSIMULATIONVISITOR_HPP
