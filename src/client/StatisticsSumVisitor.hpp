#ifndef STATISTICSVISITOR_H
#define STATISTICSVISITOR_H

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

    class StatisticsSumVisitor : public common::Visitor
    {
    public:
        StatisticsSumVisitor(Statistics *stat);

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


#endif // STATISTICSVISITOR_H
