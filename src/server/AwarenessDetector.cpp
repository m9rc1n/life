#include "AwarenessDetector.hpp"


bool AwarenessDetector::isAware(common::Creature &creature, common::MapObject &map_object)
{
    return doesItHear(creature, map_object) or doesItSee(creature, map_object);
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

    double current_direction = creature.getDirectionInDegrees();
    double object_direction = creature.getDirectionOfObjectInDegrees(map_object);
    double diff = abs(current_direction - object_direction);
    double angle = std::min(diff, 360 - diff);

    if(angle > creature.getAngle())
    {
        return false;
    }
    else
    {
        return true;
    }
}
