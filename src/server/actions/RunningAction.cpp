#include "RunningAction.hpp"

namespace server {

RunningAction::RunningAction(int priority, common::Creature & creature, common::MapObject& object):
    Action(priority, creature, object)
{
}
bool RunningAction::perform(double time_interval)
{
    creature_.partiallyTurnOppositeAndMoveFromObject(object_, BOOST_FOR_RUNNING * creature_.getSpeed() * time_interval / SPEED_FACTOR_FOR_MOVING, BOOST_FOR_RUNNING * creature_.getSpeed() * time_interval / SPEED_FACTOR_FOR_ROTATING );
    return true;
}

} // namespace server
