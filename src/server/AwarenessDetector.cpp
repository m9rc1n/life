#include "AwarenessDetector.hpp"


bool AwarenessDetector::isAware(common::Creature &creature, common::MapObject &map_object)
{
    bool is_aware = doesItHear(creature, map_object) or doesItSee(creature, map_object);
    return is_aware;
}

bool AwarenessDetector::doesItHear(common::Creature &creature, common::MapObject &map_object)
{
    double dist = creature.getDistance(map_object);

    if(dist > 5)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool AwarenessDetector::doesItSee(common::Creature &creature, common::MapObject &map_object)
{
    double dist = creature.getDistance(map_object);

    if(dist > creature.getRadius())
    {
        return false;
    }

    double angle = fabs(creature.getAngleDifference(map_object));

    if(angle > (double)creature.getAngle())
    {
        return false;
    }
    else
    {
        return true;
    }
}
