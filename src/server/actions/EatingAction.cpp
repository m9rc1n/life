#include "EatingAction.hpp"

using namespace server;

server::EatingAction::EatingAction(int priority, common::Creature & creature, common::MapObject& object):
    Action(priority, creature, object)
{
}

bool server::EatingAction::perform()
{
    if(creature_.isHungry())
    {
        creature_.partiallyTurnAndMoveToObject(object_, 0.4,0.25);
        return true;
    }
}
