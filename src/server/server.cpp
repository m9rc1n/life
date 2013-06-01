#include "server.hpp" 


void server::run(std::mutex *mutex, common::Map *map, common::Config *config)
{
    std::cout << "Jestem serwerem!\n" << std::endl;
    
    common::Map *localMap = new common::Map(config->map_height, config->map_width); // generujemy mape na podstawie config

    std::chrono::steady_clock::time_point current, previous;

    for(int i = 0;; ++i) // nieskonczona petla
    {
        previous = current;
        current = std::chrono::steady_clock::now();
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        
        // aktualizacja mapy za pomoca wizytatorow
        //double time = std::chrono::duration_cast<std::chrono::duration<double>>(current - previous);
        SimulationVisitor visitor(150);
        localMap->accept(visitor);
        
        mutex->lock();
        {
            *map = *localMap;
        }
        mutex->unlock();
        
    }
}
