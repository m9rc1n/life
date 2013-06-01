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

        virtual void visit(common::Map &);
        virtual void visit(common::Predator &);
        virtual void visit(common::Herbivore &);
        virtual void visit(common::Waterhole &);
        virtual void visit(common::Lair &);
        virtual void visit(common::Tree &);

        virtual void visit(common::MapObject &){} // formalnosc
        virtual void visit(common::Creature &){} // formalnosc
    };
}


#endif // STATISTICSVISITOR_H
