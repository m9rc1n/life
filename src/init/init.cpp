#include <thread> // c++11
#include <mutex>  // c++11
#include "../include.hpp"

using namespace Ui;

int init::run(Ui::Init_UI *init_ui)
{
    config->map_width = 4;
    config->map_height = 5;
    init_ui->show();
}

int init::startGame()
{
    // ta struktura zawiera wszystkie dane gry
    common::Map *map = new common::Map(config->map_width, config->map_height);

    // mutex do synchronizacji
    std::mutex *mutex = new std::mutex;

    std::thread client_thread(bind(client::run, mutex, map));
    std::thread server_thread(bind(server::run, mutex, map, config));

    client_thread.join();
    server_thread.join();

    /// @todo zakończenie gry!
    // delete map;
    // delete mutex;
}
