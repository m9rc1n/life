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
#include "StatisticsSumVisitor.hpp"
#include "StatisticsAverageVisitor.hpp"

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

        void toPopCre(int to);
        void toPopHer(int to);
        void toPopPre(int to);
        void toPopTot(int to);
        void toPopSle(int to);
        void toPopCop(int to);

        void toAvePreAng(double to);
        void toAvePreSpe(double to);
        void toAvePreEne(double to);
        void toAvePreFec(double to);
        void toAvePreRad(double to);
        void toAvePreHyd(double to);
        void toAvePreRep(double to);
        void toAvePreAge(double to);
        void toMaxPreAge(double to);
        void toMaxPreEne(double to);
        void toMaxPreRep(double to);
        void toMaxPreHyd(double to);
        void toDiePreAge(double to);

        void toAveHerAng(double to);
        void toAveHerSpe(double to);
        void toAveHerEne(double to);
        void toAveHerFec(double to);
        void toAveHerRad(double to);
        void toAveHerHyd(double to);
        void toAveHerRep(double to);
        void toAveHerAge(double to);
        void toMaxHerAge(double to);
        void toMaxHerEne(double to);
        void toMaxHerRep(double to);
        void toMaxHerHyd(double to);
        void toDieHerAge(double to);

    protected:
        void run();

    private:
        common::Config  *config;
    };
}

