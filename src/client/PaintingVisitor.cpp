#include "PaintingVisitor.hpp"

client::PaintingVisitor::PaintingVisitor(QImage *image) :
    image(image)
{

}

void client::PaintingVisitor::visit(common::Map & obj)
{
    long colorMap = 666666;
    image->fill(colorMap);
    std::cout << "Jestem w mapie" <<std::endl;
}

void client::PaintingVisitor::visit(common::Predator &obj)
{    

    std::cout << "Jestem w Predatorze" <<std::endl;
    int x = obj.getX()*10;
    int y = obj.getY()*10;

    std::cout << x << " " << y << std::endl;

    long colorDarkPredator = 555555;
    long colorLightPredator = 7777777;

/// draw Predator ////////////////////////////////////////

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

/// end Predator /////////////////////////////////////////

/// draw Stats ///////////////////////////////////////////

/// end Stats ////////////////////////////////////////////

}

void client::PaintingVisitor::visit(common::Herbivore &obj)
{

    std::cout << "Jestem w Herbivorze" <<std::endl;

    int x = obj.getX()*10;
    int y = obj.getY()*10;

    long colorDarkHerb = 555555;
    long colorLightHerb = 7777777;

/// draw Herbivore ///////////////////////////////////////

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

/// end Herbivore ////////////////////////////////////////

/// draw Stats ///////////////////////////////////////////

/// end Stats ////////////////////////////////////////////

}

void client::PaintingVisitor::visit(common::Waterhole &obj)
{
    int x = obj.getX()*10;
    int y = obj.getY()*10;

    long colorLightWave = 555555;
    long colorDarkWave = 7777777;

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
    long colorDownLair = 7777777;

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
