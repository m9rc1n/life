#include "MapGenerator.hpp"


void MapGenerator::generateMap(common::Map *map)
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
