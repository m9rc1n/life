#include "PaintingVisitor.hpp"

int temp_counter = 0;

client::PaintingVisitor::PaintingVisitor(QImage *image, bool showCreatureParametres) :
    image(image),
    showCreatureParametres(showCreatureParametres)
{
    config = common::Config::getInstance();
}

void client::PaintingVisitor::visit(common::Map &)
{
    QRgb colorMap = qRgb(180, 200, 180);
    image->fill(colorMap);
}

// pozwoliłem sobie, dla sprawdzenia jak działa zabijanie...
void client::PaintingVisitor::drawDeadCreature(common::Creature &obj)
{
    int x = obj.getX()*10;
    int y = obj.getY()*10;

    QRgb color = qRgb(40, 0, 0);

    image->setPixel (QPoint (x+0, y+2), color);
    image->setPixel (QPoint (x+1, y+2), color);
    image->setPixel (QPoint (x+2, y+2), color);
    image->setPixel (QPoint (x+3, y+2), color);
    image->setPixel (QPoint (x+4, y+2), color);

    image->setPixel (QPoint (x+2, y+0), color);
    image->setPixel (QPoint (x+2, y+1), color);
    image->setPixel (QPoint (x+2, y+2), color);
    image->setPixel (QPoint (x+2, y+3), color);
    image->setPixel (QPoint (x+2, y+4), color);
    image->setPixel (QPoint (x+2, y+5), color);
}

void client::PaintingVisitor::drawSleepingCreature(common::Creature &obj)
{
    int x = obj.getX()*10;
    int y = obj.getY()*10;

    QRgb color = qRgb(0, 0, 100);

    image->setPixel (QPoint (x+0, y+0), color);
    image->setPixel (QPoint (x+1, y+0), color);
    image->setPixel (QPoint (x+2, y+0), color);
    image->setPixel (QPoint (x+3, y+0), color);
    image->setPixel (QPoint (x+2, y+1), color);
    image->setPixel (QPoint (x+1, y+2), color);
    image->setPixel (QPoint (x+0, y+3), color);
    image->setPixel (QPoint (x+1, y+3), color);
    image->setPixel (QPoint (x+2, y+3), color);
    image->setPixel (QPoint (x+3, y+3), color);

}

void client::PaintingVisitor::drawProcreatingCreature(common::Creature &obj)
{
    int x = obj.getX()*10;
    int y = obj.getY()*10;

    QRgb color = qRgb(255, 0, 0);

    image->setPixel (QPoint (x+1, y+0), color);
    image->setPixel (QPoint (x+3, y+0), color);

    image->setPixel (QPoint (x+0, y+1), color);
    image->setPixel (QPoint (x+1, y+1), color);
    image->setPixel (QPoint (x+2, y+1), color);
    image->setPixel (QPoint (x+3, y+1), color);
    image->setPixel (QPoint (x+4, y+1), color);

    image->setPixel (QPoint (x+1, y+2), color);
    image->setPixel (QPoint (x+2, y+2), color);
    image->setPixel (QPoint (x+3, y+2), color);

    image->setPixel (QPoint (x+2, y+3), color);

}

void client::PaintingVisitor::visit(common::Predator &obj)
{
    if(obj.isDead())
    {
        drawDeadCreature(obj);
        return;
    }
    else
    if(obj.isSleeping())
    {
        drawSleepingCreature(obj);
        return;
    }
    else
    if(obj.isProcreating())
    {
        drawProcreatingCreature(obj);
        return;
    }


    int x = obj.getX()*10;
    int y = obj.getY()*10;

    if (x < 0 || y < 0)
        return;

    QRgb colorDarkPredator;
    QRgb colorLightPredator;

    if(obj.is_male_)
    {
        colorDarkPredator = 555555;
        colorLightPredator = 7777777;
    } else
    {
        colorLightPredator = 555555;
        colorDarkPredator = 7777777;
    }


/// draw Predator ////////////////////////////////////////

    if((x+y)%2 == 0 )
    {
        image->setPixel (QPoint (x+0, y+0), colorDarkPredator);
        image->setPixel (QPoint (x+1, y+0), colorDarkPredator);
        image->setPixel (QPoint (x+3, y+0), colorDarkPredator);
        image->setPixel (QPoint (x+4, y+0), colorLightPredator);
        image->setPixel (QPoint (x+5, y+0), colorDarkPredator);

        image->setPixel (QPoint (x+1, y+1), colorLightPredator);
        image->setPixel (QPoint (x+3, y+1), colorLightPredator);
        image->setPixel (QPoint (x+5, y+1), colorLightPredator);
        image->setPixel (QPoint (x+7, y+1), colorLightPredator);
        image->setPixel (QPoint (x+8, y+1), colorDarkPredator);
        image->setPixel (QPoint (x+9, y+1), colorLightPredator);

        image->setPixel (QPoint (x+1, y+2), colorDarkPredator);
        image->setPixel (QPoint (x+3, y+2), colorDarkPredator);
        image->setPixel (QPoint (x+5, y+2), colorDarkPredator);
        image->setPixel (QPoint (x+7, y+2), colorLightPredator);
        image->setPixel (QPoint (x+8, y+2), colorLightPredator);
        image->setPixel (QPoint (x+9, y+2), colorLightPredator);

        image->setPixel (QPoint (x+1, y+3), colorLightPredator);
        image->setPixel (QPoint (x+3, y+3), colorLightPredator);
        image->setPixel (QPoint (x+5, y+3), colorLightPredator);
        image->setPixel (QPoint (x+7, y+3), colorLightPredator);

        image->setPixel (QPoint (x+1, y+4), colorDarkPredator);
        image->setPixel (QPoint (x+2, y+4), colorLightPredator);
        image->setPixel (QPoint (x+3, y+4), colorDarkPredator);
        image->setPixel (QPoint (x+5, y+4), colorDarkPredator);
        image->setPixel (QPoint (x+6, y+4), colorLightPredator);
        image->setPixel (QPoint (x+7, y+4), colorDarkPredator);
    }
    else
    {
        image->setPixel (QPoint (x+7, y+0), colorLightPredator);
        image->setPixel (QPoint (x+8, y+0), colorDarkPredator);
        image->setPixel (QPoint (x+9, y+0), colorLightPredator);

        image->setPixel (QPoint (x+0, y+1), colorLightPredator);
        image->setPixel (QPoint (x+1, y+1), colorDarkPredator);
        image->setPixel (QPoint (x+3, y+1), colorDarkPredator);
        image->setPixel (QPoint (x+4, y+1), colorLightPredator);
        image->setPixel (QPoint (x+5, y+1), colorDarkPredator);
        image->setPixel (QPoint (x+7, y+1), colorLightPredator);
        image->setPixel (QPoint (x+8, y+1), colorLightPredator);
        image->setPixel (QPoint (x+9, y+1), colorLightPredator);

        image->setPixel (QPoint (x+1, y+2), colorDarkPredator);
        image->setPixel (QPoint (x+3, y+2), colorDarkPredator);
        image->setPixel (QPoint (x+5, y+2), colorDarkPredator);
        image->setPixel (QPoint (x+7, y+2), colorLightPredator);

        image->setPixel (QPoint (x+1, y+3), colorLightPredator);
        image->setPixel (QPoint (x+3, y+3), colorLightPredator);
        image->setPixel (QPoint (x+5, y+3), colorLightPredator);
        image->setPixel (QPoint (x+2, y+3), colorLightPredator);
        image->setPixel (QPoint (x+6, y+3), colorDarkPredator);
        image->setPixel (QPoint (x+7, y+3), colorLightPredator);
    }

/// end Predator /////////////////////////////////////////

    int ageIndex = (obj.age_ * 10)/obj.max_age_;
    int energyIndex = (obj.energy_ * 10)/obj.max_energy_;
    int repletionIndex = (obj.repletion_ * 10)/obj.max_repletion_;
    int hydrationIndex = (obj.hydration_ * 10)/obj.max_hydration_;
    int procreateIndex = obj.getTimeToProcreate() / 10;

    QRgb colorAgeLow = 0xFF0000;
    QRgb colorAgeHigh = 0x0000FF;
    QRgb colorEnergyHigh = 0x0000FF;
    QRgb colorEnergyLow = 0xFF0000;
    QRgb colorRepletionLow = 0xFF0000;
    QRgb colorRepletionHigh = 0x0000FF;
    QRgb colorHydrationLow = 0xFF0000;
    QRgb colorHydrationHigh = 0x0000FF;
    QRgb colorTimeToProcreateLow =  qRgb(200, 2, 2);

/// draw Stats ///////////////////////////////////////////

    for( int i=0; i<ageIndex; i++)
    {
        if(ageIndex < 5)
        {
            image->setPixel (QPoint (x+i, y+6), colorAgeLow);
        }
        else
        {
            image->setPixel (QPoint (x+i, y+6), colorAgeHigh);
        }
    }

    for( int i=0; i<energyIndex; i++)
    {
        if(energyIndex < 5)
        {
            image->setPixel (QPoint (x+i, y+8), colorEnergyLow);
        }
        else
        {
            image->setPixel (QPoint (x+i, y+8), colorEnergyHigh);
        }
    }

    for( int i=0; i<repletionIndex; i++)
    {
        if(repletionIndex < 5)
        {
            image->setPixel (QPoint (x+i, y+10), colorRepletionLow);
        }
        else
        {
            image->setPixel (QPoint (x+i, y+10), colorRepletionHigh);
        }
    }

    for( int i=0; i<hydrationIndex; i++)
    {
        if(hydrationIndex < 5)
        {
            image->setPixel (QPoint (x+i, y+12), colorHydrationLow);
        }
        else
        {
            image->setPixel (QPoint (x+i, y+12), colorHydrationHigh);
        }
    }

    for( int i=0; i<procreateIndex; i++)
    {
        image->setPixel (QPoint (x+i, y+14), colorTimeToProcreateLow);
    }

    if(showCreatureParametres)
    {

        float maxIndex = config->getParameterSum();

        int speedIndex = round((obj.getSpeed() * 20)/maxIndex);
        int radiusIndex = round((obj.getRadius() * 20)/maxIndex);
        int angleIndex = round((obj.getAngle() * 20)/maxIndex);
        int fecundityIndex = round((obj.getFecundity() * 20)/maxIndex);
        int repletionMaxIndex = round((obj.getMaxRepletion() * 20)/maxIndex);
        int hydrationMaxIndex = round((obj.getMaxHydration() * 20)/maxIndex);
        int ageMaxIndex = round((obj.getMaxAge() * 20)/maxIndex);
        int energyMaxIndex = round((obj.getMaxEnergy() * 20)/maxIndex);

        QRgb colorSpeed = qRgb(0, 0, 0);
        QRgb colorRadius = qRgb(0, 255, 0);
        QRgb colorAngle = qRgb(0, 0, 255);
        QRgb colorFecundity = qRgb(255, 0, 0);
        QRgb colorRepletion = qRgb(255, 255, 0);
        QRgb colorHydration = qRgb(0, 255, 255);
        QRgb colorAge = qRgb(255, 0, 255);
        QRgb colorEnergy = qRgb(255, 255, 255);
        int sumPrev = 0;
        int sumCon = speedIndex;

        for (int i=sumPrev; i<sumCon; i++)
        {
            if (i<10)
            {
                image->setPixel (QPoint (x+i, y+16), colorSpeed);
            }
            else
            {
                image->setPixel (QPoint (x+(i%10), y+17), colorSpeed);
            }
        }

        sumPrev = sumCon;
        sumCon += radiusIndex;

        for (int i=sumPrev; i<sumCon; i++)
        {
            if (i<10)
            {
                image->setPixel (QPoint (x+i, y+16), colorRadius);
            }
            else
            {
                image->setPixel (QPoint (x+(i%10), y+17), colorRadius);
            }
        }

        sumPrev = sumCon;
        sumCon += angleIndex;

        for (int i=sumPrev; i<sumCon; i++)
        {
            if (i<10)
            {
                image->setPixel (QPoint (x+i, y+16), colorAngle);
            }
            else
            {
                image->setPixel (QPoint (x+(i%10), y+17), colorAngle);
            }
        }

        sumPrev = sumCon;
        sumCon += fecundityIndex;

        for (int i=sumPrev; i<sumCon; i++)
        {
            if (i<10)
            {
                image->setPixel (QPoint (x+i, y+16), colorFecundity);
            }
            else
            {
                image->setPixel (QPoint (x+(i%10), y+17), colorFecundity);
            }
        }

        sumPrev = sumCon;
        sumCon += repletionMaxIndex;

        for (int i=sumPrev; i<sumCon; i++)
        {
            if (i<10)
            {
                image->setPixel (QPoint (x+i, y+16), colorRepletion);
            }
            else
            {
                image->setPixel (QPoint (x+(i%10), y+17), colorRepletion);
            }
        }

        sumPrev = sumCon;
        sumCon += hydrationMaxIndex;

        for (int i=sumPrev; i<sumCon; i++)
        {
            if (i<10)
            {
                image->setPixel (QPoint (x+i, y+16), colorHydration);
            }
            else
            {
                image->setPixel (QPoint (x+(i%10), y+17), colorHydration);
            }
        }

        sumPrev = sumCon;
        sumCon += ageMaxIndex;

        for (int i=sumPrev; i<sumCon; i++)
        {
            if (i<10)
            {
                image->setPixel (QPoint (x+i, y+16), colorAge);
            }
            else
            {
                image->setPixel (QPoint (x+(i%10), y+17), colorAge);
            }
        }

        sumPrev = sumCon;
        sumCon += energyMaxIndex;

        for (int i=sumPrev; i<sumCon; i++)
        {
            if (i<10)
            {
                image->setPixel (QPoint (x+i, y+16), colorEnergy);
            }
            else
            {
                image->setPixel (QPoint (x+(i%10), y+17), colorEnergy);
            }
        }
    }
/// end Stats ////////////////////////////////////////////

}

void client::PaintingVisitor::visit(common::Herbivore &obj)
{
    if(obj.isDead())
    {
       drawDeadCreature(obj);
       return;
    }
    else
    if(obj.isSleeping())
    {
        drawSleepingCreature(obj);
        return;
    }
    else
    if(obj.isProcreating())
    {
        drawProcreatingCreature(obj);
        return;
    }

    int x = obj.getX()*10;
    int y = obj.getY()*10;

    if (x < 0 || y < 0)
        return;

    QRgb colorDarkHerb;
    QRgb colorLightHerb;

    if(obj.is_male_)
    {
        colorDarkHerb = qRgb(255, 255, 255);
        colorLightHerb = qRgb(0, 0, 0);
    }
    else
    {
        colorDarkHerb = qRgb(0, 0, 0);
        colorLightHerb = qRgb(255, 255, 255);
    }

/// draw Herbivore ///////////////////////////////////////

    if((x+y)%2 == 0 )
    {
        image->setPixel (QPoint (x+2, y+0), colorLightHerb);
        image->setPixel (QPoint (x+1, y+1), colorLightHerb);
        image->setPixel (QPoint (x+2, y+1), colorLightHerb);

        image->setPixel (QPoint (x+3, y+2), colorLightHerb);
        image->setPixel (QPoint (x+4, y+2), colorDarkHerb);
        image->setPixel (QPoint (x+5, y+2), colorLightHerb);
        image->setPixel (QPoint (x+6, y+2), colorDarkHerb);
        image->setPixel (QPoint (x+7, y+2), colorLightHerb);

        image->setPixel (QPoint (x+3, y+3), colorLightHerb);
        image->setPixel (QPoint (x+4, y+3), colorLightHerb);
        image->setPixel (QPoint (x+5, y+3), colorDarkHerb);
        image->setPixel (QPoint (x+6, y+3), colorLightHerb);
        image->setPixel (QPoint (x+8, y+3), colorLightHerb);

        image->setPixel (QPoint (x+3, y+4), colorLightHerb);
        image->setPixel (QPoint (x+6, y+4), colorLightHerb);
    }
    else
    {
        image->setPixel (QPoint (x+2, y+1), colorLightHerb);

        image->setPixel (QPoint (x+1, y+2), colorLightHerb);
        image->setPixel (QPoint (x+2, y+2), colorLightHerb);

        image->setPixel (QPoint (x+3, y+2), colorLightHerb);
        image->setPixel (QPoint (x+4, y+2), colorDarkHerb);
        image->setPixel (QPoint (x+5, y+2), colorLightHerb);
        image->setPixel (QPoint (x+6, y+2), colorDarkHerb);
        image->setPixel (QPoint (x+7, y+2), colorLightHerb);

        image->setPixel (QPoint (x+3, y+3), colorLightHerb);
        image->setPixel (QPoint (x+4, y+3), colorLightHerb);
        image->setPixel (QPoint (x+5, y+3), colorDarkHerb);
        image->setPixel (QPoint (x+6, y+3), colorLightHerb);
        image->setPixel (QPoint (x+8, y+1), colorLightHerb);

        image->setPixel (QPoint (x+4, y+4), colorLightHerb);
        image->setPixel (QPoint (x+7, y+4), colorLightHerb);
    }

/// end Herbivore ////////////////////////////////////////

    int ageIndex = (obj.age_ * 10)/obj.max_age_;
    int energyIndex = (obj.energy_ * 10)/obj.max_energy_;
    int repletionIndex = (obj.repletion_ * 10)/obj.max_repletion_;
    int hydrationIndex = (obj.hydration_ * 10)/obj.max_hydration_;
    int procreateIndex = obj.getTimeToProcreate() / 10;

    QRgb colorAgeLow = 0xFF0000;
    QRgb colorAgeHigh = 0x0000FF;
    QRgb colorEnergyHigh = 0x0000FF;
    QRgb colorEnergyLow = 0xFF0000;
    QRgb colorRepletionLow = 0xFF0000;
    QRgb colorRepletionHigh = 0x0000FF;
    QRgb colorHydrationLow = 0xFF0000;
    QRgb colorHydrationHigh = 0x0000FF;
    QRgb colorTimeToProcreateLow =  qRgb(200, 2, 2);

/// draw Stats ///////////////////////////////////////////

    for( int i=0; i<ageIndex; i++)
    {
        if(ageIndex < 5)
        {
            image->setPixel (QPoint (x+i, y+6), colorAgeLow);
        }
        else
        {
            image->setPixel (QPoint (x+i, y+6), colorAgeHigh);
        }
    }

    for( int i=0; i<energyIndex; i++)
    {
        if(energyIndex < 5)
        {
            image->setPixel (QPoint (x+i, y+8), colorEnergyLow);
        }
        else
        {
            image->setPixel (QPoint (x+i, y+8), colorEnergyHigh);
        }
    }

    for( int i=0; i<repletionIndex; i++)
    {
        if(repletionIndex < 5)
        {
            image->setPixel (QPoint (x+i, y+10), colorRepletionLow);
        }
        else
        {
            image->setPixel (QPoint (x+i, y+10), colorRepletionHigh);
        }
    }

    for( int i=0; i<hydrationIndex; i++)
    {
        if(hydrationIndex < 5)
        {
            image->setPixel (QPoint (x+i, y+12), colorHydrationLow);
        }
        else
        {
            image->setPixel (QPoint (x+i, y+12), colorHydrationHigh);
        }
    }

    for( int i=0; i<procreateIndex; i++)
    {
        image->setPixel (QPoint (x+i, y+14), colorTimeToProcreateLow);
    }

    if(showCreatureParametres)
    {

        float maxIndex = config->getParameterSum();

        int speedIndex = round((obj.getSpeed() * 20)/maxIndex);
        int radiusIndex = round((obj.getRadius() * 20)/maxIndex);
        int angleIndex = round((obj.getAngle() * 20)/maxIndex);
        int fecundityIndex = round((obj.getFecundity() * 20)/maxIndex);
        int repletionMaxIndex = round((obj.getMaxRepletion() * 20)/maxIndex);
        int hydrationMaxIndex = round((obj.getMaxHydration() * 20)/maxIndex);
        int ageMaxIndex = round((obj.getMaxAge() * 20)/maxIndex);
        int energyMaxIndex = round((obj.getMaxEnergy() * 20)/maxIndex);

        QRgb colorSpeed = qRgb(0, 0, 0);
        QRgb colorRadius = qRgb(0, 255, 0);
        QRgb colorAngle = qRgb(0, 0, 255);
        QRgb colorFecundity = qRgb(255, 0, 0);
        QRgb colorRepletion = qRgb(255, 255, 0);
        QRgb colorHydration = qRgb(0, 255, 255);
        QRgb colorAge = qRgb(255, 0, 255);
        QRgb colorEnergy = qRgb(255, 255, 255);

        int sumPrev = 0;
        int sumCon = speedIndex;

        for (int i=sumPrev; i<sumCon; i++)
        {
            if (i<10)
            {
                image->setPixel (QPoint (x+i, y+16), colorSpeed);
            }
            else
            {
                image->setPixel (QPoint (x+(i%10), y+17), colorSpeed);
            }
        }

        sumPrev = sumCon;
        sumCon += radiusIndex;

        for (int i=sumPrev; i<sumCon; i++)
        {
            if (i<10)
            {
                image->setPixel (QPoint (x+i, y+16), colorRadius);
            }
            else
            {
                image->setPixel (QPoint (x+(i%10), y+17), colorRadius);
            }
        }

        sumPrev = sumCon;
        sumCon += angleIndex;

        for (int i=sumPrev; i<sumCon; i++)
        {
            if (i<10)
            {
                image->setPixel (QPoint (x+i, y+16), colorAngle);
            }
            else
            {
                image->setPixel (QPoint (x+(i%10), y+17), colorAngle);
            }
        }

        sumPrev = sumCon;
        sumCon += fecundityIndex;

        for (int i=sumPrev; i<sumCon; i++)
        {
            if (i<10)
            {
                image->setPixel (QPoint (x+i, y+16), colorFecundity);
            }
            else
            {
                image->setPixel (QPoint (x+(i%10), y+17), colorFecundity);
            }
        }

        sumPrev = sumCon;
        sumCon += repletionMaxIndex;

        for (int i=sumPrev; i<sumCon; i++)
        {
            if (i<10)
            {
                image->setPixel (QPoint (x+i, y+16), colorRepletion);
            }
            else
            {
                image->setPixel (QPoint (x+(i%10), y+17), colorRepletion);
            }
        }

        sumPrev = sumCon;
        sumCon += hydrationMaxIndex;

        for (int i=sumPrev; i<sumCon; i++)
        {
            if (i<10)
            {
                image->setPixel (QPoint (x+i, y+16), colorHydration);
            }
            else
            {
                image->setPixel (QPoint (x+(i%10), y+17), colorHydration);
            }
        }

        sumPrev = sumCon;
        sumCon += ageMaxIndex;

        for (int i=sumPrev; i<sumCon; i++)
        {
            if (i<10)
            {
                image->setPixel (QPoint (x+i, y+16), colorAge);
            }
            else
            {
                image->setPixel (QPoint (x+(i%10), y+17), colorAge);
            }
        }

        sumPrev = sumCon;
        sumCon += energyMaxIndex;

        for (int i=sumPrev; i<sumCon; i++)
        {
            if (i<10)
            {
                image->setPixel (QPoint (x+i, y+16), colorEnergy);
            }
            else
            {
                image->setPixel (QPoint (x+(i%10), y+17), colorEnergy);
            }
        }
    }
/// end Stats ////////////////////////////////////////////

}

void client::PaintingVisitor::visit(common::Waterhole &obj)
{
    int x = obj.getX()*10;
    int y = obj.getY()*10;

    QRgb colorUpWater = qRgb(150, 150, 200);
    QRgb colorDownWater = qRgb( 100, 100, 50);

/// draw Waterhole ///////////////////////////////////////


    image->setPixel (QPoint (x+3, y+1), colorUpWater);
    image->setPixel (QPoint (x+4, y+1), colorUpWater);
    image->setPixel (QPoint (x+5, y+1), colorUpWater);
    image->setPixel (QPoint (x+6, y+1), colorUpWater);

    image->setPixel (QPoint (x+2, y+2), colorUpWater);
    image->setPixel (QPoint (x+4, y+2), colorUpWater);
    image->setPixel (QPoint (x+5, y+2), colorUpWater);
    image->setPixel (QPoint (x+7, y+2), colorUpWater);

    image->setPixel (QPoint (x+1, y+3), colorUpWater);
    image->setPixel (QPoint (x+3, y+3), colorUpWater);
    image->setPixel (QPoint (x+4, y+3), colorUpWater);
    image->setPixel (QPoint (x+5, y+3), colorUpWater);
    image->setPixel (QPoint (x+6, y+3), colorUpWater);
    image->setPixel (QPoint (x+8, y+3), colorUpWater);

    image->setPixel (QPoint (x+2, y+4), colorUpWater);
    image->setPixel (QPoint (x+3, y+4), colorUpWater);
    image->setPixel (QPoint (x+4, y+4), colorUpWater);
    image->setPixel (QPoint (x+5, y+4), colorUpWater);
    image->setPixel (QPoint (x+6, y+4), colorUpWater);
    image->setPixel (QPoint (x+7, y+4), colorUpWater);

    image->setPixel (QPoint (x+1, y+5), colorUpWater);
    image->setPixel (QPoint (x+3, y+5), colorUpWater);
    image->setPixel (QPoint (x+4, y+5), colorUpWater);
    image->setPixel (QPoint (x+5, y+5), colorUpWater);
    image->setPixel (QPoint (x+6, y+5), colorUpWater);
    image->setPixel (QPoint (x+8, y+5), colorUpWater);

    image->setPixel (QPoint (x+2, y+6), colorUpWater);
    image->setPixel (QPoint (x+4, y+6), colorUpWater);
    image->setPixel (QPoint (x+5, y+6), colorUpWater);
    image->setPixel (QPoint (x+7, y+6), colorUpWater);

    image->setPixel (QPoint (x+4, y+7), colorDownWater);
    image->setPixel (QPoint (x+5, y+7), colorDownWater);

    image->setPixel (QPoint (x+4, y+8), colorDownWater);
    image->setPixel (QPoint (x+5, y+8), colorDownWater);

    image->setPixel (QPoint (x+3, y+9), colorDownWater);
    image->setPixel (QPoint (x+4, y+9), colorDownWater);
    image->setPixel (QPoint (x+5, y+9), colorDownWater);
    image->setPixel (QPoint (x+6, y+9), colorDownWater);

    /*
    image->setPixel (QPoint (x+3, y+2), colorLightWave);
    image->setPixel (QPoint (x+4, y+2), colorLightWave);
    image->setPixel (QPoint (x+5, y+2), colorDarkWave);
    image->setPixel (QPoint (x+6, y+2), colorDarkWave);

    image->setPixel (QPoint (x+2, y+3), colorLightWave);
    image->setPixel (QPoint (x+5, y+3), colorLightWave);
    image->setPixel (QPoint (x+6, y+3), colorDarkWave);
    image->setPixel (QPoint (x+7, y+3), colorDarkWave);

    image->setPixel (QPoint (x+6, y+4), colorLightWave);
    image->setPixel (QPoint (x+7, y+4), colorDarkWave);
    image->setPixel (QPoint (x+8, y+4), colorDarkWave);

    image->setPixel (QPoint (x+6, y+5), colorLightWave);
    image->setPixel (QPoint (x+7, y+5), colorLightWave);
    image->setPixel (QPoint (x+8, y+5), colorDarkWave);
    image->setPixel (QPoint (x+9, y+5), colorDarkWave);

    image->setPixel (QPoint (x+6, y+6), colorLightWave);
    image->setPixel (QPoint (x+7, y+6), colorDarkWave);
    image->setPixel (QPoint (x+8, y+6), colorDarkWave);
    image->setPixel (QPoint (x+9, y+6), colorDarkWave);

    image->setPixel (QPoint (x, y+7), colorLightWave);
    image->setPixel (QPoint (x+5, y+7), colorLightWave);
    image->setPixel (QPoint (x+6, y+7), colorDarkWave);
    image->setPixel (QPoint (x+7, y+7), colorDarkWave);
    image->setPixel (QPoint (x+8, y+7), colorDarkWave);
    image->setPixel (QPoint (x+9, y+7), colorDarkWave);

    image->setPixel (QPoint (x, y+8), colorDarkWave);
    image->setPixel (QPoint (x+1, y+8), colorLightWave);
    image->setPixel (QPoint (x+4, y+8), colorLightWave);
    image->setPixel (QPoint (x+5, y+8), colorDarkWave);
    image->setPixel (QPoint (x+6, y+8), colorDarkWave);
    image->setPixel (QPoint (x+7, y+8), colorDarkWave);
    image->setPixel (QPoint (x+8, y+8), colorDarkWave);
    image->setPixel (QPoint (x+9, y+8), colorDarkWave);

    image->setPixel (QPoint (x+0, y+9), colorDarkWave);
    image->setPixel (QPoint (x+1, y+9), colorDarkWave);
    image->setPixel (QPoint (x+2, y+9), colorDarkWave);
    image->setPixel (QPoint (x+3, y+9), colorDarkWave);
    image->setPixel (QPoint (x+4, y+9), colorDarkWave);
    image->setPixel (QPoint (x+5, y+9), colorDarkWave);
    image->setPixel (QPoint (x+6, y+9), colorDarkWave);
    image->setPixel (QPoint (x+7, y+9), colorDarkWave);
    image->setPixel (QPoint (x+8, y+9), colorDarkWave);
    image->setPixel (QPoint (x+9, y+9), colorDarkWave);
*/

/// end Waterhole ////////////////////////////////////////

}

void client::PaintingVisitor::visit(common::Lair &obj)
{
    int x = obj.getX()*10;
    int y = obj.getY()*10;

    QRgb colorUpLair = 555555;
    QRgb colorDownLair = 0x111111;

/// draw Lair ////////////////////////////////////////////

    image->setPixel (QPoint (x+3, y+5), colorUpLair);
    image->setPixel (QPoint (x+4, y+5), colorUpLair);
    image->setPixel (QPoint (x+5, y+5), colorUpLair);
    image->setPixel (QPoint (x+6, y+5), colorUpLair);

    image->setPixel (QPoint (x+2, y+6), colorUpLair);
    image->setPixel (QPoint (x+3, y+6), colorUpLair);
    image->setPixel (QPoint (x+4, y+6), colorUpLair);
    image->setPixel (QPoint (x+5, y+6), colorUpLair);
    image->setPixel (QPoint (x+6, y+6), colorUpLair);
    image->setPixel (QPoint (x+7, y+6), colorUpLair);

    image->setPixel (QPoint (x+1, y+7), colorUpLair);
    image->setPixel (QPoint (x+2, y+7), colorUpLair);
    image->setPixel (QPoint (x+3, y+7), colorUpLair);
    image->setPixel (QPoint (x+4, y+7), colorDownLair);
    image->setPixel (QPoint (x+5, y+7), colorDownLair);
    image->setPixel (QPoint (x+6, y+7), colorUpLair);
    image->setPixel (QPoint (x+7, y+7), colorUpLair);
    image->setPixel (QPoint (x+8, y+7), colorUpLair);

    image->setPixel (QPoint (x+0, y+8), colorUpLair);
    image->setPixel (QPoint (x+1, y+8), colorUpLair);
    image->setPixel (QPoint (x+2, y+8), colorUpLair);
    image->setPixel (QPoint (x+3, y+8), colorDownLair);
    image->setPixel (QPoint (x+4, y+8), colorDownLair);
    image->setPixel (QPoint (x+5, y+8), colorDownLair);
    image->setPixel (QPoint (x+6, y+8), colorDownLair);
    image->setPixel (QPoint (x+7, y+8), colorUpLair);
    image->setPixel (QPoint (x+8, y+8), colorUpLair);
    image->setPixel (QPoint (x+9, y+8), colorUpLair);

    image->setPixel (QPoint (x+0, y+9), colorUpLair);
    image->setPixel (QPoint (x+1, y+9), colorUpLair);
    image->setPixel (QPoint (x+2, y+9), colorDownLair);
    image->setPixel (QPoint (x+3, y+9), colorDownLair);
    image->setPixel (QPoint (x+4, y+9), colorDownLair);
    image->setPixel (QPoint (x+5, y+9), colorDownLair);
    image->setPixel (QPoint (x+6, y+9), colorDownLair);
    image->setPixel (QPoint (x+7, y+9), colorDownLair);
    image->setPixel (QPoint (x+8, y+9), colorUpLair);
    image->setPixel (QPoint (x+9, y+9), colorUpLair);

/// end Lair /////////////////////////////////////////////

}

void client::PaintingVisitor::visit(common::Tree &obj)
{
    int x = obj.getX()*10;
    int y = obj.getY()*10;

    QRgb colorUpTree = 555555;
    QRgb colorDownTree = 7777777;

/// draw Tree ////////////////////////////////////////////

    image->setPixel (QPoint (x+3, y+1), colorUpTree);
    image->setPixel (QPoint (x+4, y+1), colorUpTree);
    image->setPixel (QPoint (x+5, y+1), colorUpTree);
    image->setPixel (QPoint (x+6, y+1), colorUpTree);

    image->setPixel (QPoint (x+2, y+2), colorUpTree);
    image->setPixel (QPoint (x+4, y+2), colorUpTree);
    image->setPixel (QPoint (x+5, y+2), colorUpTree);
    image->setPixel (QPoint (x+7, y+2), colorUpTree);

    image->setPixel (QPoint (x+1, y+3), colorUpTree);
    image->setPixel (QPoint (x+3, y+3), colorUpTree);
    image->setPixel (QPoint (x+4, y+3), colorUpTree);
    image->setPixel (QPoint (x+5, y+3), colorUpTree);
    image->setPixel (QPoint (x+6, y+3), colorUpTree);
    image->setPixel (QPoint (x+8, y+3), colorUpTree);

    image->setPixel (QPoint (x+2, y+4), colorUpTree);
    image->setPixel (QPoint (x+3, y+4), colorUpTree);
    image->setPixel (QPoint (x+4, y+4), colorUpTree);
    image->setPixel (QPoint (x+5, y+4), colorUpTree);
    image->setPixel (QPoint (x+6, y+4), colorUpTree);
    image->setPixel (QPoint (x+7, y+4), colorUpTree);

    image->setPixel (QPoint (x+1, y+5), colorUpTree);
    image->setPixel (QPoint (x+3, y+5), colorUpTree);
    image->setPixel (QPoint (x+4, y+5), colorUpTree);
    image->setPixel (QPoint (x+5, y+5), colorUpTree);
    image->setPixel (QPoint (x+6, y+5), colorUpTree);
    image->setPixel (QPoint (x+8, y+5), colorUpTree);

    image->setPixel (QPoint (x+2, y+6), colorUpTree);
    image->setPixel (QPoint (x+4, y+6), colorUpTree);
    image->setPixel (QPoint (x+5, y+6), colorUpTree);
    image->setPixel (QPoint (x+7, y+6), colorUpTree);

    image->setPixel (QPoint (x+4, y+7), colorDownTree);
    image->setPixel (QPoint (x+5, y+7), colorDownTree);

    image->setPixel (QPoint (x+4, y+8), colorDownTree);
    image->setPixel (QPoint (x+5, y+8), colorDownTree);

    image->setPixel (QPoint (x+3, y+9), colorDownTree);
    image->setPixel (QPoint (x+4, y+9), colorDownTree);
    image->setPixel (QPoint (x+5, y+9), colorDownTree);
    image->setPixel (QPoint (x+6, y+9), colorDownTree);

/// end Tree /////////////////////////////////////////////

}
