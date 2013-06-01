#include "server.hpp" 
#include <QWidget>

server::Server::Server(common::Config *config, QObject *parent)
    : QThread(parent),
      config(config)
{}


void server::Server::run()
{
    common::Map *localMap = new common::Map(config->map_height, config->map_width); // generujemy mape na podstawie config

    for(int i = 0;; ++i) // nieskonczona petla
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1200));

        std::cout << "Jestem serwerem!\n" << std::endl;

        // aktualizacja mapy za pomoca wizytatorow
        /// @todo Michał czemu visitor jest w pętli? musi być?
        SimulationVisitor visitor;
        localMap->accept(visitor);

        config->mutex.lock();
        {
            *(config->map) = *localMap;
        }
        config->mutex.unlock();
    }
}


