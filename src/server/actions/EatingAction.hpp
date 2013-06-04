#ifndef EATINGACTION_HPP
#define EATINGACTION_HPP

#include "Action.hpp"
#include "../../const.h"

namespace server
{
    class EatingAction : public server::Action
    {
    public:
        EatingAction(int priority, common::Creature & creature, common::MapObject& object);
        virtual bool perform(double time_interval);
    };
}
#endif // EATINGACTION_HPP
