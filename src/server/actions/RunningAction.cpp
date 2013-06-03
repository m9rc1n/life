#include "RunningAction.hpp"

namespace server {

RunningAction::RunningAction(int priority, common::Creature & creature, common::MapObject& object):
    Action(priority, creature, object)
{
}
bool RunningAction::perform(double time_interval)
{
    creature_.partiallyTurnOppositeAndMoveFromObject(object_, creature_.getSpeed() * time_interval / 1200, creature_.getSpeed() * time_interval / 12000);
    return true;
}

} // namespace server
