#ifndef MAPGENERATOR_HPP
#define MAPGENERATOR_HPP

#include "../common/Config.hpp"
#include "../common/Map.hpp"
#include "../common/Tree.hpp"
#include "../common/Herbivore.hpp"
#include "../common/Predator.hpp"
#include "../common/Lair.hpp"
#include "../common/Waterhole.hpp"
#include "../common/MapObject.hpp"

#include <random>
#include <boost/random/variate_generator.hpp>

class MapGenerator
{
    MapGenerator() = delete;

    static double getRandomDouble(common::Map *map)
    {
        static int max = map->getWidth();
        static time_t t = time(NULL);
        static std::mt19937 seed((int)t);
        static std::uniform_real_distribution<double> dist(0.0, (double)max);
        static boost::variate_generator<std::mt19937&, std::uniform_real_distribution<> > random(seed,dist);
        return (random)();
    }

public:
    static void generateMap(common::Map *map);
};

#endif // MAPGENERATOR_HPP
