#ifndef COMMON_MAP_H
#define COMMON_MAP_H

#include <vector>

#include <boost/serialization/base_object.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/export.hpp>

#include "Herbivore.hpp"
#include "Predator.hpp"
#include "Visitor.hpp"

#include "Lair.hpp"
#include "Tree.hpp"
#include "Waterhole.hpp"

#include "../server/SimulationVisitor.hpp"

namespace common
{
    
    /**
    * @brief
    * Klasa reprezentujaca mape (obszar gry) wraz z zawartymi na niej obiektami.
    * 
    * Klasa może być serializowana przy pomocy boost::serialize
    * 
    * @todo write me
    */
    class Map
    {
    public:
        /**
         * @brief
         * Konstruktor tworzacy pusta mape
         */
        Map():
            Map(.0,.0)
        {
        }

        /**
         * @brief
         * Konstruktor tworzacy pusta mape o zadanych wymiarach
         */
        Map(int width, int height):
            width_ (width),
            height_(height) {}

        /**
         * @brief
         * Konstruktor kopiujący kopiuje elementy kolekcji #obiekty
         */
        Map(const Map &another):
            width_ (another.width_),
            height_(another.height_)
        {
            for (std::vector <MapObject *>::const_iterator iter = another.objects.begin(); iter != another.objects.end(); ++iter)
            {
                objects.push_back((*iter)->clone());
            }
        }

        /**
         * @brief
         * Operator przypisania kopiuje elementy kolekcji #obiekty
         */
        Map& operator = (const Map &another)
        {
            if(this == &another)
            {
                return *this;
            }
            width_ = another.width_;
            height_ = another.height_;
            for (std::vector <MapObject *>::iterator iter = objects.begin(); iter != objects.end(); ++iter)
            {
                delete *iter;
            }
            objects.clear();
            for (std::vector <MapObject *>::const_iterator iter = another.objects.begin(); iter != another.objects.end(); ++iter)
            {
                objects.push_back((*iter)->clone());
            }
        }

        /**
         * @brief destruktor zwalnia dynamicznie alokowaną pamięć z tablicy objects
         */
        ~Map()
        {
            for(auto iter: objects)
            {
                delete iter;
            }
        }

        /**
         * @brief setter dla width_
         */
        int getWidth()
        {
            return width_;
        }

        /**
         * @brief setter dla height_
         */
        int getHeight()
        {
            return height_;
        }

        /**
         * @brief dodaje obiekt do mapy
         * @pre object jest wskaźnikiem na poprawnie utworzony obiekt klasy pochodnej po MapObject
         */
        void appendObject(MapObject *object)
        {
            objects.push_back(object);
        }
        
        /**
         * @brief
         * Przyjecie (acceptance) wizytatora.
         */
        virtual void accept(Visitor &);
        
        /**
         * @brief
         * Serializacja (np na potrzeby zapisu/odczytu map na dysku)
         * 
         * Do serializacji uzywamy boost::serialize. Aby prawidlowo serializowac
         * klasy dziedziczace po MapObject, nalezy uzyc makra BOOST_CLASS_EXPORT
         * w pliku cpp, w ktorym beda wolane metody serializacji.
         * 
         * Wiecej informacji:
         * http://stackoverflow.com/questions/3396330/where-to-put-boost-class-export-for-boostserialization
         *
         */
        template<class Archive>
        void serialize(Archive & ar, const unsigned int version)
        {
            ar & BOOST_SERIALIZATION_NVP(objects);
            ar & width_;
            ar & height_;
        }

    protected:
        /**
         * @brief
         * Wektor zawierający wszystkie obiekty znajdujące się na mapie
         * 
         * Rozróżnienie typów obiektów zagwarantują wirtualne metody w hierarchii
         * klas dziedziczących po typie MapObject.
         */
        std::vector <MapObject *> objects;
        
        int width_;
        int height_;
        
        AllocationCounter counter;

        friend class boost::serialization::access;
    };
}

#endif
