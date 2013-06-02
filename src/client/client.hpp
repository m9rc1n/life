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
    signals:
        void renderedImage(const QImage &image);
        void toPopPre(int update);
        void toPopHer(int update);
        void toPopCre(int update);

    protected:
        void run();

        int run(std::mutex *mutex, common::Map *map);

    private:
        common::Config  *config;
    };
}

