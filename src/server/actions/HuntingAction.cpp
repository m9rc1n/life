#include "HuntingAction.hpp"

namespace server {

HuntingAction::HuntingAction(int priority, common::Creature & creature, common::MapObject& object):
    Action(priority, creature, object)
{
}
bool HuntingAction::perform()
{

}

} // namespace server
