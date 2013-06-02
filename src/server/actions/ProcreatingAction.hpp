#ifndef SERVER_PROCREATINGACTION_HPP
#define SERVER_PROCREATINGACTION_HPP

#include "Action.hpp"
namespace server {

class ProcreatingAction : public server::Action
{
public:
    ProcreatingAction(int priority);
    virtual void perform(common::Creature &);
};

} // namespace server

#endif // SERVER_PROCREATINGACTION_HPP
