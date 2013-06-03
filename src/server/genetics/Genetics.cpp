#include "Genetics.hpp"
#include "Genotype.hpp"
#include "../server.hpp"
namespace server
{
    const int Genetics::MUTATION_COUNT = 10;

    void Genetics::makeChild(common::Creature *mother, common::Creature *father)
    {
        server::Genotype mother_genotype (mother);
        server::Genotype father_genotype (father);

        server::Genotype child_genotype (mother_genotype, father_genotype);
        for(int i=0; i<Genetics::MUTATION_COUNT; ++i)
        {
            child_genotype.mutate();
        }

        child_genotype.putToMap(mother->getX(), mother->getY(), server::Server::localMap);
    }

} // namespace server
