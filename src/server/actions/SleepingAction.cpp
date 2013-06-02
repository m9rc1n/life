#include "SleepingAction.hpp"

namespace server {

SleepingAction::SleepingAction(int priority):
    Action(priority)
{
}
void SleepingAction::perform(common::Creature & creature)
{

}

} // namespace server
