#include "Action.hpp"

using namespace server;

server::Action::Action(int priority, common::Creature & creature, common::MapObject& object):
    priority_(priority),
    creature_(creature),
    object_(object)
{
}
