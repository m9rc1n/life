#include "HuntingAction.hpp"

namespace server {

    HuntingAction::HuntingAction(int priority, common::Creature & creature, common::MapObject& object):
        Action(priority, creature, object)
    {
    }
    bool HuntingAction::perform(double time_interval)
    {

        if(creature_.isHungry())
        {
            if(creature_.getDistance(object_) < 1) // cel osiagniety
            {
                creature_.eat();
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
