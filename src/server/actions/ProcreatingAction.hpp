#ifndef SERVER_PROCREATINGACTION_HPP
#define SERVER_PROCREATINGACTION_HPP

#include "Action.hpp"
#include "../../const.h"
namespace server {

class ProcreatingAction : public server::Action
{
public:
    ProcreatingAction(int priority, common::Creature & creature, common::MapObject& object);
    virtual bool perform(double time_interval);
};

} // namespace server

#endif // SERVER_PROCREATINGACTION_HPP
