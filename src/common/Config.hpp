#ifndef COMMON_CONFIG_H
#define COMMON_CONFIG_H

#include <vector>
#include <QMutex>
#include <QWaitCondition>

namespace common
{
    class Map;
    class MaslovPyramid;
    class GeneticEquation;

    /**
    * @brief
    * Klasa przechowujaca komplet ustawien wybranych przez uzytkownika na ekranie
    * startowym.
    *
    * Singleton.
    *
    * @todo hermetyzacja!!!
    */
    class Config
    {

    private:
        // singleton
        Config():
            map_width(100),
            map_height(100),
            map(NULL),
            objectsCounter(0),
            parameter_sum(200),
            simulation_speed(1),
            show_creatures_parametres(false),
            stop(0)
        {}
        Config(Config &);

        /// liczba obiektów utworzonych na planszy (nie dekrementujemy przy kasowaniu obiektów)
        /// ten sam obiekt znajdujący się w kilku kopiach mapy liczony jest raz (nie inkrementujemy przy kopiowaniu)
        int             objectsCounter;

        // parametry rozgrywki, chyba nie trzeba opisywac po kolei
        int             map_width;
        int             map_height;
        int             number_of_predators;
        int             number_of_herbivores;
        int             number_of_trees;
        int             number_of_waterholes;
        int             number_of_lairs;

        /// do jakiej wartosci normalizowac cechy osobnikow?
        int             parameter_sum;

        /// szybkosz symulacji, mnoznik
        int             simulation_speed;

        /// czy pokazywać dodatkowe paski?
        bool            show_creatures_parametres;

        /// polecenie zatrzymania gry, głównie do testowania
        bool stop;

    public:
        common::Map     *map;
        MaslovPyramid   *predators_pyramid;
        MaslovPyramid   *herbivores_pyramid;
        //std::vector <GeneticEquation> equations;
        QMutex          mutex;
        QWaitCondition  condition;


        /// getter dla pola #stop
        bool isGameStopped() const
        {
            return stop;
        }

        static Config *getInstance()
        {
            static Config instance;
            return &instance;
        }

        /**
         * @brief Zwiększa licznik obiektów na mapie
         *
         * Wołać w dwóch przypadkach: 1) kreacja obiektów na początkiu gry 2) rozmnażanie zwierząt i tworzenie potomka
         */
        void increaseObjectsCounter()
        {
            objectsCounter++;
        }

        /**
         *@return wartość licznika obiektów na mapie
         */
        int getObjectsCounter() const
        {
            return objectsCounter;
        }

        /**
         * @brief getMapWidth
         * @return szerokość mapy
         */
        int getMapWidth() const
        {
            return map_width;
        }

        /**
         * @brief setMapWidth
         * @param map_width : nowa szerokość mapy
         */
        void setMapWidth (int map_width)
        {
            this->map_width = map_width;
        }

        /**
         * @brief getMapHeight
         * @return wysokość mapy
         */
        int getMapHeight() const
        {
            return map_height;
        }

        /**
         * @brief setMapHeight
         * @param map_width : nowa wysokość mapy
         */
        void setMapHeight (int map_height)
        {
            this->map_height = map_height;
        }

        bool getShowCreaturesParametres()
        {
            return show_creatures_parametres;
        }

        void setShowCreaturesParametres(bool show_creatures_parametres)
        {
            this->show_creatures_parametres = show_creatures_parametres;
        }

        int getNumberOfPredators()
        {
            return number_of_predators;
        }

        int getNumberOfHerbivores()
        {
            return number_of_herbivores;
        }

        int getNumberOfTrees()
        {
            return number_of_trees;
        }

        int getNumberOfWaterholes()
        {
            return number_of_waterholes;
        }

        int getNumberOfLairs()
        {
            return number_of_lairs;
        }

        void setNumberOfPredators(int number)
        {
            this->number_of_predators = number;
        }

        void setNumberOfHerbivores(int number)
        {
            this->number_of_herbivores = number;
        }

        void setNumberOfTrees(int number)
        {
            this->number_of_trees = number;
        }

        void setNumberOfLairs(int number)
        {
            this->number_of_lairs = number;
        }

        void setNumberOfWaterholes(int number)
        {
            this->number_of_waterholes = number;
        }

        int getParameterSum()
        {
            return parameter_sum;
        }

        void setParameterSum(int sum)
        {
            parameter_sum = sum;
        }

        MaslovPyramid* getPredatorsPyramid()
        {
            return predators_pyramid;
        }

        MaslovPyramid* getHerbivoresPyramid()
        {
            return herbivores_pyramid;
        }

        /**
         * @brief setPredatorsPyramid
         * @param pyramid
         * @todo zadziała??
         */
        void setPredatorsPyramid(MaslovPyramid *pyramid)
        {
            this->predators_pyramid = pyramid;
        }

        void setHerbivoresPyramid(MaslovPyramid *pyramid)
        {
            this->herbivores_pyramid = pyramid;
        }

/*        QMutex getMutex()
        {
            return mutex;
        }

        QWaitCondition getCondition()
        {
            return condition;
        }
*/
        common::Map* getMap()
        {
            return map;
        }

        void setMap(common::Map* map)
        {
            this->map = map;
        }

        int getSimulationSpeed()
        {
            return simulation_speed;
        }

        void setSimulationSpeed(int speed)
        {
            simulation_speed = speed;
        }

    };
}

#endif
