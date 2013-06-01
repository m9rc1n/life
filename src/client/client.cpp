#include "client.hpp"
#include <math.h>
#include <QWidget>

client::Client::Client(common::Config *config, QObject *parent)
    : QThread(parent),
      config(config)
{
    restart = false;
    abort = false;

    for (int i = 0; i < ColormapSize; ++i)
        colormap[i] = 2;//rgbFromWaveLength(380.0 + (i * 400.0 / ColormapSize));
}

client::Client::~Client()
{
    config->mutex.lock();
    abort = true;
    config->condition.wakeOne();
    config->mutex.unlock();

    wait();
}

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
        restart = true;
        config->condition.wakeOne();
    }
}

void client::Client::run()
{
    common::Map* localMap;

    QImage image(resultSize, QImage::Format_RGB32);

    client::PaintingVisitor painter(&image);
    client::StatisticsVisitor stater;

    for(int i = 0;; ++i) // nieskonczona petla
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        image.fill(666666);

        for (int y = 10+i; y < 20+i; ++y)
        {
            for (int x = 10+i; x < 20+i; ++x)
            {
                image.setPixel(QPoint(x, y), 66666666);
            }
        }

        emit renderedImage(image, scaleFactor);


        config->mutex.lock();
            localMap = new common::Map(*(config->map));
        config->mutex.unlock();

        localMap->accept(painter);

        /*
        std::vector<common::MapObject*>::iterator obj = localMap->objects.begin();

        for (obj; obj!=localMap->objects.end(); obj++)
        {
            /// @todo nie działa ??? (*i)->accept(painter);
            // localMap->objects.at(i);
        }
        */

        for (int index=0; index<localMap->objects.size(); index++)
        {
            /// @todo nie działa ??? (*i)->accept(painter);
            // localMap->objects.at(i);
            localMap->objects[index]->accept(painter);
        }

        localMap->accept(stater);

        // robimy cos z mapa: wyswietlamy, aktualizujemy statystyki
        // za pomoca wizytatorow, np. jesli mamy wizytatoror Stat
        // to robimy Stat.visit(*localMap);

        delete localMap; // mozna zmienic na sprytny wskaznik
    }
    /*
    forever {

        std::cout << "Jestem klientem!\n" << std::endl;

        config->mutex.lock();
            QSize resultSize = this->resultSize;
            double scaleFactor = this->scaleFactor;
            double centerX = this->centerX;
            double centerY = this->centerY;
        config->mutex.unlock();

        int halfWidth = resultSize.width() / 2;

        int halfHeight = resultSize.height() / 2;
        QImage image(resultSize, QImage::Format_RGB32);

        const int NumPasses = 8;
        int pass = 0;
        while (pass < NumPasses) {
            const int MaxIterations = (1 << (2 * pass + 6)) + 32;
            const int Limit = 4;
            bool allBlack = true;

            for (int y = -halfHeight; y < halfHeight; ++y) {
                if (restart)
                    break;
                if (abort)
                    return;

                uint *scanLine =
                        reinterpret_cast<uint *>(image.scanLine(y + halfHeight));
                double ay = centerY + (y * scaleFactor);

                for (int x = -halfWidth; x < halfWidth; ++x) {
                    double ax = centerX + (x * scaleFactor);
                    double a1 = ax;
                    double b1 = ay;
                    int numIterations = 0;

                    do {
                        ++numIterations;
                        double a2 = (a1 * a1) - (b1 * b1) + ax;
                        double b2 = (2 * a1 * b1) + ay;
                        if ((a2 * a2) + (b2 * b2) > Limit)
                            break;

                        ++numIterations;
                        a1 = (a2 * a2) - (b2 * b2) + ax;
                        b1 = (2 * a2 * b2) + ay;
                        if ((a1 * a1) + (b1 * b1) > Limit)
                            break;
                    } while (numIterations < MaxIterations);

                    if (numIterations < MaxIterations) {
                        *scanLine++ = colormap[numIterations % ColormapSize];
                        allBlack = false;
                    } else {
                        *scanLine++ = qRgb(0, 0, 0);
                    }
                }
            }

            if (allBlack && pass == 0) {
                pass = 4;
            } else {
                if (!restart)
                    emit renderedImage(image, scaleFactor);
                ++pass;
            }
        }

        config->mutex.lock();
            if (!restart)
                config->condition.wait(mutex);
            restart = false;
        config->mutex.unlock();
    }
    */
}

