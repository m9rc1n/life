#include <mutex> // c++11
#include <iostream>
#include <thread> // c++11
#include <chrono> // c++11

#include <QThread>
#include "../common/Config.hpp"
#include "../common/Map.hpp"
#include "MapGenerator.hpp"
#include "SimulationVisitor.hpp"

namespace server
{
    class Server : public QThread
    {
        Q_OBJECT

    public:
        Server( QObject *parent = 0);

    protected:
        void run();
        static common::Map *localMap;

        friend class Genetics;
    };
}
