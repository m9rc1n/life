#include "server.hpp" 
#include "../common/MaslovPyramid.hpp"
#include <ctime>
#include <cstdlib>

server::Server::Server(QObject *parent)
    : QThread(parent)
{}

common::Map *server::Server::localMap;

void server::Server::run()
{
    srand(time(NULL));

    localMap = new common::Map(common::Config::getInstance()->getMapWidth(),
                                            common::Config::getInstance()->getMapHeight()); // generujemy mape na podstawie config

    common::Config::getInstance()->map = new common::Map();

    common::Config::getInstance()->predators_pyramid = new common::MaslovPyramid(1,2,3,4,5);
    common::Config::getInstance()->herbivores_pyramid = new common::MaslovPyramid(1,2,3,4,5);

    MapGenerator::generateMap(localMap);

    std::chrono::steady_clock::time_point current = std::chrono::steady_clock::now(), previous;

    for(int i = 0;
        common::Config::getInstance()->isGameStopped() == 0;
        ++i) // głowna pętla serwera
    {
        previous = current;
        current = std::chrono::steady_clock::now();
        
        // aktualizacja mapy za pomoca wizytatorow
        std::chrono::milliseconds time = std::chrono::duration_cast<std::chrono::milliseconds>(current - previous);

        double speed = common::Config::getInstance()->getSimulationSpeed();

        SimulationVisitor visitor(speed * time.count());
        localMap->accept(visitor);

        common::Config::getInstance()->mutex.lock();
        {
            *(common::Config::getInstance()->map) = *localMap;
        }
        common::Config::getInstance()->mutex.unlock();

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    delete localMap;
    delete common::Config::getInstance()->map;
    return;
}


