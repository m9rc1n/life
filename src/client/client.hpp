
#include <iostream>
#include <mutex>
#include <thread> // c++11
#include <chrono> // c++11

#include "../include.hpp"

namespace client
{
    void run(std::mutex *mutex, common::Map *map, common::Config *config);
    // tutaj deklaracje jakichs klas uzytych w kliencie, np.
    // class GameWindow;
}
