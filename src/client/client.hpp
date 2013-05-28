
#include <iostream>
#include <mutex>
#include <thread> // c++11
#include <chrono> // c++11

#include "../include.hpp"
#include <QApplication>

namespace client
{
    int run(std::mutex *mutex, common::Map *map);
    // tutaj deklaracje jakichs klas uzytych w kliencie, np.
    // class GameWindow;
}
