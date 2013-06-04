#include "EatingAction.hpp"
#include "../../common/Tree.hpp"

using namespace server;

server::EatingAction::EatingAction(int priority, common::Creature & creature, common::MapObject& object):
    Action(priority, creature, object)
{
}

bool server::EatingAction::perform(double time_interval)
{
    if(creature_.isHungry())
    {
        common::Tree &tree = dynamic_cast<common::Tree&>(object_);
        if(creature_.getDistance(object_) < DISTANCE_TO_ASSUME_TARGET_ACHIEVED ) // cel osiagniety
        {
            creature_.eat();
            tree.eatLeafs(LEAFS_EATEN_AT_ONCE);
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
