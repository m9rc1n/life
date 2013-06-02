#include "client.hpp"
#include <math.h>
#include <QWidget>

client::Client::Client(common::Config *config, QObject *parent)
    : QThread(parent),
      config(config){}

client::Client::~Client(){}

void client::Client::run()
{
    common::Map* localMap;

    QImage image(QSize(config->map_width*10, config->map_height*10), QImage::Format_RGB32);

    for(int i = 0;; ++i) // nieskonczona petla
    {

        client::PaintingVisitor painter(&image);
        client::StatisticsVisitor stater(Statistics::getInstance());

        std::this_thread::sleep_for(std::chrono::milliseconds(250));

        config->mutex.lock();
            localMap = new common::Map(*(config->map));
        config->mutex.unlock();

        localMap->accept(painter);
        localMap->accept(stater);

        emit renderedImage(image);

        int popHer = Statistics::getInstance()->populationHerbivores;
        int popPre = Statistics::getInstance()->populationPredators;
        int popCre = popHer + popPre;

        emit toPopCre(popCre);
        emit toPopHer(popHer);
        emit toPopPre(popPre);

        delete localMap; // mozna zmienic na sprytny wskaznik
    }
}
