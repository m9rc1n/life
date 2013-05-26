
#include <thread> // c++11
#include <mutex>  // c++11
/**
 * QT
 * nie wiem do konca jak zainicjowac qt zeby bylo ok razem z mostem
 * ale wydaje mi sie ze tak bedzie na poczatek ok
 */
 
#include "include.hpp"

int main(int argc, char **argv)
{

    common::Config *config = new common::Config(); // komplet konfiguracji
    
    init::run(config, argc, argv); // nie musimy wolac tego jako osobnego watku
    
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
