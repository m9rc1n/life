#include <QString>
#include <QtTest>

#define ENABLE_MEMORY_TEST 1

// beware classes, im coming
#define protected public
#define private public

#include "../../common/Map.hpp"
#include "../../common/Creature.hpp"
#include "../../common/Herbivore.hpp"
#include "../../common/Predator.hpp"

#include "../../server/AwarenessDetector.hpp"
#include "../../server/genetics/Genotype.hpp"


#include "../../server/server.hpp"
#include "../../client/client.hpp"

#include <cmath>

class lifeTest : public QObject
{
    Q_OBJECT
    
public:
    lifeTest();
    
private Q_SLOTS:
    void testCase1();
    void testCase2();
    void testCase3();
    void testCase4();

    void memoryTest();
    void serverMemoryTest();
    void serverAndClientMemoryTest();
};

lifeTest::lifeTest()
{
    //testCase1();
    //testCase2();
    //testCase3();
}

void lifeTest::testCase1()
{

    common::Predator p(3,4,0,0,0,0,0,0,0,0,0,0);

    QTEST_ASSERT(p.getX() == 3);
    QTEST_ASSERT(p.getY() == 4);

    common::Herbivore h1(4,5,0,0,0,0,0,0,0,0,0,0);
    QTEST_ASSERT(h1.getX() == 4);
    QTEST_ASSERT(h1.getY() == 5);
    QTEST_ASSERT (abs(p.getDirectionOfObjectInDegrees(h1) - 45) < 0.01);

    common::Herbivore h2(3,5,0,0,0,0,0,0,0,0,0,0);
    QTEST_ASSERT (abs(p.getDirectionOfObjectInDegrees(h2) - 0) < 0.01);

    common::Herbivore h3(4,3,0,0,0,0,0,0,0,0,0,0);
    QTEST_ASSERT (abs(p.getDirectionOfObjectInDegrees(h3) - 135) < 0.01);

    common::Herbivore h4(3,4,0,0,0,0,0,0,0,0,0,0);
    double nan = p.getDirectionOfObjectInDegrees(h4); // should be nan
    QTEST_ASSERT (nan != nan);

    common::Herbivore h5(2,3,0,0,0,0,0,0,0,0,0,0);
    QTEST_ASSERT (abs(p.getDirectionOfObjectInDegrees(h5) - 225) < 0.01);

    common::Herbivore h6(2,4,0,0,0,0,0,0,0,0,0,0);
    QTEST_ASSERT (abs(p.getDirectionOfObjectInDegrees(h6) - 270) < 0.01);

    h1.direction_ = 90;
    QTEST_ASSERT (abs(h1.getDirectionInDegrees() - 90) < 0.01);
    QTEST_ASSERT (abs(h1.getDirectionInRadians() - 3.14159/2) < 0.01);

    h1.moveByVector(-4, -5);
    QTEST_ASSERT (abs((h1.getX()) < 0.001));
    QTEST_ASSERT (abs(h1.getY()) < 0.001);

    h1.moveByDistance(1); // go right
    QTEST_ASSERT (abs((h1.getX() - 1) < 0.01));
    QTEST_ASSERT (abs(h1.getY()) < 0.001);

    h1.turnToObject(h3);
    QTEST_ASSERT (abs(h1.getDirectionInDegrees() - 45) < 0.01);

    h1.moveByDistance(1);
    QTEST_ASSERT (abs(h1.getX()- (sqrt(2)/2 + 1)) < 0.01);
    QTEST_ASSERT (abs(h1.getY()- sqrt(2)/2) <     0.01);
}


void lifeTest::testCase2()
{
    common::Predator p1(1,1,0,0,0,0,0,0,0,0,0,0);
    common::Predator p2(2,2,0,0,0,0,0,0,0,0,0,0);
    p1.direction_ = 0;
    p1.partiallyTurnAndMoveToObject(p2, 1, 1);
    std::cout << p1.direction_ << std::endl;
    QTEST_ASSERT (abs (p1.direction_ - 1) < 0.001);
}

void lifeTest::testCase3()
{
    common::Predator p1(10,10,0,20,25,0,0,0,0,0,0,0);
    common::Predator p2(20,20,0,0,0,0,0,0,0,0,0,0);
    QTEST_ASSERT(!AwarenessDetector::isAware(p1, p2));
    common::Predator p3(10,10,0,20,44,0,0,0,0,0,0,0);
    QTEST_ASSERT(!AwarenessDetector::isAware(p3, p2));
    common::Predator p4(10,10,0,20,46,0,0,0,0,0,0,0);
    QTEST_ASSERT(AwarenessDetector::isAware(p4, p2));
}

void lifeTest::testCase4()
{
    {
        common::Herbivore c(0,0,0,10,20,30,40,50,60,70,80,0);
        server::Genotype g(&c);
        g.normalize();
        QTEST_ASSERT(g.angle_ + g.fecundity_ + g.max_age_ + g.max_energy_ +
                     g.max_hydration_ + g.max_repletion_ + g.radius_ + g.speed_ == 200);
        QTEST_ASSERT(g.angle_ >= 0);
        QTEST_ASSERT(g.fecundity_>= 0);
        QTEST_ASSERT(g.max_age_>= 0);
        QTEST_ASSERT(g.max_energy_>= 0);
        QTEST_ASSERT(g.max_hydration_>= 0);
        QTEST_ASSERT(g.max_repletion_>= 0);
        QTEST_ASSERT(g.radius_>= 0);
        QTEST_ASSERT(g.speed_>= 0);
    }
    {
        common::Herbivore c(0,0,0,37346,34619,43664,43656,43346,64610,34654,24655,0);
        server::Genotype g(&c);
        g.normalize();
        QTEST_ASSERT(g.angle_ + g.fecundity_ + g.max_age_ + g.max_energy_ +
                     g.max_hydration_ + g.max_repletion_ + g.radius_ + g.speed_ == 200);
        QTEST_ASSERT(g.angle_ >= 0);
        QTEST_ASSERT(g.fecundity_>= 0);
        QTEST_ASSERT(g.max_age_>= 0);
        QTEST_ASSERT(g.max_energy_>= 0);
        QTEST_ASSERT(g.max_hydration_>= 0);
        QTEST_ASSERT(g.max_repletion_>= 0);
        QTEST_ASSERT(g.radius_>= 0);
        QTEST_ASSERT(g.speed_>= 0);
    }
}

void lifeTest::memoryTest()
{
    int count;
    {
        common::Map map(345,567);
        for(int i=0; i<1000; ++i)
        {
            map.appendObject(new common::Predator(0,0,0,10,20,30,40,50,60,70,80,0));
        }
        for(int i=0; i<1000; ++i)
        {
            map.appendObject(new common::Herbivore(0,0,0,10,20,30,40,50,60,70,80,0));
        }

        count = AllocationCounter::getCount();
        QTEST_ASSERT(count == 2000);

        common::Map map2(map);
        for(int i=0; i<13; ++i)
        {
            map2.appendObject(new common::Herbivore(0,0,0,10,20,30,40,50,60,70,80,0));
        }

        QTEST_ASSERT(map2.objects.size() == 2013);

        count = AllocationCounter::getCount();
        QTEST_ASSERT(count == 4013);
    }
    count = AllocationCounter::getCount();
    QTEST_ASSERT(count == 0);// count > 0 means memory leak
}

void lifeTest::serverMemoryTest()
{
    QTEST_ASSERT(AllocationCounter::getCount() == 0);

    // tworzymy jakiś plik konfiguracyjny
    common::Config::getInstance()->number_of_herbivores = 90;
    common::Config::getInstance()->number_of_predators = 90;
    common::Config::getInstance()->number_of_lairs = 90;
    common::Config::getInstance()->number_of_trees = 90;
    common::Config::getInstance()->number_of_waterholes = 90;

    common::Config::getInstance()->map_height = 100;
    common::Config::getInstance()->map_width = 100;

    {
        std::cout << "Running example server.." << std:: endl;
        // tworzymy głupi serwerek, odpalamy
        server::Server testServ;
        testServ.start();

        // czekamy 2 sekundy
        QTime dieTime = QTime::currentTime().addSecs(2);
        while( QTime::currentTime() < dieTime );

        // kulturalnie ubijamy
        common::Config::getInstance()->stop = 1;

        while(!testServ.isFinished()){}
    }

    QTEST_ASSERT(AllocationCounter::getCount() == 0);
}


void lifeTest::serverAndClientMemoryTest()
{
    QTEST_ASSERT(AllocationCounter::getCount() == 0);

    // tworzymy jakiś plik konfiguracyjny
    common::Config::getInstance()->number_of_herbivores = 900;
    common::Config::getInstance()->number_of_predators = 900;
    common::Config::getInstance()->number_of_lairs = 900;
    common::Config::getInstance()->number_of_trees = 900;
    common::Config::getInstance()->number_of_waterholes = 900;

    common::Config::getInstance()->simulation_speed = 0.5;

    common::Config::getInstance()->map_height = 50;
    common::Config::getInstance()->map_width = 50;

    {
        std::cout << "Running example server..." << std:: endl;
        // serwer
        server::Server testServ;
        testServ.start();

        std::cout << "Running example client..." << std:: endl;
        client::Client testClient(common::Config::getInstance());
        testClient.start();

        // czekamy 3 sekundy
        QTime dieTime = QTime::currentTime().addSecs(3);
        while( QTime::currentTime() < dieTime );

        // kulturalnie ubijamy
        common::Config::getInstance()->stop = 1;

        while(!testServ.isFinished()){}
        while(!testClient.isFinished()){}
    }

    QTEST_ASSERT(AllocationCounter::getCount() == 0);
}


QTEST_APPLESS_MAIN(lifeTest)

#include "tst_lifetest.moc"
