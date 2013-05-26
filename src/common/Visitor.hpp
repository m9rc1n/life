#ifndef VISITOR_H
#define VISITOR_H
namespace common
{

    class MapObject;
    class Map;

    class Visitor
    {
        public:
            virtual void visitMapObject(MapObject&);
            virtual void visitMap(Map&);
            virtual void visitStat();
    };
}

#endif // VISITOR_H
