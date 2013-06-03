#ifndef SERVER_GENOME_HPP
#define SERVER_GENOME_HPP

#include "../../common/Creature.hpp"

namespace server {

class Genome
{
public:
    /**
     * @brief Generuje obiekt genomu na podstawie żyjącego stworzenia
     * @param creature
     */
    Genome(common::Creature *creature);
};

} // namespace server

#endif // SERVER_GENOME_HPP
