#include "ProcreatingAction.hpp"

namespace server {

ProcreatingAction::ProcreatingAction(int priority, common::Creature & creature, common::MapObject& object):
    Action(priority, creature, object)
{
}
bool ProcreatingAction::perform()
{

}

} // namespace server
