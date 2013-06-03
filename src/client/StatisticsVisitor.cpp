#include "StatisticsVisitor.hpp"
#include "../common/Predator.hpp"
#include "../common/Herbivore.hpp"

client::StatisticsVisitor::StatisticsVisitor(Statistics *stat) :
    stat(stat)
{
    stat->populationHerbivores = 0;
    stat->populationPredators = 0;
}

void client::StatisticsVisitor::visit(common::Map &)
{

}


void client::StatisticsVisitor::visit(common::Predator &predator)
{
    if(!predator.isDead()) // martwych nie liczymy
    {
        (*stat).populationPredators++;
    }
}

void client::StatisticsVisitor::visit(common::Herbivore &herbivore)
{
    if(!herbivore.isDead())
    {
        (*stat).populationHerbivores++;
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

