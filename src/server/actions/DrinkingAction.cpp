#include "DrinkingAction.hpp"

namespace server
{

    DrinkingAction::DrinkingAction(int priority, common::Creature & creature, common::MapObject& object):
        Action(priority, creature, object)
    {
    }
    bool DrinkingAction::perform()
    {
        if(creature_.isThirsty())
        {
            creature_.partiallyTurnAndMoveToObject(object_, 1,1);
        }
    }

} // namespace server
