#ifndef CLIENT_UI_H
#define CLIENT_UI_H

#include <QMainWindow>
#include <QPixmap>
#include "client.hpp"
#include "../common/Config.hpp"

#include <QPainter>
#include <cmath>
#include <QScrollArea>
#include <QAction>
#include <QLabel>
#include <QScrollBar>
#include <QMessageBox>
#include <QImage>
#include <QMenu>

namespace Ui
{
    class Client_UI;
}

/**
 * @brief The Client_UI class
 *  Creates the GUI for the game, display statistic and coordinates from
 *  objects on map
 *
 */
class Client_UI : public QMainWindow
{
    Q_OBJECT

    public:

        Client_UI(common::Config *config, QMainWindow *parent = 0);
        ~Client_UI();

    private slots:

        void updatePixmap(const QImage &image);
        void updatePopCre(int update);
        void updatePopHer(int update);
        void updatePopPre(int update);
        void updatePopTot();
        void updatePopSle(int update);
        void updatePopCop(int update);

        void updateAvePreAng(double update);
        void updateAvePreSpe(double update);
        void updateAvePreEne(double update);
        void updateAvePreFec(double update);
        void updateAvePreRad(double update);
        void updateAvePreHyd(double update);
        void updateAvePreRep(double update);
        void updateAvePreAge(double update);
        void updateMaxPreAge(double update);
        void updateMaxPreEne(double update);
        void updateMaxPreRep(double update);
        void updateMaxPreHyd(double update);
        void updateDiePreAge(double update);

        void updateAveHerAng(double update);
        void updateAveHerSpe(double update);
        void updateAveHerEne(double update);
        void updateAveHerFec(double update);
        void updateAveHerRad(double update);
        void updateAveHerHyd(double update);
        void updateAveHerRep(double update);
        void updateAveHerAge(double update);
        void updateMaxHerAge(double update);
        void updateMaxHerEne(double update);
        void updateMaxHerRep(double update);
        void updateMaxHerHyd(double update);
        void updateDieHerAge(double update);

        void zoomIn();
        void zoomOut();
        void normalSize();
        void about();
        void legend();
        void speedSimulationLow();
        void speedSimulationHigh();
        void speedSimulationMedium();
        void showParametres();

    private:

        void createActions();
        void createConnections();
        void createMenus();
        void scaleImage(double factor);
        void adjustScrollBar(QScrollBar *scrollBar, double factor);

        common::Config  *config;
        Ui::Client_UI   *ui;
        client::Client  *client_thread;
        QPixmap         *pixmap;
        QLabel          *imageLabel;
        QImage          *image;

        QAction         *exitAct;
        QAction         *zoomInAct;
        QAction         *zoomOutAct;
        QAction         *normalSizeAct;
        QAction         *aboutAct;
        QAction         *aboutQtAct;
        QAction         *simulationLAct;
        QAction         *simulationMAct;
        QAction         *simulationHAct;
        QAction         *legendAct;
        QAction         *showParametresAct;
        double          scaleFactor;

        QMenu           *viewMenu;
        QMenu           *helpMenu;
        QMenu           *fileMenu;

        enum simulation_speed
        {
            LOW = 1,
            MEDIUM = 2,
            HIGH = 4
        };
};

#endif // CLIENT_UI_H
