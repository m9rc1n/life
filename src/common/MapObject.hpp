#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include <boost/serialization/export.hpp>
#include <boost/serialization/nvp.hpp>

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
        return x_pos_;
    }

    /**
     * @brief
     * Funkcja wykonuje jeden krok symulacji dla obiektu.
     *
     * @param miliseconds czas w milisekundach, który upłynął od poprzedniego kroku
     */
    virtual void simulationStep(int miliseconds) = 0;
    
    
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
BOOST_SERIALIZATION_ASSUME_ABSTRACT(MapObject);

#endif