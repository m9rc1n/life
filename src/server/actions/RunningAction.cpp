#include "RunningAction.hpp"

namespace server {

RunningAction::RunningAction(int priority):
    Action(priority)
{
}
void RunningAction::perform(common::Creature & creature)
{

}

} // namespace server
