#include "ProcreatingAction.hpp"

namespace server {

    ProcreatingAction::ProcreatingAction(int priority, common::Creature & creature, common::MapObject& object):
        Action(priority, creature, object)
    {
    }
    bool ProcreatingAction::perform(double time_interval)
    {
        common::Creature &another = dynamic_cast<common::Creature &>(object_);
        if(!creature_.isHungry() && !creature_.isThirsty() && !creature_.isTired() &&
           !another.isHungry() && !another.isThirsty() && !another.isTired())
        {
            if(creature_.getDistance(object_) < 1) // cel osiagniety
            {
                // write me
                return true;
            }
            else
            {
                creature_.partiallyTurnAndMoveToObject(object_, creature_.getSpeed() * time_interval / 2500, creature_.getSpeed() * time_interval / 15000);
                return true;
            }
        }
        return false;
    }

} // namespace server
