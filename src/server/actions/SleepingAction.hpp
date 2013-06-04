#ifndef SERVER_SLEEPINGACTION_HPP
#define SERVER_SLEEPINGACTION_HPP

#include "Action.hpp"
#include "../../const.h"
namespace server {

class SleepingAction : public server::Action
{
public:
    virtual~SleepingAction(){};
    SleepingAction(int priority, common::Creature & creature, common::MapObject& object);
    virtual bool perform(double time_interval);
};

} // namespace server

#endif // SERVER_SLEEPINGACTION_HPP
