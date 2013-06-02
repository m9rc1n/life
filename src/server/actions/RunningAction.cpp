#include "RunningAction.hpp"

namespace server {

RunningAction::RunningAction(int priority, common::Creature & creature, common::MapObject& object):
    Action(priority, creature, object)
{
}
bool RunningAction::perform()
{

}

} // namespace server
