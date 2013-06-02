#ifndef SERVER_HUNTINGACTION_HPP
#define SERVER_HUNTINGACTION_HPP

#include "Action.hpp"
namespace server {

class HuntingAction : public server::Action
{
public:
    HuntingAction(int priority, common::Creature & creature, common::MapObject& object);
    virtual bool perform(double time_interval);
};

} // namespace server

#endif // SERVER_HUNTINGACTION_HPP
