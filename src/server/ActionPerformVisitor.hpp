#ifndef ACTIONPERFORMVISITOR_HPP
#define ACTIONPERFORMVISITOR_HPP

#include "../common/Visitor.hpp"
#include "../common/Map.hpp"
#include "../common/Predator.hpp"
#include "../common/Herbivore.hpp"
#include "../common/MaslovPyramid.hpp"
#include "actions/Action.hpp"

class ActionPerformVisitor : public common::Visitor
{
public:
    ActionPerformVisitor(common::Creature &visited_creature, common::Map *visited_map, double time_interval, std::vector<server::Action> &actions);

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
    double time_interval_;
    enum {PREDATOR, HERBIVORE} visited_creature_type_;
    std::vector<server::Action> &actions_;
};

#endif // ACTIONPERFORMVISITOR_HPP
