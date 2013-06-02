#include <iostream>
#include <mutex>
#include <thread> // c++11
#include <chrono> // c++11
#include <vector>

#include <QSize>
#include <QThread>
#include <QImage>

#include "../common/Map.hpp"
#include "../common/Config.hpp"
#include "PaintingVisitor.hpp"
#include "StatisticsVisitor.hpp"

namespace client
{

    class Client : public QThread
    {
        Q_OBJECT

    public:
        Client(common::Config *config, QObject *parent = 0);
        ~Client();
        void render(double centerX, double centerY, double scaleFactor, QSize resultSize);

    signals:
        void renderedImage(const QImage &image, double scaleFactor);

    protected:
        void run();

        int run(std::mutex *mutex, common::Map *map);

    private:
        common::Config  *config;
        double          centerX;
        double          centerY;
        double          scaleFactor;
        QSize           resultSize;
    };
}

