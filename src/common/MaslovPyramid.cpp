#include "MaslovPyramid.hpp"
#include <iostream>
#include <algorithm>

common::MaslovPyramid::MaslovPyramid(int hunting_or_running, int drinking, int sleeping, int procreating):
    hunting_or_running_(hunting_or_running),
    drinking_(drinking),
    sleeping_(sleeping),
    procreating_(procreating)
{
    checkData();
}


/**
 * @brief
 * Sprawdza, czy 4 pola sa dobrze ustawione, tj. czy sa permutacja liczb 1,2,3,4
 *
 * @TODO uzyj mnie, najlepiej w jakichs testach modulowych
 */
void common::MaslovPyramid::checkData()
{
    int arr[4] = {hunting_or_running_, drinking_, sleeping_, procreating_};
    std::sort(arr, arr+4);
    for(int i=0;i<4;++i)
    {
        if(arr[i] != i+1)
        {
            std::cerr << "Maslov's Pyramid set incorrectly" << std::endl;
            abort();
        }
    }
}


int common::MaslovPyramid::getHuntingOrRunningPriority()
{
    return hunting_or_running_;
}

int common::MaslovPyramid::getDrinkingPriority()
{
    return drinking_;
}

int common::MaslovPyramid::getSleepingPriority()
{
    return sleeping_;
}

int common::MaslovPyramid::getProcreatingPriority()
{
    return procreating_;
}
