#ifndef SERVER_GENETICS_HPP
#define SERVER_GENETICS_HPP

#include "../../common/Config.hpp"

namespace common
{
 // fwd declaration
    class Creature;
    class Map;
}

namespace server
{
    // fwd declaration
    class Genotype;

    class Genetics
    {
        Genetics() = delete;
        static const int MUTATION_COUNT;
    public:
        static void makeChild(common::Creature*, common::Creature*);
};

} // namespace server

#endif // SERVER_GENETICS_HPP
