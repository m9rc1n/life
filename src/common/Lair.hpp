// <<<<<<< HEAD
#ifndef COMMON_LAIR_HPP
#define COMMON_LAIR_HPP

#include "MapObject.hpp"

namespace common
{
    
    class Lair: public MapObject
    {
    public:
        Lair(double x_pos, double y_pos):
            MapObject(x_pos, y_pos)
        {
            // ...
        }


        /**
         * @brief
         * Przyjecie (acceptance) wizytatora.
         */
        virtual void accept(Visitor &);
        
        
        /**
         * @brief
         * Tworzy głęboką kopię obiektu
         * 
         * @returns wskaznik do nowego obiektu (utworzonego przez new)
         * 
         * @todo moze zmienic na sprytny wskaznik?
         */
        virtual MapObject *clone()
        {
            return new Lair(*this);
        }
    };
}

#endif // LAIR_HPP
