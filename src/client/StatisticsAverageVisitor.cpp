#include "StatisticsAverageVisitor.hpp"

client::StatisticsAverageVisitor::StatisticsAverageVisitor(Statistics *stat) :
    stat(stat)
{
    stat->averageAgeHerbivores = 0;
    stat->averageDieAgeHerbivores = 0;
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
    stat->averageDieAgePredators = 0;
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
}

void client::StatisticsAverageVisitor::visit(common::Map &){}


void client::StatisticsAverageVisitor::visit(common::Predator &obj)
{
    if(!obj.isDead()) // martwych nie liczymy
    {
        (*stat).averageAgePredators += obj.age_;
        (*stat).averageAnglePredators += obj.angle_;
        (*stat).averageEnergyPredators += obj.energy_;
        (*stat).averageFecundityPredators += obj.fecundity_;
        (*stat).averageHydrationPredators += obj.hydration_;
        (*stat).averageRadiusPredators += obj.radius_;
        (*stat).averageSpeedPredators += obj.hydration_;
        (*stat).averageRepletionPredators += obj.repletion_;
    }
    else
    {
        (*stat).averageDieAgePredators += obj.age_;
    }
}

void client::StatisticsAverageVisitor::visit(common::Herbivore &obj)
{
    if(!obj.isDead())
    {
        (*stat).averageAgeHerbivores += obj.age_;
        (*stat).averageAngleHerbivores += obj.angle_;
        (*stat).averageEnergyHerbivores += obj.energy_;
        (*stat).averageFecundityHerbivores += obj.fecundity_;
        (*stat).averageHydrationHerbivores += obj.hydration_;
        (*stat).averageRadiusHerbivores += obj.radius_;
        (*stat).averageSpeedHerbivores += obj.hydration_;
        (*stat).averageRepletionHerbivores += obj.repletion_;
    }
    else
    {
        (*stat).averageDieAgePredators += obj.age_;
    }
}

void client::StatisticsAverageVisitor::visit(common::Waterhole &)
{

}

void client::StatisticsAverageVisitor::visit(common::Lair &)
{

}

void client::StatisticsAverageVisitor::visit(common::Tree &)
{

}

