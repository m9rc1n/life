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


class Client_UI : public QMainWindow
{
    Q_OBJECT

    public:

        Client_UI(common::Config *config, QMainWindow *parent = 0);
        ~Client_UI();

    protected:

        void paintEvent(QPaintEvent *event);
        void resizeEvent(QResizeEvent *event);
        void drawLabel();

    private slots:

        void updatePixmap(const QImage &image, double scaleFactor);
        void print();
        void zoomIn();
        void zoomOut();
        void normalSize();
        void fitToWindow();
        void about();

    private:

        void createActions();
        void createMenus();
        void updateActions();
        void scaleImage(double factor);
        void adjustScrollBar(QScrollBar *scrollBar, double factor);

        common::Config  *config;
        Ui::Client_UI   *ui;
        client::Client  *client_thread;
        QPixmap         *pixmap;
        QLabel          *imageLabel;
        QImage          *image;

        QAction         *printAct;
        QAction         *exitAct;
        QAction         *zoomInAct;
        QAction         *zoomOutAct;
        QAction         *normalSizeAct;
        QAction         *fitToWindowAct;
        QAction         *aboutAct;
        QAction         *aboutQtAct;
        double          scaleFactor;

        QMenu           *viewMenu;
        QMenu           *helpMenu;
};

#endif // CLIENT_UI_H
