#ifndef SERVER_SLEEPINGACTION_HPP
#define SERVER_SLEEPINGACTION_HPP

#include "Action.hpp"
namespace server {

class SleepingAction : public server::Action
{
public:
    SleepingAction(int priority);
    virtual void perform(common::Creature &);
};

} // namespace server

#endif // SERVER_SLEEPINGACTION_HPP
