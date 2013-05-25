#ifndef COMMON_CREATURE_H
#define COMMON_CREATURE_H

#include "MapObject.hpp"


namespace common
{

    /**
    * @brief
    * Abstrakcyjna klasa reprezentująca stworzenie
    */
    class Creature: public MapObject
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
        * @param api draw using specific api
        * @todo potrzebujesz fathera?
        */
        Creature(const Creature &mother, DrawingAPI &api_p/*const Creature &father*/):
            MapObject(mother, api_p),
            radius_(0),
            angle_(0),
            speed_(0),
            fecundity_(0),
            max_repletion_(0),
            max_hydration_(0),
            max_energy_(0),
            max_age_(0)
        {
            /// @todo write me
        }

        /**
        * @brief
        * Konstruktor wywoływany w przypadku, gdy stworzenie jest generowane na początku gry.
        * Wspolrzedne stworzenia są podawane jako parametry konstruktora.
        *
        * Stworzenie pojawi się w wybranym miejscu na planszy (powinno ono byc wolne).
        */
        Creature(double x_pos, double y_pos, DrawingAPI &api_p):
            MapObject(x_pos, y_pos, api_p),
            radius_(0),
            angle_(0),
            speed_(0),
            fecundity_(0),
            max_repletion_(0),
            max_hydration_(0),
            max_energy_(0),
            max_age_(0)
        {
            /// @todo write me
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
        * Funkcja podaje informację czy stworzenie jest martwe.
        *
        * Dzieje się tak, gdy najedzenie, napojenie lub energia spadnie do zera
        * lub gdy stworzenie osiągnie swój maksymalny wiek.
        *
        * Po stwierdzeniu, że stworzenie jest martwe, funkcja wołająca powinna zniszczyć
        * obiekt klasy Creature.
        *
        * @returns true wtedy i tylko wtedy gdy osobnik jest martwy.
        */
        bool isDead() const
        {
            return is_dead_;
        }

        /**
         * @brief
         * Przyjecie (acceptance) wizytatora.
         */
        virtual void accept(Visitor &) = 0;

        /**
         * @brief
         * Draw MapObject
         */
        virtual void draw() = 0;

        /**
        * @brief
        * Serializacja
        *
        * Serializuje skladowe obiektu oraz klase bazowa.
        *
        * @see Map::serialize
        */
        template<class Archive>
        void serialize(Archive & ar, const unsigned int version)
        {
            ar & boost::serialization::base_object<MapObject>(*this);
    //         ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP(MapObject);
            ar & radius_;
            ar & angle_;
            ar & speed_;
            ar & fecundity_;
            ar & max_repletion_;
            ar & max_hydration_;
            ar & max_energy_;
            ar & max_age_;
            ar & repletion_;
            ar & hydration_;
            ar & energy_;
            ar & age_;
        }

    protected:
        /// Zasięg widzenia
        const int radius_;

        /// Kąt widzenia
        const int angle_;

        /// Prędkość poruszania się
        const int speed_;

        /// Płodność
        const int fecundity_;

        /// Maksymalny poziom najedzenia (inaczej: odporność na głód)
        const int max_repletion_;

        /// Maksymalny poziom napojenia (inaczej: odporność na pragnienie)
        const int max_hydration_;

        /// Maksymalny poziom energii (inaczej: odporność na zmęczenie)
        const int max_energy_;

        /// Maksymalna długość życia
        const int max_age_;

        /// Obecny poziom najedzenia
        double repletion_;

        /// Obecny poziom napojenia
        double hydration_;

        /// Obecny poziom energii
        double energy_;

        /// Obecny wiek
        double age_;

        /// Czy zwierzę jest martwe?
        bool is_dead_;

    };
}

BOOST_SERIALIZATION_ASSUME_ABSTRACT(Creature);

#endif
