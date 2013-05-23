 
#include <thread> // c++11
#include <mutex>  // c++11
 
#include "include.hpp"

int main()
{
    common::Config *config = new common::Config(); // komplet konfiguracji
    
    init::run(config); // nie musimy wolac tego jako osobnego watku
    
    common::Map *map = new common::Map(config->map_width, config->map_height); // ta struktura zawiera wszystkie dane gry
    
    std::mutex *mutex = new std::mutex; // mutex do synchronizacji
        
    std::thread client_thread(bind(client::run, mutex, map, config));
    std::thread server_thread(bind(server::run, mutex, map, config));
    
    client_thread.join();
    server_thread.join();
    
    delete map;
    delete mutex;
    delete config;
    
    return 0;
}
