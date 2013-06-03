#include "Genetics.hpp"
#include "Genotype.hpp"
namespace server
{
    const int Genetics::MUTATION_COUNT = 10;

    void Genetics::makeChild(common::Creature *mother, common::Creature *father)
    {
        server::Genotype mother_genotype (mother);
        server::Genotype father_genotype (father);

        server::Genotype child_Genotype (mother_genotype, father_genotype);
        for(int i=0; i<Genetics::MUTATION_COUNT; ++i)
        {
            child_Genotype.mutate();
        }
    }

} // namespace server
