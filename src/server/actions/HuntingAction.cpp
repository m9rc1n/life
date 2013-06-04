#include "HuntingAction.hpp"

namespace server
{

    HuntingAction::HuntingAction(int priority, common::Creature & creature, common::MapObject& object):
        Action(priority, creature, object)
    {
    }
    bool HuntingAction::perform(double time_interval)
    {
        common::Creature &herbivore = dynamic_cast<common::Creature&> (object_);
        if(creature_.isHungry())
        {
            if(creature_.getDistance(object_) < DISTANCE_TO_ASSUME_TARGET_ACHIEVED ) // cel osiagniety
            {
                creature_.eat();
                herbivore.beEaten();
                return true;
            }
            else
            {
                creature_.partiallyTurnAndMoveToObject(object_, creature_.getSpeed() * time_interval/ SPEED_FACTOR_FOR_MOVING, creature_.getSpeed() * time_interval/ SPEED_FACTOR_FOR_ROTATING );
                return true;
            }
        }
        return false;
    }

} // namespace server
