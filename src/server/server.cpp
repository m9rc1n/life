#include "server.hpp" 
#include <QWidget>

server::Server::Server(QObject *parent)
    : QThread(parent)
{}


void server::Server::run()
{
    common::Map *localMap = new common::Map(common::Config::getInstance()->map_width,
                                            common::Config::getInstance()->map_height); // generujemy mape na podstawie config

    common::Config::getInstance()->map = new common::Map();

    MapGenerator::generateMap(localMap);

    std::chrono::steady_clock::time_point current, previous;

    for(int i = 0;; ++i) // nieskonczona petla
    {
        previous = current;
        current = std::chrono::steady_clock::now();
        
        // aktualizacja mapy za pomoca wizytatorow
        //double time = std::chrono::duration_cast<std::chrono::duration<double>>(current - previous);

        /// @todo Michał czemu visitor jest w pętli? musi być?
        /// tak, w wizytatorze robię właściwie całą symulację

        SimulationVisitor visitor(150);
        localMap->accept(visitor);

        common::Config::getInstance()->mutex.lock();
        {
            *(common::Config::getInstance()->map) = *localMap;
        }
        common::Config::getInstance()->mutex.unlock();

        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}


