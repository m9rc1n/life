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
    static void generateMap(common::Map *map)
    {

        int amount_herbivores = common::Config::getInstance()->amount_herbivores;
        int amount_predators = common::Config::getInstance()->amount_predators;
        int amount_lairs = common::Config::getInstance()->amount_lairs;
        int amount_trees= common::Config::getInstance()->amount_trees;
        int amount_waterholes = common::Config::getInstance()->amount_waterholes;

        for(int i=0; i < amount_herbivores; ++i)
        {
            common::Herbivore *h = new common::Herbivore(getRandomDouble(map), getRandomDouble(map));
            map->appendObject(h);
        }

        for(int i=0; i < amount_predators; ++i)
        {
            common::Predator *p = new common::Predator(getRandomDouble(map), getRandomDouble(map));
            map->appendObject(p);
        }

        for(int i=0; i < amount_lairs; ++i)
        {
            common::Lair *l = new common::Lair(getRandomDouble(map), getRandomDouble(map));
            map->appendObject(l);
        }

        for(int i=0; i < amount_trees; ++i)
        {
            common::Tree *t = new common::Tree(getRandomDouble(map), getRandomDouble(map));
            map->appendObject(t);
        }

        for(int i=0; i < amount_waterholes; ++i)
        {
            common::Waterhole *w = new common::Waterhole(getRandomDouble(map), getRandomDouble(map));
            map->appendObject(w);
        }
    }
};

#endif // MAPGENERATOR_HPP
