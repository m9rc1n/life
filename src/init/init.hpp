 
#ifndef INIT_INIT_HPP
#define INIT_INIT_HPP 

#include "../include.hpp"
#include <QApplication>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QGraphicsView>
 
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
    int run(common::Config *config, int argc, char **argv);
}

#endif
