#include "EatingAction.hpp"

using namespace server;

server::EatingAction::EatingAction(int priority, common::Creature & creature, common::MapObject& object):
    Action(priority, creature, object)
{
}

bool server::EatingAction::perform(double time_interval)
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
            creature_.partiallyTurnAndMoveToObject(object_, creature_.getSpeed() * time_interval/ 2000, creature_.getSpeed() * time_interval/ 15000);
            return true;
        }
    }
    return false;
}
