#ifndef CLIENT_UI_H
#define CLIENT_UI_H

#include <QWidget>
#include <QPixmap>
#include "client.hpp"
#include "../common/Config.hpp"


namespace Ui
{
    class Client_UI;
}


class Client_UI : public QWidget
{
    Q_OBJECT

    public:
        Client_UI(common::Config *config, QWidget *parent = 0);
        ~Client_UI();

    protected:
        void paintEvent(QPaintEvent *event);
        void resizeEvent(QResizeEvent *event);
        void keyPressEvent(QKeyEvent *event);

    private slots:
        void updatePixmap(const QImage &image, double scaleFactor);
        void zoom(double zoomFactor);

    private:
        void scroll(int deltaX, int deltaY);

        Ui::Client_UI   *ui;
        client::Client  *client_thread;
        common::Config  *config;
        QPixmap         pixmap;
        QPoint          pixmapOffset;
        QPoint          lastDragPos;
        double          centerX;
        double          centerY;
        double          pixmapScale;
        double          curScale;
};

#endif // CLIENT_UI_H
