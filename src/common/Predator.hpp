#ifndef PREDATOR_H
#define PREDATOR_H

#include "Creature.hpp"

class Predator: public Creature
{
public:
    /**
     * @brief
     * Konstruktor wywoływany w momencie narodzin stworzenia. Parametry stworzenia są
     * ustalane na podstawie odpowiednich parametrów ojca i matki.
     *
     * Ten konstruktor zakłada, że matka i ojciec znajdują się w tym samym miejscu.
     * Nowe stworzenie również pojawi się w tym samym miejscu.
     *
     * @param mother referencja do matki
     * @param father referencja do ojca
     */
    Predator(const Predator &mother, const Predator &father):
        Creature(mother, father)
    {} // kod w klasie Creature

    
    /**
     * @brief
     * Konstruktor wywoływany w przypadku, gdy stworzenie jest generowane na początku gry.
     * Wspolrzedne stworzenia są podawane jako parametry konstruktora.
     *
     * Stworzenie pojawi się w wybranym miejscu na planszy (powinno ono byc wolne).
     */
    Predator(double x_pos, double y_pos):
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

#endif // PREDATOR_H
