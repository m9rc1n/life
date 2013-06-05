#include "SleepingAction.hpp"

namespace server {

SleepingAction::SleepingAction(int priority, common::Creature & creature, common::MapObject& object):
    Action(priority, creature, object)
{
}
bool SleepingAction::perform(double time_interval)
{
    if(creature_.isTired())
    {
        if(creature_.getDistance(object_) < DISTANCE_TO_ASSUME_TARGET_ACHIEVED ) // cel osiagniety
        {
            creature_.fallAsleep();
            return true;
        }
        else
        {
            creature_.partiallyTurnAndMoveToObject(object_, creature_.getSpeed() * time_interval / SPEED_FACTOR_FOR_MOVING, creature_.getSpeed() * time_interval / SPEED_FACTOR_FOR_ROTATING );
            return true;
        }
    }
}

} // namespace server
