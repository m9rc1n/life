#include "server.hpp" 
#include <QWidget>

server::Server::Server(common::Config *config, QObject *parent)
    : QThread(parent),
      config(config)
{}


void server::Server::run()
{
    common::Map *localMap = new common::Map(common::Config::getInstance()->map->getWidth(),
                                            common::Config::getInstance()->map->getHeight()); // generujemy mape na podstawie config

    std::chrono::steady_clock::time_point current, previous;

    for(int i = 0;; ++i) // nieskonczona petla
    {
        previous = current;
        current = std::chrono::steady_clock::now();
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        
        // aktualizacja mapy za pomoca wizytatorow
        //double time = std::chrono::duration_cast<std::chrono::duration<double>>(current - previous);

        /// @todo Michał czemu visitor jest w pętli? musi być?
        /// tak, w wizytatorze robię właściwie całą symulację

        SimulationVisitor visitor(150);
        localMap->accept(visitor);

        config->mutex.lock();
        {
            *(config->map) = *localMap;
        }
        config->mutex.unlock();
    }
}


