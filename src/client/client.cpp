#include "client.hpp"
#include <math.h>
#include <QWidget>

client::Client::Client(common::Config *config, QObject *parent)
    : QThread(parent),
      config(config){}

client::Client::~Client(){}

void client::Client::render(double centerX, double centerY, double scaleFactor,
                          QSize resultSize)
{
    QMutexLocker locker(&(config->mutex));

    this->centerX = centerX;
    this->centerY = centerY;
    this->scaleFactor = scaleFactor;
    this->resultSize = resultSize;

    if (!isRunning()) {
        start(LowPriority);
    } else {
        config->condition.wakeOne();
    }
}

void client::Client::run()
{
    common::Map* localMap;

    QImage image(QSize(config->map_width*10, config->map_height*10), QImage::Format_RGB32);
    client::PaintingVisitor painter(&image);
    client::StatisticsVisitor stater;

    for(int i = 0;; ++i) // nieskonczona petla
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        config->mutex.lock();
            localMap = new common::Map(*(config->map));
            std::cout << localMap->objects.size();
        config->mutex.unlock();

        localMap->accept(painter);

        emit renderedImage(image, scaleFactor);

        delete localMap; // mozna zmienic na sprytny wskaznik
    }
}
