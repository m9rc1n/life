#include "PaintingVisitor.hpp"

int temp_counter = 0;

client::PaintingVisitor::PaintingVisitor(QImage *image) :
    image(image)
{
    config = common::Config.getInstance();
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

    if(obj.is_male)
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

    int ageIndex = obj.age_/obj.max_age_ * 10;
    int energyIndex = obj.energy_/obj.max_energy_ * 10;
    int repletionIndex = obj.repletion_/obj.max_repletion_ * 10;
    int hydrationIndex = obj.hydration_/obj.max_hydration_ * 10;
    int procreateIndex = obj.getTimeToProcreate() / 10;

    int maxIndex = config->parameter_sum;

    int speedIndex = obj.getSpeed()/maxIndex;
    int radiusIndex = obj.getRadius()/maxIndex;
    int angleIndex = obj.getAngle()/maxIndex;
    int fecundityIndex = obj.getFecundity()/maxIndex;
    int repletionMaxIndex = obj.getMaxRepletion()/maxIndex;
    int hydrationMaxIndex = obj.getMaxHydration()/maxIndex;
    int ageMaxIndex = obj.getMaxAge()/maxIndex;
    int energyMaxIndex = obj.getMaxEnergy()/maxIndex;

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


    for( int i=0; i<procreateIndex; i++)
    {
        image->setPixel (QPoint (x+i, y+16), colorTimeToProcreateLow);
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

    if(obj.is_male)
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
        image->setPixel (QPoint (x+2, y+1), colorDarkHerb);

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

    int ageIndex = obj.age_/obj.max_age_ * 10;
    int energyIndex = obj.energy_/obj.max_energy_ * 10;
    int repletionIndex = obj.repletion_/obj.max_repletion_ * 10;
    int hydrationIndex = obj.hydration_/obj.max_hydration_ * 10;
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
/// end Stats ////////////////////////////////////////////

}

void client::PaintingVisitor::visit(common::Waterhole &obj)
{
    int x = obj.getX()*10;
    int y = obj.getY()*10;

    QRgb colorUpWater = 0x0011FF;
    QRgb colorDownWater = 0x0000FF;

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
