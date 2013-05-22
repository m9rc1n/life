#ifndef HERBIVORE_H
#define HERBIVORE_H

#include "Creature.hpp"


/**
 * @todo write me
 */
class Herbivore: public Creature
{ 
public:  
    /**
     * @brief
     * Konstruktor wywoływany w przypadku, gdy stworzenie jest generowane na początku gry.
     * Wspolrzedne stworzenia są podawane jako parametry konstruktora.
     *
     * Stworzenie pojawi się w wybranym miejscu na planszy (powinno ono byc wolne).
     */
    Herbivore(double x_pos, double y_pos):
        Creature(x_pos, y_pos)
    {} // kod w klasie Creature
    
    /**
     * @brief
     * Funkcja wykonuje jeden krok symulacji dla obiektu.
     *
     * Poszczególne elementy symulacji (poszukiwanie pożywienia, poszukiwanie wody, polowanie,
     * ucieczka, poszukiwanie schronienia, poszukiwanie partnera do reprodukcji) są wywoływane
     * w odpowiedniej kolejności, wg piramidy potrzeb osobnika.
     *
     * @param miliseconds czas w milisekundach, który upłynął od poprzedniego kroku
     */
    virtual void simulationStep(int miliseconds)
    {
        
    }
    
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & boost::serialization::base_object<Creature>(*this);
    }
};


#endif