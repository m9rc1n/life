#include "server.hpp" 



void server::run(std::mutex *mutex, common::Map *map, common::Config *config)
{
    std::cout << "Jestem serwerem!\n" << std::endl;
    
    
    for(int i = 0;; ++i) // nieskonczona petla
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1200));
        
        mutex->lock();
            map->createSomeRandomObjects();
            std::cout <<"serwer modyfikuje plansze, liczba obiektow: " << map->countObjects() << std::endl;
        mutex->unlock();
    }
}