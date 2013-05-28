#ifndef PAINTINGVISITOR_H
#define PAINTINGVISITOR_H

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
    * Wizytator rysujący obiekty na mapie.
    *
    * Konkretne wizytatory mogą np. symulować poszczególne obiekty,
    * wyświetlać je na ekranie, zbierać statystyki etc.
    */

    class PaintingVisitor : public common::Visitor
    {
    public:
        PaintingVisitor();

        void visit(Map &);
        void visit(Predator &);
        void visit(Herbivore &);
        void visit(Waterhole &);
        void visit(Lair &);
        void visit(Tree &);
    };
}

#endif // PAINTINGVISITOR_H
