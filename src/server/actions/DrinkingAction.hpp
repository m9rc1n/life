#ifndef SERVER_DRINKINGACTION_HPP
#define SERVER_DRINKINGACTION_HPP

#include "Action.hpp"
namespace server {

class DrinkingAction : public server::Action
{
public:
    DrinkingAction(int priority, common::Creature & creature, common::MapObject& object);
    virtual bool perform();
};

} // namespace server

#endif // SERVER_DRINKINGACTION_HPP
