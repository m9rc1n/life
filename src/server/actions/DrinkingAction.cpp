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
            std::cout << "Going to waterhole (" << object_.getX() << ", " << object_.getY()<< ") "<< std::endl;
            creature_.partiallyTurnAndMoveToObject(object_,2,0.2);
            return true;
        }
    }

} // namespace server
