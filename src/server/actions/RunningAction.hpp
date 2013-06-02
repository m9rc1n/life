#ifndef SERVER_RUNNINGACTION_HPP
#define SERVER_RUNNINGACTION_HPP

#include "Action.hpp"
namespace server {

class RunningAction : public server::Action
{
public:
    RunningAction(int priority);
    virtual void perform(common::Creature &);
};

} // namespace server

#endif // SERVER_RUNNINGACTION_HPP
