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
        virtual bool perform(){ throw new std::exception(); return true; }
        int getPriority() const
        {
            return priority_;
        }

        struct compare
        {
            inline bool operator() (const Action& action1, const Action& action2)
            {
                return (action1.getPriority() < action2.getPriority());
            }
        };
    };
}

#endif // ACTION_HPP
