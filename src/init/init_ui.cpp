#include "init_ui.hpp"
#include "init.hpp"
#include "ui_init_ui.h"
#include "../client/client_ui.hpp"

/// @TODO Dodac paramtry przy wolaniu konstruktora Init_UI w linii 10
Init_UI::Init_UI(common::Config *config_p, QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::Init_UI()),
    config(config_p),
    prevIndex(0)
{
    ui->setupUi(this);

    predatorsPyramide = {"NONE", "HUNTING", "DRINKING", "SLEEPING", "PROCREATING"};
    herbivorsPyramide = {"NONE", "RUNNING", "DRINKING", "SLEEPING", "PROCREATING", "EATING"};

    predatorsTable = {0, 0, 0, 0};
    herbivorsTable = {0, 0, 0, 0, 0};

    ui->comboBox_0->addItems(herbivorsPyramide);
    ui->comboBox_1->addItems(herbivorsPyramide);
    ui->comboBox_2->addItems(herbivorsPyramide);
    ui->comboBox_3->addItems(herbivorsPyramide);
    ui->comboBox_4->addItems(herbivorsPyramide);

    ui->comboBox_5->addItems(predatorsPyramide);
    ui->comboBox_6->addItems(predatorsPyramide);
    ui->comboBox_7->addItems(predatorsPyramide);
    ui->comboBox_8->addItems(predatorsPyramide);

    connect( ui->comboBox_0, SIGNAL( activated(int) ), this, SLOT(comboBox0_Activated(int)) );
    connect( ui->comboBox_1, SIGNAL( activated(int) ), this, SLOT(comboBox1_Activated(int)) );
    connect( ui->comboBox_2, SIGNAL( activated(int) ), this, SLOT(comboBox2_Activated(int)) );
    connect( ui->comboBox_3, SIGNAL( activated(int) ), this, SLOT(comboBox3_Activated(int)) );
    connect( ui->comboBox_4, SIGNAL( activated(int) ), this, SLOT(comboBox4_Activated(int)) );

    connect( ui->comboBox_5, SIGNAL( activated(int) ), this, SLOT(comboBox5_Activated(int)) );
    connect( ui->comboBox_6, SIGNAL( activated(int) ), this, SLOT(comboBox6_Activated(int)) );
    connect( ui->comboBox_7, SIGNAL( activated(int) ), this, SLOT(comboBox7_Activated(int)) );
    connect( ui->comboBox_8, SIGNAL( activated(int) ), this, SLOT(comboBox8_Activated(int)) );

    createActions();
    createMenus();

    setWindowTitle(tr("Life! ------ Predators vs. Herbivores"));
}

Init_UI::~Init_UI()
{
    delete ui;
}

void Init_UI::on_pushButton_clicked()
{
    if( predatorsTable.indexOf(0) != -1 )
    {
        /// @todo you should fill predators pyramide again
        // reset pyramide
        return;
    }

    if( herbivorsTable.indexOf(0) != -1 )
    {
        /// @todo you should fill herbivors pyramide again
        // reset pyramide
        return;
    }

    if( herbivorsTable.indexOf(0) != -1 )
    {
        /// @todo you should fill herbivors pyramide again
        // reset pyramide
        return;
    }
    config->herbivores_pyramid = new common::MaslovPyramid(herbivorsTable[0], herbivorsTable[1], herbivorsTable[2], herbivorsTable[3], herbivorsTable[4]);
    config->predators_pyramid  = new common::MaslovPyramid(predatorsTable[0], predatorsTable[1], predatorsTable[2], predatorsTable[3]);    


    this->hide();
    init::startGame();
}

void Init_UI::comboBox0_Activated(int index)
{
    if (index != 0)
    {
        // if h*T*[1] is different than zero enable button in other boxes
        if (herbivorsTable[0] != 0)
        {
            QVariant v(1|32);
            enableItemFromHerbivore_0(herbivorsTable[0], v);
        }
        QVariant v(0);
        enableItemFromHerbivore_0(index, v);
    }
    else
    {
        QVariant v(1|32);
        enableItemFromHerbivore_0(herbivorsTable[0], v);
    }
    herbivorsTable[0] = index;
}

void Init_UI::comboBox1_Activated(int index)
{
    if (index != 0)
    {
        // if h*T*[1] is different than zero enable button in other boxes
        if (herbivorsTable[1] != 0)
        {
            QVariant v(1|32);
            enableItemFromHerbivore_1(herbivorsTable[1], v);
        }
        QVariant v(0);
        enableItemFromHerbivore_1(index, v);
    }
    else
    {
        QVariant v(1|32);
        enableItemFromHerbivore_1(herbivorsTable[1], v);
    }
    herbivorsTable[1] = index;
}

void Init_UI::comboBox2_Activated(int index)
{
    if (index != 0)
    {
        // if h*T*[1] is different than zero enable button in other boxes
        if (herbivorsTable[2] != 0)
        {
            QVariant v(1|32);
            enableItemFromHerbivore_2(herbivorsTable[2], v);
        }
        QVariant v(0);
        enableItemFromHerbivore_2(index, v);
    }
    else
    {
        QVariant v(1|32);
        enableItemFromHerbivore_2(herbivorsTable[2], v);
    }
    herbivorsTable[2] = index;
}

void Init_UI::comboBox3_Activated(int index)
{
    if (index != 0)
    {
        // if h*T*[1] is different than zero enable button in other boxes
        if (herbivorsTable[3] != 0)
        {
            QVariant v(1|32);
            enableItemFromHerbivore_3(herbivorsTable[3], v);
        }
        QVariant v(0);
        enableItemFromHerbivore_3(index, v);
    }
    else
    {
        QVariant v(1|32);
        enableItemFromHerbivore_3(herbivorsTable[3], v);
    }
    herbivorsTable[3] = index;
}
void Init_UI::comboBox4_Activated(int index)
{
    if (index != 0)
    {
        // if h*T*[1] is different than zero enable button in other boxes
        if (herbivorsTable[4] != 0)
        {
            QVariant v(1|32);
            enableItemFromHerbivore_4(herbivorsTable[4], v);
        }
        QVariant v(0);
        enableItemFromHerbivore_4(index, v);
    }
    else
    {
        QVariant v(1|32);
        enableItemFromHerbivore_4(herbivorsTable[4], v);
    }
    herbivorsTable[4] = index;
}

void Init_UI::comboBox5_Activated(int index)
{
    if (index != 0)
    {
        // if h*T*[1] is different than zero enable button in other boxes
        if (predatorsTable[0] != 0)
        {
            QVariant v(1|32);
            enableItemFromPredator_0(predatorsTable[0], v);
        }
        QVariant v(0);
        enableItemFromPredator_0(index, v);
    }
    else
    {
        QVariant v(1|32);
        enableItemFromPredator_0(predatorsTable[0], v);
    }
    predatorsTable[0] = index;
}

void Init_UI::comboBox6_Activated(int index)
{
    if (index != 0)
    {
        // if h*T*[1] is different than zero enable button in other boxes
        if (predatorsTable[1] != 0)
        {
            QVariant v(1|32);
            enableItemFromPredator_1(predatorsTable[1], v);
        }
        QVariant v(0);
        enableItemFromPredator_1(index, v);
    }
    else
    {
        QVariant v(1|32);
        enableItemFromPredator_1(predatorsTable[1], v);
    }
    predatorsTable[1] = index;}

void Init_UI::comboBox7_Activated(int index)
{
    if (index != 0)
    {
        // if h*T*[1] is different than zero enable button in other boxes
        if (predatorsTable[2] != 0)
        {
            QVariant v(1|32);
            enableItemFromPredator_2(predatorsTable[2], v);
        }
        QVariant v(0);
        enableItemFromPredator_2(index, v);
    }
    else
    {
        QVariant v(1|32);
        enableItemFromPredator_2(predatorsTable[2], v);
    }
    predatorsTable[2] = index;
}

void Init_UI::comboBox8_Activated(int index)
{
    if (index != 0)
    {
        // if h*T*[1] is different than zero enable button in other boxes
        if (predatorsTable[3] != 0)
        {
            QVariant v(1|32);
            enableItemFromPredator_3(predatorsTable[3], v);
        }
        QVariant v(0);
        enableItemFromPredator_3(index, v);
    }
    else
    {
        QVariant v(1|32);
        enableItemFromPredator_3(predatorsTable[3], v);
    }
    predatorsTable[3] = index;
}

void Init_UI::enableItemFromHerbivore_0(int index, QVariant v)
{
    index_1 = ui->comboBox_1->model()->index(index, 0);
    index_2 = ui->comboBox_2->model()->index(index, 0);
    index_3 = ui->comboBox_3->model()->index(index, 0);
    index_4 = ui->comboBox_4->model()->index(index, 0);
    ui->comboBox_1->model()->setData(index_1, v, Qt::UserRole -1);
    ui->comboBox_2->model()->setData(index_2, v, Qt::UserRole -1);
    ui->comboBox_3->model()->setData(index_3, v, Qt::UserRole -1);
    ui->comboBox_4->model()->setData(index_4, v, Qt::UserRole -1);
}



void Init_UI::enableItemFromHerbivore_1(int index, QVariant v)
{
    index_1 = ui->comboBox_0->model()->index(index, 0);
    index_2 = ui->comboBox_2->model()->index(index, 0);
    index_3 = ui->comboBox_3->model()->index(index, 0);
    index_4 = ui->comboBox_4->model()->index(index, 0);
    ui->comboBox_0->model()->setData(index_1, v, Qt::UserRole -1);
    ui->comboBox_2->model()->setData(index_2, v, Qt::UserRole -1);
    ui->comboBox_3->model()->setData(index_3, v, Qt::UserRole -1);
    ui->comboBox_4->model()->setData(index_4, v, Qt::UserRole -1);
}

void Init_UI::enableItemFromHerbivore_2(int index, QVariant v)
{
    index_1 = ui->comboBox_0->model()->index(index, 0);
    index_2 = ui->comboBox_1->model()->index(index, 0);
    index_3 = ui->comboBox_3->model()->index(index, 0);
    index_4 = ui->comboBox_4->model()->index(index, 0);
    ui->comboBox_0->model()->setData(index_1, v, Qt::UserRole -1);
    ui->comboBox_1->model()->setData(index_2, v, Qt::UserRole -1);
    ui->comboBox_3->model()->setData(index_3, v, Qt::UserRole -1);
    ui->comboBox_4->model()->setData(index_4, v, Qt::UserRole -1);
}

void Init_UI::enableItemFromHerbivore_3(int index, QVariant v)
{
    index_1 = ui->comboBox_0->model()->index(index, 0);
    index_2 = ui->comboBox_1->model()->index(index, 0);
    index_3 = ui->comboBox_2->model()->index(index, 0);
    index_4 = ui->comboBox_4->model()->index(index, 0);
    ui->comboBox_0->model()->setData(index_1, v, Qt::UserRole -1);
    ui->comboBox_1->model()->setData(index_2, v, Qt::UserRole -1);
    ui->comboBox_2->model()->setData(index_3, v, Qt::UserRole -1);
    ui->comboBox_4->model()->setData(index_4, v, Qt::UserRole -1);
}


void Init_UI::enableItemFromHerbivore_4(int index, QVariant v)
{
    index_1 = ui->comboBox_0->model()->index(index, 0);
    index_2 = ui->comboBox_1->model()->index(index, 0);
    index_3 = ui->comboBox_2->model()->index(index, 0);
    index_4 = ui->comboBox_3->model()->index(index, 0);
    ui->comboBox_0->model()->setData(index_1, v, Qt::UserRole -1);
    ui->comboBox_1->model()->setData(index_2, v, Qt::UserRole -1);
    ui->comboBox_2->model()->setData(index_3, v, Qt::UserRole -1);
    ui->comboBox_3->model()->setData(index_4, v, Qt::UserRole -1);
}


void Init_UI::enableItemFromPredator_0(int index, QVariant v)
{
    index_1 = ui->comboBox_6->model()->index(index, 0);
    index_2 = ui->comboBox_7->model()->index(index, 0);
    index_3 = ui->comboBox_8->model()->index(index, 0);
    ui->comboBox_6->model()->setData(index_1, v, Qt::UserRole -1);
    ui->comboBox_7->model()->setData(index_2, v, Qt::UserRole -1);
    ui->comboBox_8->model()->setData(index_3, v, Qt::UserRole -1);
}


void Init_UI::enableItemFromPredator_1(int index, QVariant v)
{
    index_1 = ui->comboBox_5->model()->index(index, 0);
    index_2 = ui->comboBox_7->model()->index(index, 0);
    index_3 = ui->comboBox_8->model()->index(index, 0);
    ui->comboBox_5->model()->setData(index_1, v, Qt::UserRole -1);
    ui->comboBox_7->model()->setData(index_2, v, Qt::UserRole -1);
    ui->comboBox_8->model()->setData(index_3, v, Qt::UserRole -1);
}


void Init_UI::enableItemFromPredator_2(int index, QVariant v)
{
    index_1 = ui->comboBox_5->model()->index(index, 0);
    index_2 = ui->comboBox_6->model()->index(index, 0);
    index_3 = ui->comboBox_8->model()->index(index, 0);
    ui->comboBox_5->model()->setData(index_1, v, Qt::UserRole -1);
    ui->comboBox_6->model()->setData(index_2, v, Qt::UserRole -1);
    ui->comboBox_8->model()->setData(index_3, v, Qt::UserRole -1);
}

void Init_UI::enableItemFromPredator_3(int index, QVariant v)
{
    index_1 = ui->comboBox_5->model()->index(index, 0);
    index_2 = ui->comboBox_7->model()->index(index, 0);
    index_3 = ui->comboBox_6->model()->index(index, 0);
    ui->comboBox_5->model()->setData(index_1, v, Qt::UserRole -1);
    ui->comboBox_7->model()->setData(index_2, v, Qt::UserRole -1);
    ui->comboBox_6->model()->setData(index_3, v, Qt::UserRole -1);
}

void Init_UI::on_spinBox_1_editingFinished()
{
    int spin = ui->spinBox_1->value();
    config->setNumberOfHerbivores(spin);
}

void Init_UI::on_spinBox_2_editingFinished()
{
    int spin = ui->spinBox_2->value();
    config->setNumberOfPredators(spin);
}

void Init_UI::on_spinBox_3_editingFinished()
{
    int spin = ui->spinBox_3->value();
    config->setNumberOfTrees(spin);
}

void Init_UI::on_spinBox_4_editingFinished()
{
    int spin = ui->spinBox_4->value();
    config->setNumberOfWaterholes(spin);
}

void Init_UI::on_spinBox_5_editingFinished()
{
    int spin = ui->spinBox_5->value();
    config->setNumberOfLairs(spin);
}


void Init_UI::createMenus()
{
    fileMenu = new QMenu(tr("&File"), this);
    fileMenu->addAction(exitAct);

    helpMenu = new QMenu(tr("&Help"), this);
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);

    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(helpMenu);
}

void Init_UI::createActions()
{

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcut(tr("Ctrl+Q"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setEnabled(true);
    aboutAct->setCheckable(true);
    aboutAct->setShortcut(tr("Ctrl+A"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setEnabled(true);
    aboutQtAct->setCheckable(true);
    aboutQtAct->setShortcut(tr("Ctrl+W"));
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    this->addAction(aboutAct);
    this->addAction(aboutQtAct);
    this->addAction(exitAct);
}

void Init_UI::about()
{
    QMessageBox::about(this, tr("About Life!"),
            tr("<p>The <b>Life!</b></p>"
               "<p><b>How to use: </b></p>"
               "<p>Ctrl++ : <b> zoom in </b></p>"
               "<p>Ctrl+- : <b> zoom out </b></p>"
               "<p>Ctrl+S : <b> reset scale </b></p>"
               "<p>Ctrl+Q : <b> quit </b></p>"
               "<p>Ctrl+A : <b> about/help </b></p>"
               "<p>Ctrl+W : <b> about Qt </b></p>"
               "<p><b> Authors: </b>"
               "Michal Krawczak \n"
               "Marcin Urbanski</p>"));
}
