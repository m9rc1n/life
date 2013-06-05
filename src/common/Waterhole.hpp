#ifndef COMMON_WATERHOLE_HPP
#define COMMON_WATERHOLE_HPP

#include "MapObject.hpp"

namespace common
{
    
    class Waterhole: public MapObject
    {
    public:

        Waterhole(double x_pos, double y_pos):
            MapObject(x_pos, y_pos)
        {
            // ...
        }

        virtual~Waterhole(){};
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
            return static_cast<MapObject*>(new Waterhole(*this));
        }
        
        /**
         * @brief
         * Przyjecie (acceptance) wizytatora.
         */
        virtual void accept(Visitor &);
    };
}

#endif // WATERHOLE_HPP
