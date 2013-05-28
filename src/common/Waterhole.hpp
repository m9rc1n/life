<<<<<<< HEAD
#ifndef COMMON_WATERHOLE_HPP
#define COMMON_WATERHOLE_HPP

#include "MapObject.hpp"

namespace common
{
    
    class Waterhole: public MapObject
    {
        
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
            return new Waterhole(*this);
        }
        
        /**
         * @brief
         * Przyjecie (acceptance) wizytatora.
         */
        virtual void accept(Visitor &);
        
    };
};

#endif
=======
#ifndef WATERHOLE_HPP
#define WATERHOLE_HPP

#endif // WATERHOLE_HPP
>>>>>>> 7c59914ddb14ddda7465e784eb78c267d664536a
