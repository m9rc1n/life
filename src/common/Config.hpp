#ifndef COMMON_CONFIG_H
#define COMMON_CONFIG_H

#include <vector>

#include "MaslovPyramid.hpp"
#include "GeneticEquation.hpp"
#include "Map.hpp"

#include <QMutex>
#include <QWaitCondition>

namespace common
{
    /**
    * @brief
    * Klasa przechowujaca komplet ustawien wybranych przez uzytkownika na ekranie
    * startowym.
    *
    * Singleton.
    *
    */
    class Config
    {

    private:
        // singleton
        Config()
        {
            map = new common::Map(0,0);
        }
        Config(Config &);

    public:
        int     amount_predators;
        int     amount_herbivores;
        int     amount_trees;
        int     amount_waterholes;
        int     amount_lairs;

        MaslovPyramid   *predators_pyramid;
        MaslovPyramid   *herbivores_pyramid;

        std::vector <GeneticEquation> equations;

        QMutex           mutex;
        QWaitCondition   condition;

        common::Map      *map;

        static Config *getInstance()
        {
            static Config instance;
            return &instance;
        }

        /// @todo różne scenariusze?
        /// np. kiedy dwa różne są w tym samym miejscu to walczą, jak takie same to kopulują
        /// np. pora sucha i pora deszczowa
        /// czy wolisz jeden bardziej spójny i złożony?
    };
}

#endif
