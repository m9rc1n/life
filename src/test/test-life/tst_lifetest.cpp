#include <QString>
#include <QtTest>

// beware classes, im coming
#define protected public
#define private public

#include "../../common/Creature.hpp"
#include "../../common/Herbivore.hpp"
#include "../../common/Predator.hpp"

#include "../../server/AwarenessDetector.hpp"
#define private public
#define protected public
#include "../../server/genetics/Genotype.hpp"

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
    std::cout << ":)" << std::endl;
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


QTEST_APPLESS_MAIN(lifeTest)

#include "tst_lifetest.moc"
