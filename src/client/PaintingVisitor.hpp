#ifndef PAINTINGVISITOR_H
#define PAINTINGVISITOR_H

#include "../common/Visitor.hpp"
#include <QImage>
#include "../common/Map.hpp"

namespace client
{


    /**
    * @brief
    * Wizytator rysujący obiekty na mapie.
    */

    class PaintingVisitor : public common::Visitor
    {
    public:
        PaintingVisitor(QImage *image);

        virtual void visit(common::Map &);
        virtual void visit(common::Predator &obj);
        virtual void visit(common::Herbivore &obj);
        virtual void visit(common::Waterhole &obj);
        virtual void visit(common::Lair &obj);
        virtual void visit(common::Tree &obj);

        virtual void visit(common::MapObject &){}
        virtual void visit(common::Creature &){}

    private:
        void drawDeadCreature(common::Creature &);

        QImage *image;
    };
}

#endif // PAINTINGVISITOR_H
