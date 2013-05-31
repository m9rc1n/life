#ifndef SIMULATIONVISITOR_HPP
#define SIMULATIONVISITOR_HPP

#include "../common/Visitor.hpp"

namespace server
{
    /**
     * @brief
     * Wizytator dokonujący symulacji obiektów na mapie.
     */
    class SimulationVisitor : public common::Visitor
    {
    public:
        SimulationVisitor();

        virtual void visit(common::Map &);
        virtual void visit(common::Predator &);
        virtual void visit(common::Herbivore &);
        virtual void visit(common::Waterhole &);
        virtual void visit(common::Lair &);
        virtual void visit(common::Tree &);
    };
}

#endif // SIMULATIONVISITOR_H
