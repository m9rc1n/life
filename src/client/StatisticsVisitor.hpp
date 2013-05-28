#ifndef STATISTICSVISITOR_H
#define STATISTICSVISITOR_H

#include "../common/Visitor.hpp"


// forward declarations:
class Map;
class Predator;
class Herbivore;
class Waterhole;
class Lair;
class Tree;

namespace client
{


    /**
    * @brief
    * Wizytator robiący statystyki obiektów na mapie.
    *
    * Konkretne wizytatory mogą np. symulować poszczególne obiekty,
    * wyświetlać je na ekranie, zbierać statystyki etc.
    */

    class StatisticsVisitor : public common::Visitor
    {
    public:
        StatisticsVisitor();

        void visit(Map &);
        void visit(Predator &);
        void visit(Herbivore &);
        void visit(Waterhole &);
        void visit(Lair &);
        void visit(Tree &);
    };
}


#endif // STATISTICSVISITOR_H
