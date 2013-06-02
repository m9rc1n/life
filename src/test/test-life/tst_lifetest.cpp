#include <QString>
#include <QtTest>

// beware classes, im coming
#define protected public
#define private public

#include "../../common/Creature.hpp"
#include "../../common/Herbivore.hpp"
#include "../../common/Predator.hpp"

#include "../../server/AwarenessDetector.hpp"

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
};

lifeTest::lifeTest()
{
    //testCase1();
    //testCase2();
    //testCase3();
}

void lifeTest::testCase1()
{

    common::Predator p(3,4);

    QTEST_ASSERT(p.getX() == 3);
    QTEST_ASSERT(p.getY() == 4);

    common::Herbivore h1(4,5);
    QTEST_ASSERT(h1.getX() == 4);
    QTEST_ASSERT(h1.getY() == 5);
    QTEST_ASSERT (abs(p.getDirectionOfObjectInDegrees(h1) - 45) < 0.01);

    common::Herbivore h2(3,5);
    QTEST_ASSERT (abs(p.getDirectionOfObjectInDegrees(h2) - 0) < 0.01);

    common::Herbivore h3(4,3);
    QTEST_ASSERT (abs(p.getDirectionOfObjectInDegrees(h3) - 135) < 0.01);

    common::Herbivore h4(3,4);
    double nan = p.getDirectionOfObjectInDegrees(h4); // should be nan
    QTEST_ASSERT (nan != nan);

    common::Herbivore h5(2,3);
    QTEST_ASSERT (abs(p.getDirectionOfObjectInDegrees(h5) - 225) < 0.01);

    common::Herbivore h6(2,4);
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
    common::Predator p1(1,1);
    common::Predator p2(2,2);
    p1.direction_ = 0;
    p1.partiallyTurnAndMoveToObject(p2, 1, 1);
    std::cout << p1.direction_ << std::endl;
    QTEST_ASSERT (abs (p1.direction_ - 1) < 0.001);
}

void lifeTest::testCase3()
{
    common::Predator p1(1,1);
    common::Predator p2(2,2);
    p1.direction_ = 0;
    p1.angle_ = 25;
    p1.radius_ = 2;
    QTEST_ASSERT(!AwarenessDetector::isAware(p1, p2));
    p1.angle_ = 44;
    p1.radius_ = 2;
    QTEST_ASSERT(!AwarenessDetector::isAware(p1, p2));
    p1.angle_ = 46;
    p1.radius_ = 2;
    QTEST_ASSERT(AwarenessDetector::isAware(p1, p2));
    std::cout << ":)" << std::endl;
}

QTEST_APPLESS_MAIN(lifeTest)

#include "tst_lifetest.moc"
