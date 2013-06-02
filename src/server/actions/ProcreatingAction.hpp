#ifndef SERVER_PROCREATINGACTION_HPP
#define SERVER_PROCREATINGACTION_HPP

#include "Action.hpp"
namespace server {

class ProcreatingAction : public server::Action
{
public:
    ProcreatingAction(int priority, common::Creature & creature, common::MapObject& object);
    virtual bool perform();
};

} // namespace server

#endif // SERVER_PROCREATINGACTION_HPP
