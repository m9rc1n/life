
#define protected public
#include "../common/Creature.hpp"
#include "../common/Herbivore.hpp"
#include "../common/Predator.hpp"

#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

BOOST_AUTO_TEST_CASE( test1 )
{
    common::Predator p(3,4);

    BOOST_CHECK(p.getX() == 3);
    BOOST_CHECK(p.getY() == 4);

    common::Herbivore h1(4,5);
    BOOST_CHECK(h1.getX() == 4);
    BOOST_CHECK(h1.getY() == 5);
    BOOST_CHECK_CLOSE (p.getDirectionOfObjectInDegrees(h1), 45, 0.01);
    
    common::Herbivore h2(3,5);
    BOOST_CHECK_CLOSE (p.getDirectionOfObjectInDegrees(h2), 0, 0.01);
    
    common::Herbivore h3(4,3);
    BOOST_CHECK_CLOSE (p.getDirectionOfObjectInDegrees(h3), 135, 0.01);
    
    common::Herbivore h4(3,4);
    double nan = p.getDirectionOfObjectInDegrees(h4); // should be nan
    BOOST_CHECK (nan != nan);
    
    common::Herbivore h5(2,3);
    BOOST_CHECK_CLOSE (p.getDirectionOfObjectInDegrees(h5), 225, 0.01);
    
    common::Herbivore h6(2,4);
    BOOST_CHECK_CLOSE (p.getDirectionOfObjectInDegrees(h6), 270, 0.01);
    
    h1.direction_ = 90;
    BOOST_CHECK_CLOSE(h1.getDirectionInDegrees(), 90, 0.01);
    BOOST_CHECK_CLOSE(h1.getDirectionInRadians(), 3.14159/2, 0.01);
    
    h1.moveByVector(-4, -5);
    BOOST_CHECK_SMALL(h1.getX(), 0.001);
    BOOST_CHECK_SMALL(h1.getY(), 0.001);
    
    h1.moveByDistance(1); // go right
    BOOST_CHECK_CLOSE(h1.getX(), 1, 0.01);
    BOOST_CHECK_SMALL(h1.getY(), 0.001);
    
    h1.turnToObject(h3);
    BOOST_CHECK_CLOSE(h1.getDirectionInDegrees(), 45, 0.01);
    
    h1.moveByDistance(1);
    BOOST_CHECK_CLOSE(h1.getX(), sqrt(2)/2 + 1, 0.01);
    BOOST_CHECK_CLOSE(h1.getY(), sqrt(2)/2,     0.01);
    
}
