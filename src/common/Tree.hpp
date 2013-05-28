<<<<<<< HEAD
#ifndef COMMON_TREE_HPP
#define COMMON_TREE_HPP

#include "MapObject.hpp"

namespace common
{
    class Tree: public MapObject
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
            return new Tree(*this);
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
#ifndef TREE_HPP
#define TREE_HPP

#endif // TREE_HPP
>>>>>>> 7c59914ddb14ddda7465e784eb78c267d664536a
