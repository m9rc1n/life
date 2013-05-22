#include "../common/Map.hpp"
#include "../common/MapObject.hpp"
#include "../common/Creature.hpp"
#include "../common/Herbivore.hpp"
#include "../common/Predator.hpp"
#include "../common/Config.hpp"

#include <iostream>
#include <mutex>
#include <thread> // c++11
#include <chrono> // c++11

namespace client
{
    int main(std::mutex *mutex, Map *map, Config *config);
};