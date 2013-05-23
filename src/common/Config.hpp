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
    */
    struct Config
    {
        int map_width;
        int map_height;
    };
};

#endif