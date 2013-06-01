#ifndef COMMON_MAPOBJECT_H
#define COMMON_MAPOBJECT_H

#include <boost/serialization/export.hpp>
#include <boost/serialization/nvp.hpp>
#include <cmath>

#include "Visitor.hpp"


namespace common
{

    /**
    * @brief
    * Klasa abstrakcyjna reprezentująca dowolny obiekt znajdujący się na mapie
    * (stworzenie, drzewo itp).
    */
    class MapObject
    {
    public:
        /// konstruktor losujący pozycję dla obiektu
        MapObject():
            /// musimy chyba przekazać na samym początku api w argumentach
            x_pos_(0),
            y_pos_(0)
        {}

        /// konstruktor z podaną pozycją startową
        MapObject(double x_pos, double y_pos):
            x_pos_(x_pos),
            y_pos_(y_pos)
        {}

        /// konstruktor kopiujący pozycję z innego obiektu
        MapObject(const MapObject &another):
            x_pos_(another.x_pos_),
            y_pos_(another.y_pos_)
        {}

        virtual ~MapObject(){}

        /// przemieszcza obiekt na zadaną pozycję
        void moveTo(double x_pos, double y_pos)
        {
            x_pos_ = x_pos;
            y_pos_ = y_pos;
        }

        /// przemieszcza obiekt o zadany wektor
        void moveByVector(double x_vec, double y_vec)
        {
            x_pos_ += x_vec;
            y_pos_ += y_vec;
        }

        /// zwraca współrzędną X położenia
        double getX() const
        {
            return x_pos_;
        }

        /// zwraca współrzędną Y położenia
        double getY() const
        {
            return y_pos_;
        }

        /// zwraca odległość od drugiego obiektu
        double getDistance(const MapObject &another) const
        {
            double dx = getX() - another.getX();
            double dy = getY() - another.getY();
            return sqrt(dx*dx + dy*dy);
        }

        /**
         * @brief
         * Tworzy głęboką kopię obiektu
         *
         * @returns wskaznik do nowego obiektu (utworzonego przez new)
         *
         * @todo moze zmienic na sprytny wskaznik?
         */
        virtual MapObject *clone() = 0;

        /**
         * @brief
         * Przyjecie (acceptance) wizytatora.
         */
        virtual void accept(Visitor &) = 0;

        /**
        * @brief
        * Serializacja
        *
        * @see Map::serialize
        */
        template<class Archive>
        void serialize(Archive & ar, const unsigned int version)
        {
            ar & x_pos_;
            ar & y_pos_;
        }

    protected:
        /// składowa x położenia
        double x_pos_;

        /// składowa y położenia
        double y_pos_;
    };
    BOOST_SERIALIZATION_ASSUME_ABSTRACT(MapObject)
}

#endif
