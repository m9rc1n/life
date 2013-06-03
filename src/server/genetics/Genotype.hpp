#ifndef SERVER_GENOTYPE_HPP
#define SERVER_GENOTYPE_HPP

#include "../../common/Creature.hpp"

namespace server {

class Genotype
{
public:
    /**
     * @brief Generuje obiekt genomu na podstawie żyjącego stworzenia
     * @param creature
     */
    Genotype(common::Creature *creature);
    /**
     * @brief Generuje obiekt genomu na podstawie dwóch innych genomów
     * @param mather genom matki
     * @param father genom ojca
     */
    Genotype(Genotype mother, Genotype father);
    /**
     * @brief Mutuje, wprowadzając jedną losową zmianę
     */
    void mutate();
private:
    int radius_;
    int angle_;
    int speed_;
    int fecundity_;
    int max_repletion_;
    int max_hydration_;
    int max_energy_;
    int max_age_;
};

} // namespace server

#endif // SERVER_GENOTYPE_HPP
