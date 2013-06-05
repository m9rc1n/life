#ifndef SERVER_RUNNINGACTION_HPP
#define SERVER_RUNNINGACTION_HPP

#include "Action.hpp"
#include "../../const.h"
namespace server {

class RunningAction : public server::Action
{
public:
    virtual~RunningAction(){};
    RunningAction(int priority, common::Creature & creature, common::MapObject& object);
    virtual bool perform(double time_interval);
};

} // namespace server

#endif // SERVER_RUNNINGACTION_HPP
