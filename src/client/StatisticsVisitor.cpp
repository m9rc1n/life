#include "StatisticsVisitor.hpp"

client::StatisticsVisitor::StatisticsVisitor(Statistics *stat) :
    stat(stat)
{
    stat->populationHerbivores = 0;
    stat->populationPredators = 0;
}

void client::StatisticsVisitor::visit(common::Map &)
{

}

void client::StatisticsVisitor::visit(common::Predator &)
{
    (*stat).populationPredators++;
}

void client::StatisticsVisitor::visit(common::Herbivore &)
{
    (*stat).populationHerbivores++;
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

