#ifndef COMMON_CONFIG_H
#define COMMON_CONFIG_H

#include <vector>

#include <QMutex>
#include <QWaitCondition>

namespace common
{
    class Map;
    class MaslovPyramid;
    class GeneticEquation;

    /**
    * @brief
    * Klasa przechowujaca komplet ustawien wybranych przez uzytkownika na ekranie
    * startowym.
    *
    * Singleton.
    *
    * @todo hermetyzacja!!!
    */
    class Config
    {

    private:
        // singleton
        Config():
            map_width(100),
            map_height(50),
            map(NULL),
            objectsCounter(0)
        {
        }
        Config(Config &);

        /// liczba obiektów utworzonych na planszy (nie dekrementujemy przy kasowaniu obiektów)
        /// ten sam obiekt znajdujący się w kilku kopiach mapy liczony jest raz (nie inkrementujemy przy kopiowaniu)
        int objectsCounter;

    public:
        int     map_width;
        int     map_height;

        int     amount_predators;
        int     amount_herbivores;
        int     amount_trees;
        int     amount_waterholes;
        int     amount_lairs;

        MaslovPyramid   *predators_pyramid;
        MaslovPyramid   *herbivores_pyramid;

        //std::vector <GeneticEquation> equations;

        QMutex           mutex;
        QWaitCondition   condition;

        common::Map      *map;

        static Config *getInstance()
        {
            static Config instance;
            return &instance;
        }

        /**
         * @brief Zwiększa licznik obiektów na mapie
         *
         * Wołać w dwóch przypadkach: 1) kreacja obiektów na początkiu gry 2) rozmnażanie zwierząt i tworzenie potomka
         */
        void increaseObjectsCounter()
        {
            objectsCounter++;
        }

        /**
         *@return wartość licznika obiektów na mapie
         */
        int getObjectsCounter() const
        {
            return objectsCounter;
        }

        /// @todo różne scenariusze?
        /// np. kiedy dwa różne są w tym samym miejscu to walczą, jak takie same to kopulują
        /// np. pora sucha i pora deszczowa
        /// czy wolisz jeden bardziej spójny i złożony?
    };
}

#endif
