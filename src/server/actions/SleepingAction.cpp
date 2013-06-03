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
        if(creature_.getDistance(object_) < 1) // cel osiagniety
        {
            creature_.fallAsleep();
            return true;
        }
        else
        {
            creature_.partiallyTurnAndMoveToObject(object_, creature_.getSpeed() * time_interval / 2800, creature_.getSpeed() * time_interval / 22000);
            return true;
        }
    }
}

} // namespace server
