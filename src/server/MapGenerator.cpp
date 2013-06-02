#include "MapGenerator.hpp"

 double MapGenerator::x_pos;
 double MapGenerator::y_pos;
 double MapGenerator::direction;

 int MapGenerator::radius;
 int MapGenerator::angle;
 int MapGenerator::speed;
 int MapGenerator::max_repletion;
 int MapGenerator::max_hydration;
 int MapGenerator::max_energy;
 int MapGenerator::fecundity;
 int MapGenerator::max_age;

void MapGenerator::getParameters()
{
    x_pos = getRandomX();
    y_pos = getRandomY();

    direction = getRandomDirection();

    radius          = getRandomCreatureParameter();
    angle           = getRandomCreatureParameter();
    speed           = getRandomCreatureParameter();
    max_repletion   = getRandomCreatureParameter();
    max_hydration   = getRandomCreatureParameter();
    max_energy      = getRandomCreatureParameter();
    fecundity       = getRandomCreatureParameter();
    max_age         = getRandomCreatureParameter();

    double sum = radius + angle + speed + max_hydration + max_repletion + max_energy + fecundity + max_age;

    radius          = round(common::Config::getInstance()->parameter_sum * radius          /sum);
    angle           = round(common::Config::getInstance()->parameter_sum * angle           /sum);
    speed           = round(common::Config::getInstance()->parameter_sum * speed           /sum);
    max_repletion   = round(common::Config::getInstance()->parameter_sum * max_repletion   /sum);
    max_hydration   = round(common::Config::getInstance()->parameter_sum * max_hydration   /sum);
    max_energy      = round(common::Config::getInstance()->parameter_sum * max_energy      /sum);
    fecundity       = round(common::Config::getInstance()->parameter_sum * max_energy      /sum);
    max_age         = round(common::Config::getInstance()->parameter_sum * max_age         /sum);
}

void MapGenerator::generateMap(common::Map *map)
{

    int amount_herbivores = common::Config::getInstance()->amount_herbivores;
    int amount_predators = common::Config::getInstance()->amount_predators;
    int amount_lairs = common::Config::getInstance()->amount_lairs;
    int amount_trees= common::Config::getInstance()->amount_trees;
    int amount_waterholes = common::Config::getInstance()->amount_waterholes;

    for(int i=0; i < amount_herbivores; ++i)
    {
        getParameters();

        common::Herbivore *h = new common::Herbivore(x_pos, y_pos, direction, radius, angle, speed,
                                   max_repletion, max_hydration, max_energy, fecundity, max_age);
        map->appendObject(h);
    }

    for(int i=0; i < amount_predators; ++i)
    {
        getParameters();

        common::Predator *p = new common::Predator(x_pos, y_pos, direction, radius, angle, speed,
                                  max_repletion, max_hydration, max_energy, fecundity, max_age);
        map->appendObject(p);
    }

    for(int i=0; i < amount_lairs; ++i)
    {
        common::Lair *l = new common::Lair(getRandomX(), getRandomY());
        map->appendObject(l);
    }

    for(int i=0; i < amount_trees; ++i)
    {
        common::Tree *t = new common::Tree(getRandomX(), getRandomY());
        map->appendObject(t);
    }

    for(int i=0; i < amount_waterholes; ++i)
    {
        common::Waterhole *w = new common::Waterhole(getRandomX(), getRandomY());
        map->appendObject(w);
    }
}
