#include "StatisticsVisitor.hpp"
#include "../common/Predator.hpp"
#include "../common/Herbivore.hpp"

client::StatisticsVisitor::StatisticsVisitor(Statistics *stat) :
    stat(stat)
{
    stat->populationHerbivores = 0;
    stat->populationPredators = 0;
    stat->populationProcreating = 0;
    stat->populationSleeping = 0;

    stat->deadHerbivores = 0;
    stat->deadPredators = 0;

    stat->averageAgeHerbivores = 0;
    stat->averageEnergyHerbivores = 0;
    stat->averageFecundityHerbivores = 0;
    stat->averageHydrationHerbivores = 0;

    stat->averageMaxAgeHerbivores = 0;
    stat->averageMaxEnergyHerbivores = 0;
    stat->averageMaxHydrationHerbivores = 0;
    stat->averageMaxRepletionHerbivores = 0;

    stat->averageRepletionHerbivores = 0;
    stat->averageRadiusHerbivores = 0;
    stat->averageSpeedHerbivores = 0;
    stat->averageAngleHerbivores = 0;

    stat->averageAgePredators = 0;
    stat->averageEnergyPredators = 0;
    stat->averageFecundityPredators = 0;
    stat->averageHydrationPredators = 0;

    stat->averageMaxAgePredators = 0;
    stat->averageMaxEnergyPredators = 0;
    stat->averageMaxHydrationPredators = 0;
    stat->averageMaxRepletionPredators = 0;

    stat->averageRepletionPredators = 0;
    stat->averageRadiusPredators = 0;
    stat->averageSpeedPredators = 0;
    stat->averageAnglePredators = 0;

    stat->averageDieAgeHerbivores = 0;
    stat->averageDieAgePredators = 0;
}

void client::StatisticsVisitor::visit(common::Map &)
{

}


void client::StatisticsVisitor::visit(common::Predator &predator)
{
    if(!predator.isDead()) // martwych nie liczymy
    {
        (*stat).populationPredators++;
        (*stat).averageAgePredators += predator.age_;
        (*stat).averageAnglePredators += predator.angle_;
        (*stat).averageEnergyPredators += predator.energy_;
        (*stat).averageFecundityPredators += predator.fecundity_;
        (*stat).averageHydrationPredators += predator.hydration_;
        (*stat).averageRadiusPredators += predator.radius_;
        (*stat).averageSpeedPredators += predator.hydration_;
        (*stat).averageRepletionPredators += predator.repletion_;
        (*stat).averageMaxEnergyPredators += predator.max_energy_;
        (*stat).averageMaxHydrationPredators += predator.max_hydration_;
        (*stat).averageMaxRepletionPredators += predator.max_repletion_;
        (*stat).averageMaxAgePredators += predator.max_age_;
    }
    else
    {
        (*stat).averageDieAgePredators += predator.age_;
        (*stat).deadPredators++;
        return;
    }

    if(predator.is_procreating_)
    {
        (*stat).populationProcreating++;
    }

    if(predator.is_sleeping_)
    {
        (*stat).populationSleeping++;
    }
}

void client::StatisticsVisitor::visit(common::Herbivore &herbivore)
{
    if(!herbivore.isDead()) // martwych nie liczymy
    {
        (*stat).populationHerbivores++;
        (*stat).averageAgeHerbivores += herbivore.age_;
        (*stat).averageAngleHerbivores += herbivore.angle_;
        (*stat).averageEnergyHerbivores += herbivore.energy_;
        (*stat).averageFecundityHerbivores += herbivore.fecundity_;
        (*stat).averageHydrationHerbivores += herbivore.hydration_;
        (*stat).averageRadiusHerbivores += herbivore.radius_;
        (*stat).averageSpeedHerbivores += herbivore.hydration_;
        (*stat).averageRepletionHerbivores += herbivore.repletion_;
        (*stat).averageMaxEnergyHerbivores += herbivore.max_energy_;
        (*stat).averageMaxHydrationHerbivores += herbivore.max_hydration_;
        (*stat).averageMaxRepletionHerbivores += herbivore.max_repletion_;
        (*stat).averageMaxAgeHerbivores += herbivore.max_age_;
    }
    else
    {
        (*stat).averageDieAgeHerbivores += herbivore.age_;
        (*stat).deadHerbivores++;
        return;
    }

    if(herbivore.is_procreating_)
    {
        (*stat).populationProcreating++;
    }

    if(herbivore.is_sleeping_)
    {
        (*stat).populationSleeping++;
    }
}

void client::StatisticsVisitor::visit(common::Waterhole &)
{

}

void client::StatisticsVisitor::visit(common::Lair &)
{

}

void client::StatisticsVisitor::visit(common::Tree &)
{

}

