#include "server.hpp" 


void server::run(std::mutex *mutex, common::Map *map, common::Config *config)
{
    std::cout << "Jestem serwerem!\n" << std::endl;
    
    common::Map *localMap = new common::Map(config->map_height, config->map_width); // generujemy mape na podstawie config

    for(int i = 0;; ++i) // nieskonczona petla
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1200));
        
        // aktualizacja mapy za pomoca wizytatorow
        SimulationVisitor visitor;
        localMap->accept(visitor);
        
        mutex->lock();
        {
            *map = *localMap;
        }
        mutex->unlock();
        
    }
}
