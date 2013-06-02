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

    /**
     * @brief zwraca losową liczbę rzeczywistą z zakresu (0, W), gdzie W jest szerokością planszy.
     */
    static double getRandomX()
    {
        static int max = common::Config::getInstance()->map_width;
        static time_t t = time(NULL);
        static std::mt19937 seed((int)t);
        static std::uniform_real_distribution<double> dist(0.0, (double)max);
        static boost::variate_generator<std::mt19937&, std::uniform_real_distribution<> > random(seed,dist);
        return (random)();
    }

    /**
     * @brief zwraca losową liczbę rzeczywistą z zakresu (0, H), gdzie H jest wysokością planszy.
     */
    static double getRandomY()
    {
        static int max = common::Config::getInstance()->map_height;
        static time_t t = time(NULL);
        static std::mt19937 seed((int)t + 37);
        static std::uniform_real_distribution<double> dist(0.0, (double)max);
        static boost::variate_generator<std::mt19937&, std::uniform_real_distribution<> > random(seed,dist);
        return (random)();
    }

    /**
     * @brief Losuje wartość która może być użyta jako parametr stworzenia przy generowaniu planszy
     * @return Losowa liczba z zakresu <10, 50)
     */
    static double getRandomCreatureParameter()
    {
        return rand()%40 + 10;
    }

    /**
     * @brief Losuje wartość która może być użyta jako kierunek patrzenia zwierzęnia
     * @return Losowa liczba z zakresu <0, 360)
     */
    static double getRandomDirection()
    {
        return rand()%360;
    }

    /**
     * @brief Generuje parametry stworzenia i normalizuje je, wynik zapisuje do zmiennych statychnych w klasie.
     */
    static void getParameters();

    static double x_pos;
    static double y_pos;

    static double direction;

    static int radius;
    static int angle;
    static int speed;
    static int max_repletion;
    static int max_hydration;
    static int max_energy;
    static int fecundity;
    static int max_age;

public:
    static void generateMap(common::Map *map);
};

#endif // MAPGENERATOR_HPP
