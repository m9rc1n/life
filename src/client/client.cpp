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
    bool showCreaturesParametres;

    QImage image(QSize(config->map_width*10+10, config->map_height*10+10), QImage::Format_RGB32);

    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    for(int i = 0;; ++i) // nieskonczona petla
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

        config->mutex.lock();
            localMap = new common::Map(*(config->map));
            showCreaturesParametres = config->show_creatures_parametres;
        config->mutex.unlock();

        client::PaintingVisitor painter(&image, showCreaturesParametres);
        client::StatisticsVisitor stater(Statistics::getInstance());
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
