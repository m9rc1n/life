#include "StatisticsSumVisitor.hpp"
#include "../common/Predator.hpp"
#include "../common/Herbivore.hpp"

client::StatisticsSumVisitor::StatisticsSumVisitor(Statistics *stat) :
    stat(stat)
{
    stat->populationHerbivores = 0;
    stat->populationPredators = 0;
    stat->populationProcreating = 0;
    stat->populationSleeping = 0;
    stat->deadHerbivores = 0;
    stat->deadPredators = 0;
}

void client::StatisticsSumVisitor::visit(common::Map &)
{

}


void client::StatisticsSumVisitor::visit(common::Predator &predator)
{
    if(!predator.isDead()) // martwych nie liczymy
    {
        (*stat).populationPredators++;
    } else
    {
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

void client::StatisticsSumVisitor::visit(common::Herbivore &herbivore)
{
    if(!herbivore.isDead())
    {
        (*stat).populationHerbivores++;
    }
    else
    {
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

void client::StatisticsSumVisitor::visit(common::Waterhole &)
{

}

void client::StatisticsSumVisitor::visit(common::Lair &)
{

}

void client::StatisticsSumVisitor::visit(common::Tree &)
{

}

