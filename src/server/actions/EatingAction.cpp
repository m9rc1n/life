#include "EatingAction.hpp"

using namespace server;

server::EatingAction::EatingAction(int priority, common::Creature & creature, common::MapObject& object):
    Action(priority, creature, object)
{
}

bool server::EatingAction::perform()
{

}
