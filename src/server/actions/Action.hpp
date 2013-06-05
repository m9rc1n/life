#ifndef ACTION_HPP
#define ACTION_HPP

#include "../../common/Creature.hpp"

namespace server
{
    class Action
    {
    protected:
        int priority_;
        common::Creature &creature_;
        common::MapObject &object_;
    public:
        Action(int priority, common::Creature & creature, common::MapObject& object);
        virtual bool perform(double time_interval){ throw new std::exception(); return true; }
        int getPriority() const
        {
            return priority_;
        }
        virtual~Action(){};

        struct compare
        {
            bool operator() (Action* action1, Action* action2)
            {
                return (action1->getPriority() < action2->getPriority());
            }
        };
    };
}

#endif // ACTION_HPP
