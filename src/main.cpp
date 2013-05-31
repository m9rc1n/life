#include "common/Config.hpp"
#include "init/init_ui.hpp"
#include "client/client_ui.hpp"
#include "init/init.hpp"

#include <QApplication>

int main(int argc, char **argv)
{

    QApplication app(argc, argv);

    Client_UI *client_ui = new Client_UI(common::Config::getInstance());
    Init_UI *init_ui = new Init_UI(common::Config::getInstance(), client_ui);

    init::run(init_ui); // nie musimy wolac tego jako osobnego watku

    return app.exec();
}
