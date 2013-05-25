#ifndef VISITOR_H
#define VISITOR_H

#include "MapObject.hpp"
#include "Map.hpp"

namespace common
{
    class Visitor
    {
        virtual void visitMapObject(MapObject&);
        virtual void visitMap(Map&);
        virtual void visitStat();
    };
}

#endif // VISITOR_H
