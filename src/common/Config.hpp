#ifndef COMMON_CONFIG_H
#define COMMON_CONFIG_H

namespace common
{
    /**
    * @brief
    * Klasa przechowujaca komplet ustawien wybranych przez uzytkownika na ekranie
    * startowym.
    * 
    * @todo moze zrobmy z tego singleton?
    * @michał tak zdecydowanie pasuje tu singleton
    */
    struct Config
    {
        int map_width;
        int map_height;
        int amount_predators;
        int amount_herbivores;
        int amount_trees;
        int amount_waterholes;
        int amount_lairs;

        /// @todo różne scenariusze?
        /// np. kiedy dwa różne są w tym samym miejscu to walczą, jak takie same to kopulują
        /// np. pora sucha i pora deszczowa
        /// czy wolisz jeden bardziej spójny i złożony?
    };
}

#endif
