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
            if(creature_.getDistance(object_) < 1) // cel osiagniety
            {
                creature_.drink();
                return true;
            }
            else
            {
                creature_.partiallyTurnAndMoveToObject(object_, creature_.getSpeed() * time_interval/ 15000, creature_.getSpeed() * time_interval/ 15000);
                return true;
            }
        }
        return false;
    }

} // namespace server
