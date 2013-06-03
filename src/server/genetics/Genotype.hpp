#ifndef SERVER_GENOTYPE_HPP
#define SERVER_GENOTYPE_HPP

#include "../../common/Herbivore.hpp"
#include "../../common/Predator.hpp"

namespace server {

class Genotype
{
public:
    /**
     * @brief Generuje obiekt genotypu na podstawie żyjącego stworzenia
     * @param creature
     */
    Genotype(common::Creature *creature);
    /**
     * @brief Generuje obiekt genomu na podstawie dwóch innych genomów
     * @param mather genotyp matki
     * @param father genotyp ojca
     */
    Genotype(Genotype mother, Genotype father);
    /**
     * @brief Normalizuje genotyp
     */
    void normalize();
    /**
     * @brief Mutuje, wprowadzając jedną losową zmianę
     */
    void mutate();

    /**
     * @brief Umieszcza na mapie obiekt o zadanym genotypie
     */
    void putToMap(double x, double y, common::Map *map);

    enum Species { HERBIVORE, PREDATOR };
private:
    int radius_;
    int angle_;
    int speed_;
    int fecundity_;
    int max_repletion_;
    int max_hydration_;
    int max_energy_;
    int max_age_;
    Species species;
};

} // namespace server

#endif // SERVER_GENOTYPE_HPP
