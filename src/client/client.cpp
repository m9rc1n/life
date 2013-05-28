#include "client.hpp" 
 
int client::run(std::mutex *mutex, common::Map *map, common::Config *config, int argc, char **argv)
{
    std::cout << "Jestem klientem!\n" << std::endl;
    
    common::Map* localMap;

    for(int i = 0;; ++i) // nieskonczona petla
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(820));
        
        mutex->lock();
        {
            // czytamy mape, robimy lokalna kopie
            localMap = new common::Map(*map);
        }
        mutex->unlock();
        
        // robimy cos z mapa: wyswietlamy, aktualizujemy statystyki
        // za pomoca wizytatorow, np. jesli mamy wizytatoror Stat
        // to robimy Stat.visit(*localMap);
        
        delete localMap; // mozna zmienic na sprytny wskaznik
    }
}
