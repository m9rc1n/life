

#include <mutex> // c++11
#include <iostream>
#include <thread> // c++11
#include <chrono> // c++11

#include "../include.hpp"

namespace server
{
    void run(std::mutex *mutex, common::Map *map, common::Config *config);
};