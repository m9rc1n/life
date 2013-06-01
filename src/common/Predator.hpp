#ifndef COMMON_PREDATOR_H
#define COMMON_PREDATOR_H

#include "Creature.hpp"

namespace common
{

    /**
     * @brief
     * Abstrakcyjna klasa reprezentujaca drapieznika
     */
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
            Creature(mother)
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
         * Tworzy głęboką kopię obiektu
         *
         * @returns wskaznik do nowego obiektu (utworzonego przez new)
         *
         * @todo moze zmienic na sprytny wskaznik?
         */
        virtual MapObject *clone()
        {
            return new Predator(*this);
        }

        virtual ~Predator()
        {}

        /**
         * @brief
         * Przyjecie (acceptance) wizytatora.
         */
        virtual void accept(Visitor & visitor)
        {
            visitor.visit(*this);
        }

        /**
         * @brief
         * Serializacja
         *
         * @see Map::serialize
         */
        template<class Archive>
        void serialize(Archive & ar, const unsigned int version)
        {
            ar & boost::serialization::base_object<Creature>(*this);
        }
    };
}
#endif // PREDATOR_H
