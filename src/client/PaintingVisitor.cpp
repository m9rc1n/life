#include "PaintingVisitor.hpp"

int temp_counter = 0;

client::PaintingVisitor::PaintingVisitor(QImage *image) :
    image(image)
{

}

void client::PaintingVisitor::visit(common::Map &)
{
    long colorMap = 0xDDFFDD;
    image->fill(colorMap);
}

// pozwoliłem sobie, dla sprawdzenia jak działa zabijanie...
void client::PaintingVisitor::drawDeadCreature(common::Creature &obj)
{
    int x = obj.getX()*10;
    int y = obj.getY()*10;

    long color = 7777777;

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

void client::PaintingVisitor::visit(common::Predator &obj)
{
    if(obj.isDead())
    {
        drawDeadCreature(obj);
        return;
    }

    int x = obj.getX()*10;
    int y = obj.getY()*10;

    if (x < 0 || y < 0)
        return;

    long colorDarkPredator = 555555;
    long colorLightPredator = 7777777;

/// draw Predator ////////////////////////////////////////

    if((x+y)%2 == 0 )
    {
        image->setPixel (QPoint (x+0, y+0), colorLightPredator);
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

    long colorAgeLow = 0xFF0000;
    long colorAgeHigh = 0x0000FF;
    long colorEnergyHigh = 0x0000FF;
    long colorEnergyLow = 0xFF0000;
    long colorRepletionLow = 0xFF0000;
    long colorRepletionHigh = 0x0000FF;
    long colorHydrationLow = 0xFF0000;
    long colorHydrationHigh = 0x0000FF;

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
/// end Stats ////////////////////////////////////////////

}

void client::PaintingVisitor::visit(common::Herbivore &obj)
{
    if(obj.isDead())
    {
       drawDeadCreature(obj);
       return;
    }
    int x = obj.getX()*10;
    int y = obj.getY()*10;

    if (x < 0 || y < 0)
        return;

    long colorDarkHerb = 0x0;
    long colorLightHerb = 0xFFFFFF;

/// draw Herbivore ///////////////////////////////////////

    if((x+y)%2 == 0 )
    {
        image->setPixel (QPoint (x+2, y+0), colorDarkHerb);
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

    long colorAgeLow = 0xFF0000;
    long colorAgeHigh = 0x0000FF;
    long colorEnergyHigh = 0x0000FF;
    long colorEnergyLow = 0xFF0000;
    long colorRepletionLow = 0xFF0000;
    long colorRepletionHigh = 0x0000FF;
    long colorHydrationLow = 0xFF0000;
    long colorHydrationHigh = 0x0000FF;

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
/// end Stats ////////////////////////////////////////////

}

void client::PaintingVisitor::visit(common::Waterhole &obj)
{
    int x = obj.getX()*10;
    int y = obj.getY()*10;

    long colorLightWave = 0x0011FF;
    long colorDarkWave = 0x0000FF;

/// draw Waterhole ///////////////////////////////////////

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

/// end Waterhole ////////////////////////////////////////

}

void client::PaintingVisitor::visit(common::Lair &obj)
{
    int x = obj.getX()*10;
    int y = obj.getY()*10;

    long colorUpLair = 555555;
    long colorDownLair = 0x111111;

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

    long colorUpTree = 555555;
    long colorDownTree = 7777777;

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
