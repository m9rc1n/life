#include "common/Config.hpp"
#include "init/init_ui.hpp"
#include "init/init.hpp"

#include <QApplication>

int main(int argc, char **argv)
{

    QApplication app(argc, argv);

    Init_UI *init_ui = new Init_UI(common::Config::getInstance());
    init::run(init_ui);

    return app.exec();
}
