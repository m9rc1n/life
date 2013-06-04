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
        Predator(double x_pos, double y_pos, double direction,
                 int radius, int angle, int speed,
                 int max_repletion, int max_hydration, int max_energy,
                 int fecundity, int max_age, bool is_male):
           Creature(x_pos, y_pos, direction, radius, angle, speed, max_repletion, max_hydration, max_energy, fecundity, max_age, is_male)
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
            return static_cast<MapObject*>(new Predator(*this));
        }

        virtual ~Predator()
        {}

        /**
         * @brief Prokreuje (działa tylko dla samic)
         */
        virtual void procreate()
        {
            if(not isDead() and not current_procreating_partner_->isDead() and !is_male_)
            {
                for(int i = 0; i < MAX_CHILDREN_FOR_PREDATORS; ++i)
                {
                    server::Genetics::makeChild(this, current_procreating_partner_);
                }
            }
        }

        /**
         * @brief Podaje piramidę potrzeb zwierzęcia.
         *
         * W przyszłości być moze będzie podawać indywidualną piramidę; póki co jest ona globalna.
         */
        MaslovPyramid *getMaslovPyramid()
        {
            return Config::getInstance()->predators_pyramid;
        }

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
