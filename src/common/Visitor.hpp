<<<<<<< HEAD
#ifndef COMMON_VISITOR_HPP
#define COMMON_VISITOR_HPP

 
namespace common
{
    
    // forward declarations:
    class Map;
    class Predator;
    class Herbivore;
    class Waterhole;
    class Lair;
    class Tree;
    
    /**
     * @brief
     * Abstrakcyjny wizytator wizytujący obiekty na mapie.
     * 
     * Konkretne wizytatory mogą np. symulować poszczególne obiekty,
     * wyświetlać je na ekranie, zbierać statystyki etc.
     */
    
    class Visitor
    {
    public:
        virtual void visit(Map &) = 0;
        virtual void visit(Predator &) = 0;
        virtual void visit(Herbivore &) = 0;
        virtual void visit(Waterhole &) = 0;
        virtual void visit(Lair &) = 0;
        virtual void visit(Tree &) = 0;
    };
};

#endif
=======
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
>>>>>>> 7c59914ddb14ddda7465e784eb78c267d664536a
