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

        virtual void visit(common::Map &);
        virtual void visit(common::Predator &);
        virtual void visit(common::Herbivore &);
        virtual void visit(common::Waterhole &);
        virtual void visit(common::Lair &);
        virtual void visit(common::Tree &);
    };
}

#endif // PAINTINGVISITOR_H
