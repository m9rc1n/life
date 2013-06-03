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

    QImage image(QSize(config->getMapWidth()*10+10, config->getMapHeight()*10+10), QImage::Format_RGB32);

    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    for(int i = 0;; ++i) // nieskonczona petla
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

        config->mutex.lock();
            localMap = new common::Map(*(config->map));
            showCreaturesParametres = config->getShowCreaturesParametres();
        config->mutex.unlock();

        client::PaintingVisitor painter(&image, showCreaturesParametres);
        client::StatisticsSumVisitor staterSum(Statistics::getInstance());
        client::StatisticsAverageVisitor staterAve(Statistics::getInstance());
        localMap->accept(painter);
        localMap->accept(staterSum);
        localMap->accept(staterAve);

        emit renderedImage(image);

        int popHer = Statistics::getInstance()->populationHerbivores;
        int popPre = Statistics::getInstance()->populationPredators;
        int popCre = popHer + popPre;

        emit toPopCre(popCre);
        emit toPopHer(popHer);
        emit toPopPre(popPre);
        emit toPopTot(config->getObjectsCounter());
        emit toPopSle(Statistics::getInstance()->populationSleeping);
        emit toPopCop(Statistics::getInstance()->populationProcreating);

        emit toAvePreAng(Statistics::getInstance()->averageAnglePredators/popPre);
        emit toAvePreSpe(Statistics::getInstance()->averageSpeedPredators/popPre);
        emit toAvePreEne(Statistics::getInstance()->averageEnergyPredators/popPre);
        emit toAvePreFec(Statistics::getInstance()->averageFecundityPredators/popPre);
        emit toAvePreRad(Statistics::getInstance()->averageRadiusPredators/popPre);
        emit toAvePreHyd(Statistics::getInstance()->averageHydrationPredators/popPre);
        emit toAvePreRep(Statistics::getInstance()->averageRepletionPredators/popPre);
        emit toAvePreAge(Statistics::getInstance()->averageAgePredators/popPre);
        emit toMaxPreAge(Statistics::getInstance()->averageMaxAgePredators/popPre);
        emit toMaxPreEne(Statistics::getInstance()->averageMaxEnergyPredators/popPre);
        emit toMaxPreRep(Statistics::getInstance()->averageMaxRepletionPredators/popPre);
        emit toMaxPreHyd(Statistics::getInstance()->averageMaxHydrationPredators/popPre);
        emit toDiePreAge(Statistics::getInstance()->averageDieAgePredators/Statistics::getInstance()->deadPredators);

        emit toAveHerAng(Statistics::getInstance()->averageAngleHerbivores/popHer);
        emit toAveHerSpe(Statistics::getInstance()->averageSpeedHerbivores/popHer);
        emit toAveHerEne(Statistics::getInstance()->averageEnergyHerbivores/popHer);
        emit toAveHerFec(Statistics::getInstance()->averageFecundityHerbivores/popHer);
        emit toAveHerRad(Statistics::getInstance()->averageRadiusHerbivores/popHer);
        emit toAveHerHyd(Statistics::getInstance()->averageHydrationHerbivores/popHer);
        emit toAveHerRep(Statistics::getInstance()->averageRepletionHerbivores/popHer);
        emit toAveHerAge(Statistics::getInstance()->averageAgeHerbivores/popHer);
        emit toMaxHerAge(Statistics::getInstance()->averageMaxAgeHerbivores/popHer);
        emit toMaxHerEne(Statistics::getInstance()->averageMaxEnergyHerbivores/popHer);
        emit toMaxHerRep(Statistics::getInstance()->averageMaxRepletionHerbivores/popHer);
        emit toMaxHerHyd(Statistics::getInstance()->averageMaxHydrationHerbivores/popHer);
        emit toDieHerAge(Statistics::getInstance()->averageDieAgeHerbivores/Statistics::getInstance()->deadHerbivores);

        delete localMap; // mozna zmienic na sprytny wskaznik
    }
}
