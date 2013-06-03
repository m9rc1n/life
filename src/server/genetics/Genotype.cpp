#include "Genotype.hpp"
#include "../MapGenerator.hpp"

namespace server
{

    Genotype::Genotype(common::Creature *creature)
    {
        radius_         = creature->getRadius();
        angle_          = creature->getAngle();
        max_repletion_  = creature->getMaxRepletion();
        max_hydration_  = creature->getMaxHydration();
        max_energy_     = creature->getMaxEnergy();
        max_age_        = creature->getMaxAge();
        speed_          = creature->getSpeed();
        fecundity_      = creature->getFecundity();

        if(dynamic_cast<common::Herbivore*>(creature) != NULL)
        {
            species = HERBIVORE;
        }
        else
        {
            species = PREDATOR;
        }
    }

    Genotype::Genotype(const server::Genotype mother, const server::Genotype father)
    {
        radius_         = mother.radius_         + father.radius_        ;
        angle_          = mother.angle_          + father.angle_         ;
        max_repletion_  = mother.max_repletion_  + father.max_repletion_ ;
        max_hydration_  = mother.max_hydration_  + father.max_hydration_ ;
        max_energy_     = mother.max_energy_     + father.max_energy_    ;
        max_age_        = mother.max_age_        + father.max_age_       ;
        speed_          = mother.speed_          + father.speed_         ;
        fecundity_      = mother.fecundity_      + father.fecundity_     ;

        species = mother.species;
    }

    void Genotype::normalize()
    {
        double sum = radius_ + angle_ + speed_ + max_hydration_ + max_repletion_ + max_energy_ + fecundity_ + max_age_;

        radius_          = floor(common::Config::getInstance()->getParameterSum() * radius_          /sum);
        angle_           = floor(common::Config::getInstance()->getParameterSum() * angle_           /sum);
        speed_           = floor(common::Config::getInstance()->getParameterSum() * speed_           /sum);
        max_repletion_   = floor(common::Config::getInstance()->getParameterSum() * max_repletion_   /sum);
        max_hydration_   = floor(common::Config::getInstance()->getParameterSum() * max_hydration_   /sum);
        max_energy_      = floor(common::Config::getInstance()->getParameterSum() * max_energy_      /sum);
        fecundity_       = floor(common::Config::getInstance()->getParameterSum() * max_energy_      /sum);
        max_age_         = common::Config::getInstance()->getParameterSum() - radius_ - angle_ - speed_ - max_repletion_ -
                                                                max_hydration_ - max_energy_ - fecundity_;
        if(max_age_ < 5) // anomalia... poprawiamy ręcznie
        {
            radius_ --;
            angle_--;
            speed_ --;
            fecundity_--;
            max_energy_-- ;
            max_repletion_--;
            max_hydration_--;
            max_age_ += 7;
        }

    }

    void Genotype::mutate()
    {
        int *parameters[] = {&radius_, &angle_, &speed_, &fecundity_, &max_energy_, &max_repletion_, &max_hydration_, &max_age_};
        int inc = rand() % 8;
        int dec = rand() % 8;
        ++ *parameters[inc];
        -- *parameters[dec];
    }

    void Genotype::putToMap(double x, double y, common::Map *map)
    {
        double direction = MapGenerator::getRandomDirection();
        bool is_male = MapGenerator::getRandomBool();
        common::Creature *creature;
        if(species == HERBIVORE)
        {
            creature = new common::Herbivore(x, y, direction, radius_, angle_, speed_,
                                                         max_repletion_, max_hydration_, max_energy_, fecundity_, max_age_, is_male);
        }
        else
        {
            creature = new common::Predator(x, y, direction, radius_, angle_, speed_,
                                                       max_repletion_, max_hydration_, max_energy_, fecundity_, max_age_, is_male);
        }
        map->appendObject(creature);
    }

} // namespace server
