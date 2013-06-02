#include "SleepingAction.hpp"

namespace server {

SleepingAction::SleepingAction(int priority, common::Creature & creature, common::MapObject& object):
    Action(priority, creature, object)
{
}
bool SleepingAction::perform()
{

}

} // namespace server
