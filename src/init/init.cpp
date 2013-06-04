#include <thread> // c++11
#include <mutex>  // c++11
#include "init.hpp"

int init::run(Init_UI *init_ui)
{
    init_ui->show();
}

int init::startGame()
{
    Client_UI *client_ui = new Client_UI(common::Config::getInstance());
    client_ui->show();

    server::Server* server_thread = new server::Server();
    server_thread->start();
}
