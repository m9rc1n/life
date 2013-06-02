#ifndef EATINGACTION_HPP
#define EATINGACTION_HPP

#include "Action.hpp"

namespace server
{
    class EatingAction : public server::Action
    {
    public:
        EatingAction(int priority);
        virtual void perform(common::Creature &);
    };
}
#endif // EATINGACTION_HPP
