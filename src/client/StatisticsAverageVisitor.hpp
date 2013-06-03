#ifndef STATISTICSAVERAGEVISITOR_H
#define STATISTICSAVERAGEVISITOR_H


#include "../common/Visitor.hpp"
#include "Statistics.hpp"
#include "../common/Map.hpp"

namespace client
{
    /**
     * @brief
     * Wizytator robiący statystyki obiektów na mapie.
     *
     * Konkretne wizytatory mogą np. symulować poszczególne obiekty,
     * wyświetlać je na ekranie, zbierać statystyki etc.
     */

    class StatisticsAverageVisitor : public common::Visitor
    {
    public:
        StatisticsAverageVisitor(Statistics *stat);

        virtual void visit(common::Map &);
        virtual void visit(common::Predator &obj);
        virtual void visit(common::Herbivore &obj);
        virtual void visit(common::Waterhole &);
        virtual void visit(common::Lair &);
        virtual void visit(common::Tree &);

        virtual void visit(common::MapObject &){} // formalnosc
        virtual void visit(common::Creature &){} // formalnosc
    private:
        Statistics      *stat;
    };
}


#endif // STATISTICSAVERAGEVISITOR_H
