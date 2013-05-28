#ifndef INIT_INIT_HPP
#define INIT_INIT_HPP

#include "init_ui.hpp"

namespace init
{
    /**
     * @brief
     * Funkcja wyswietla okno, w ktorym uzytkownik moze dostosowac
     * parametry symulacji. 
     * 
     * Wynik jest zapisywany do obiektu wskazywanego przez 
     * wskaznik #config.
     * 
     * @todo write me
     */
    int run(Init_UI *init);

    /**
     * @brief startGame
     * Za pomocą tej funkcji rozpoczynamy nową grę z parametrami ustalonymi
     * przez gracza.
     * Przechodzimy do widoku clienta!
     *
     * @return
     */
    int startGame();
}

#endif
