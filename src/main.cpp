#include "include.hpp"
#include <QApplication>

int main(int argc, char **argv)
{

    common::Config *config = new common::Config(); // komplet konfiguracji

    QApplication app(argc, argv);

    Client_UI *client_ui = new Client_UI(config);
    Init_UI *init_ui = new Init_UI(config, client_ui);

    init::run(init_ui); // nie musimy wolac tego jako osobnego watku

    // delete config;
    return app.exec();
}
