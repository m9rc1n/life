#ifndef COMMON_HERBIVORE_H
#define COMMON_HERBIVORE_H

#include "Creature.hpp"
#include <typeinfo>

namespace common
{
    /**
    * @brief
    * Klasa reprezentujaca roslinozerce
    *
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
        Herbivore(double x_pos, double y_pos, double direction,
                  int radius, int angle, int speed,
                  int max_repletion, int max_hydration, int max_energy,
                  int fecundity, int max_age, bool is_male):
            Creature(x_pos, y_pos, direction, radius, angle, speed, max_repletion, max_hydration, max_energy, fecundity, max_age, is_male)
        {} // kod w klasie Creature

        /**
         * @brief Podaje piramidę potrzeb zwierzęcia.
         *
         * W przyszłości być moze będzie podawać indywidualną piramidę; póki co jest ona globalna.
         */
        MaslovPyramid *getMaslovPyramid()
        {
            return Config::getInstance()->herbivores_pyramid;
        }

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
            return static_cast<MapObject*>(new Herbivore(*this));
        }

        /**
         * @brief
         * Przyjecie (acceptance) wizytatora.
         */
        virtual void accept(Visitor &visitor)
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

#endif
