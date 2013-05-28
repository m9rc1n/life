

#include "../include.hpp"

using namespace init;
// using namespace Ui;

int init::run(common::Config *config, int argc, char **argv)
{
    config->map_width = 4;
    config->map_height = 5;
/*
    QApplication app(argc, argv);

    QGraphicsScene scene;
    scene.setSceneRect( -100.0, -100.0, 200.0, 200.0 );

    QGraphicsEllipseItem *item = new QGraphicsEllipseItem( 0, &scene );
    item->setRect( -50.0, -50.0, 100.0, 100.0 );

    QGraphicsView view( &scene );
    view.setRenderHints( QPainter::Antialiasing );
    view.show();
*/

    QApplication a(argc, argv);
    Init_UI w;
    w.show();

    return a.exec();
    // return app.exec();
}
