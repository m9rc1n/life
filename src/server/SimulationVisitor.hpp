#ifndef SIMULATIONVISITOR_HPP
#define SIMULATIONVISITOR_HPP

#include "../common/Visitor.hpp"
#include "../common/Map.hpp"
#include "../common/Tree.hpp"
#include "../common/Herbivore.hpp"
#include "../common/Predator.hpp"
#include "../common/Lair.hpp"
#include "../common/Waterhole.hpp"
#include "../common/MapObject.hpp"

#include "InternalSimulationVisitor.hpp"
#include "ActionPerformVisitor.hpp"

#include "actions/DrinkingAction.hpp"
#include "actions/EatingAction.hpp"
#include "actions/HuntingAction.hpp"
#include "actions/ProcreatingAction.hpp"
#include "actions/RunningAction.hpp"
#include "actions/SleepingAction.hpp"

namespace server
{
    /**
     * @brief
     * Wizytator dokonujący symulacji obiektów na mapie.
     */
    class SimulationVisitor : public common::Visitor
    {
    public:
        SimulationVisitor(double time_interval);

        virtual void visit(common::Map &);
        virtual void visit(common::MapObject &);
        virtual void visit(common::Creature &);
        virtual void visit(common::Predator &);
        virtual void visit(common::Herbivore &);
        virtual void visit(common::Waterhole &);
        virtual void visit(common::Lair &);
        virtual void visit(common::Tree &);

    private:
        common::Map *visited_map_;
        double time_interval_;

    };
}

#endif // SIMULATIONVISITOR_H
