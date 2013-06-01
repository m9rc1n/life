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

    static double getRandomX()
    {
        return getRandomDouble(common::Config::getInstance()->map->getWidth());
    }

    static double getRandomY()
    {
        return getRandomDouble(common::Config::getInstance()->map->getHeight());
    }

    static double getRandomDouble(int max)
    {
      time_t t = time(NULL);
      std::mt19937 seed((int)t);
      std::uniform_real_distribution<double> dist(0.0, (double)max);
      boost::variate_generator<std::mt19937&, std::uniform_real_distribution<> > random(seed,dist);
      return random();
    }

public:
    static void generateMap()
    {

        int amount_herbivores = common::Config::getInstance()->amount_herbivores;
        int amount_predators = common::Config::getInstance()->amount_predators;
        int amount_lairs = common::Config::getInstance()->amount_lairs;
        int amount_trees= common::Config::getInstance()->amount_trees;
        int amount_waterholes = common::Config::getInstance()->amount_waterholes;

        for(int i=0; i < amount_herbivores; ++i)
        {
            common::Herbivore *h = new common::Herbivore(getRandomX(), getRandomY());
            common::Config::getInstance()->map->appendObject(h);
        }

        for(int i=0; i < amount_predators; ++i)
        {
            common::Predator *p = new common::Predator(getRandomX(), getRandomY());
            common::Config::getInstance()->map->appendObject(p);
        }

        for(int i=0; i < amount_lairs; ++i)
        {
            common::Lair *l = new common::Lair(getRandomX(), getRandomY());
            common::Config::getInstance()->map->appendObject(l);
        }

        for(int i=0; i < amount_trees; ++i)
        {
            common::Tree *t = new common::Tree(getRandomX(), getRandomY());
            common::Config::getInstance()->map->appendObject(t);
        }

        for(int i=0; i < amount_waterholes; ++i)
        {
            common::Waterhole *w = new common::Waterhole(getRandomX(), getRandomY());
            common::Config::getInstance()->map->appendObject(w);
        }
    }
};

#endif // MAPGENERATOR_HPP
