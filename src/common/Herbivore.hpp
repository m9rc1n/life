#ifndef COMMON_HERBIVORE_H
#define COMMON_HERBIVORE_H

#include "Creature.hpp"


namespace common
{
    /**
    * @brief
    * Abstrakcyjna klasa reprezentujaca roslinozerce
    *
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
        Herbivore(double x_pos, double y_pos, DrawingAPI& api):
            Creature(x_pos, y_pos, api)
        {} // kod w klasie Creature


        /**
         * @brief
         * Tworzy głęboką kopię obiektu
         *
         * @returns wskaznik do nowego obiektu (utworzonego przez new)
         *
         * @todo moze zmienic na sprytny wskaznik?
         * @todo kontruktor kopiujacy?
         */
        virtual MapObject *clone()
        {
            return new Herbivore(*this);
        }

        /**
         * @brief
         * Przyjecie (acceptance) wizytatora.
         */
        virtual void accept(Visitor &visitor);

        /**
         * @brief
         * Draw Herbivore
         */
        virtual void draw();

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
};

#endif
