#if not defined MAP_H
#define MAP_H

#include <vector>

#include <boost/serialization/base_object.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/export.hpp>

#include "MapObject.hpp"
#include "Creature.hpp"
#include "Herbivore.hpp"
#include "Predator.hpp"


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
     * @todo write me
     */
    Map(int width, int height):
      width_ (width),
      height_(height)
    {
        
    }
    
    /**
     * @brief
     * TYMCZASOWA FUNKCJA DO TESTOWANIA
     * 
     * @todo USUN MNIE GDY NAPISZESZ BARDZIEJ ZAAWANSOWANE TESTY!!!
     */
    void createSomeRandomObjects()
    {
        objects.push_back(new Herbivore(2, 3));
        objects.push_back(new Predator(5, 2));
        objects.push_back(new Predator(7, 3));
    }
    
    /**
     * @brief
     * TYMCZASOWA FUNKCJA DO TESTOWANIA
     * 
     * @todo USUN MNIE GDY NAPISZESZ BARDZIEJ ZAAWANSOWANE TESTY!!!
     */
    int countObjects()
    {
        return objects.size();
    }
    
    /**
     * @brief
     * Przeprowadza jeden krok symulacji dla wszystkich obiektow na mapie.
     *
     * @param miliseconds czas w milisekundach, który upłynął od poprzedniego kroku
     */
    void simulationStep(int miliseconds)
    {
        for(std::vector<MapObject*>::iterator iter = objects.begin(); iter != objects.end(); ++iter)
        {
            (*iter) -> simulationStep(miliseconds);
        }
    }
    
protected:
    /**
     * @brief
     * Wektor zawierający wszystkie obiekty znajdujące się na mapie
     * 
     * Rozróżnienie typów obiektów zagwarantują wirtualne metody w hierarchii
     * klas dziedziczących po typie MapObject.
     * 
     * @todo zmienic strukture danych na cos lepszego (moze mapa?)
     */
    std::vector <MapObject *> objects;
    
    const int width_;
    const int height_;
    
    friend class boost::serialization::access;
    
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & BOOST_SERIALIZATION_NVP(objects);
        ar & width_;
        ar & height_;
    }
};

#endif