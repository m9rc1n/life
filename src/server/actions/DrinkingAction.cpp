#include "DrinkingAction.hpp"

namespace server
{

    DrinkingAction::DrinkingAction(int priority, common::Creature & creature, common::MapObject& object):
        Action(priority, creature, object)
    {
    }
    bool DrinkingAction::perform(double time_interval)
    {
        if(creature_.isThirsty())
        {
            if(creature_.getDistance(object_) < DISTANCE_TO_ASSUME_TARGET_ACHIEVED ) // cel osiagniety
            {
                creature_.drink();
                return true;
            }
            else
            {
                creature_.partiallyTurnAndMoveToObject(object_, creature_.getSpeed() * time_interval/ SPEED_FACTOR_FOR_MOVING, creature_.getSpeed() * time_interval/SPEED_FACTOR_FOR_ROTATING );
                return true;
            }
        }
        return false;
    }

} // namespace server
