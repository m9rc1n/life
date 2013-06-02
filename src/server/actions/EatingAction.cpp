#include "EatingAction.hpp"

using namespace server;

server::EatingAction::EatingAction(int priority):
    Action(priority)
{
}

void server::EatingAction::perform(common::Creature & creature)
{

}
