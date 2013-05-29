#include "init_ui.hpp"
#include "init.hpp"
#include "ui_init_ui.h"
#include "../client/client_ui.hpp"

/// @TODO Dodac paramtry przy wolaniu konstruktora Init_UI w linii 10
Init_UI::Init_UI(common::Config *config_p, Client_UI *client_ui, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Init_UI()),
    cui(client_ui),
    config(config_p),
    prevIndex(0)
{
    ui->setupUi(this);

    predatorsPyramide = {"NONE", "HUNTING", "EATING", "DRINKING", "PROCREATING"};
    herbivorsPyramide = {"NONE", "RUNNING", "EATING", "DRINKING", "PROCREATING"};

    predatorsTable = {0, 0, 0, 0};
    herbivorsTable = {0, 0, 0, 0};

    ui->comboBox_1->addItems(herbivorsPyramide);
    ui->comboBox_2->addItems(herbivorsPyramide);
    ui->comboBox_7->removeItem(index);
    ui->comboBox_5->removeItem(index);
    ui->comboBox_6->removeItem(index);
    ui->comboBox_3->addItems(herbivorsPyramide);
    ui->comboBox_4->addItems(herbivorsPyramide);

    ui->comboBox_5->addItems(predatorsPyramide);
    ui->comboBox_6->addItems(predatorsPyramide);
    ui->comboBox_7->addItems(predatorsPyramide);
    ui->comboBox_8->addItems(predatorsPyramide);

    connect( ui->comboBox_1, SIGNAL( activated(int) ), this, SLOT(comboBox1_Activated(int)) );
    connect( ui->comboBox_2, SIGNAL( activated(int) ), this, SLOT(comboBox2_Activated(int)) );
    connect( ui->comboBox_3, SIGNAL( activated(int) ), this, SLOT(comboBox3_Activated(int)) );
    connect( ui->comboBox_4, SIGNAL( activated(int) ), this, SLOT(comboBox4_Activated(int)) );

    connect( ui->comboBox_5, SIGNAL( activated(int) ), this, SLOT(comboBox5_Activated(int)) );
    connect( ui->comboBox_6, SIGNAL( activated(int) ), this, SLOT(comboBox6_Activated(int)) );
    connect( ui->comboBox_7, SIGNAL( activated(int) ), this, SLOT(comboBox7_Activated(int)) );
    connect( ui->comboBox_8, SIGNAL( activated(int) ), this, SLOT(comboBox8_Activated(int)) );
}

Init_UI::~Init_UI()
{
    delete ui;
}

void Init_UI::on_pushButton_clicked()
{
    init::startGame();
    this->hide();
    this->cui->show();
}

void Init_UI::comboBox1_Activated(int index)
{
    if (index != 0)
    {
        // if h*T*[1] is different than zero enable button in other boxes
        if (herbivorsTable[0] != 0)
        {
            QVariant v(1|32);
            QModelIndex in2 = ui->comboBox_2->model()->index(herbivorsTable[0], 0);
            QModelIndex in3 = ui->comboBox_3->model()->index(herbivorsTable[0], 0);
            QModelIndex in4 = ui->comboBox_4->model()->index(herbivorsTable[0], 0);
            ui->comboBox_2->model()->setData(in2, v, Qt::UserRole -1);
            ui->comboBox_3->model()->setData(in3, v, Qt::UserRole -1);
            ui->comboBox_4->model()->setData(in4, v, Qt::UserRole -1);
        }
        QVariant v(0);
        QModelIndex in2 = ui->comboBox_2->model()->index(index, 0);
        QModelIndex in3 = ui->comboBox_3->model()->index(index, 0);
        QModelIndex in4 = ui->comboBox_4->model()->index(index, 0);
        ui->comboBox_2->model()->setData(in2, v, Qt::UserRole -1);
        ui->comboBox_3->model()->setData(in3, v, Qt::UserRole -1);
        ui->comboBox_4->model()->setData(in4, v, Qt::UserRole -1);
    }
    else
    {
        QVariant v(1|32);
        QModelIndex in2 = ui->comboBox_2->model()->index(herbivorsTable[0], 0);
        QModelIndex in3 = ui->comboBox_3->model()->index(herbivorsTable[0], 0);
        QModelIndex in4 = ui->comboBox_4->model()->index(herbivorsTable[0], 0);
        ui->comboBox_2->model()->setData(in2, v, Qt::UserRole -1);
        ui->comboBox_3->model()->setData(in3, v, Qt::UserRole -1);
        ui->comboBox_4->model()->setData(in4, v, Qt::UserRole -1);
    }
    herbivorsTable[0] = index;
}


void Init_UI::comboBox2_Activated(int index)
{
    if (index != 0)
    {
        // if h*T*[1] is different than zero enable button in other boxes
        if (herbivorsTable[1] != 0)
        {
            QVariant v(1|32);
            QModelIndex in1 = ui->comboBox_1->model()->index(herbivorsTable[1], 0);
            QModelIndex in3 = ui->comboBox_3->model()->index(herbivorsTable[1], 0);
            QModelIndex in4 = ui->comboBox_4->model()->index(herbivorsTable[1], 0);
            ui->comboBox_1->model()->setData(in1, v, Qt::UserRole -1);
            ui->comboBox_3->model()->setData(in3, v, Qt::UserRole -1);
            ui->comboBox_4->model()->setData(in4, v, Qt::UserRole -1);
        }
        QVariant v(0);
        QModelIndex in1 = ui->comboBox_1->model()->index(index, 0);
        QModelIndex in3 = ui->comboBox_3->model()->index(index, 0);
        QModelIndex in4 = ui->comboBox_4->model()->index(index, 0);
        ui->comboBox_1->model()->setData(in1, v, Qt::UserRole -1);
        ui->comboBox_3->model()->setData(in3, v, Qt::UserRole -1);
        ui->comboBox_4->model()->setData(in4, v, Qt::UserRole -1);
    }
    else
    {
        QVariant v(1|32);
        QModelIndex in1 = ui->comboBox_1->model()->index(herbivorsTable[1], 0);
        QModelIndex in3 = ui->comboBox_3->model()->index(herbivorsTable[1], 0);
        QModelIndex in4 = ui->comboBox_4->model()->index(herbivorsTable[1], 0);
        ui->comboBox_1->model()->setData(in1, v, Qt::UserRole -1);
        ui->comboBox_3->model()->setData(in3, v, Qt::UserRole -1);
        ui->comboBox_4->model()->setData(in4, v, Qt::UserRole -1);
    }
    herbivorsTable[1] = index;
}

void Init_UI::comboBox3_Activated(int index)
{
    if (index != 0)
    {
        // if h*T*[1] is different than zero enable button in other boxes
        if (herbivorsTable[2] != 0)
        {
            QVariant v(1|32);
            QModelIndex in1 = ui->comboBox_1->model()->index(herbivorsTable[2], 0);
            QModelIndex in2 = ui->comboBox_2->model()->index(herbivorsTable[2], 0);
            QModelIndex in4 = ui->comboBox_4->model()->index(herbivorsTable[2], 0);
            ui->comboBox_1->model()->setData(in1, v, Qt::UserRole -1);
            ui->comboBox_2->model()->setData(in2, v, Qt::UserRole -1);
            ui->comboBox_4->model()->setData(in4, v, Qt::UserRole -1);
        }
        QVariant v(0);
        QModelIndex in1 = ui->comboBox_1->model()->index(index, 0);
        QModelIndex in2 = ui->comboBox_2->model()->index(index, 0);
        QModelIndex in4 = ui->comboBox_4->model()->index(index, 0);
        ui->comboBox_1->model()->setData(in1, v, Qt::UserRole -1);
        ui->comboBox_2->model()->setData(in2, v, Qt::UserRole -1);
        ui->comboBox_4->model()->setData(in4, v, Qt::UserRole -1);
    }
    else
    {
        QVariant v(1|32);
        QModelIndex in1 = ui->comboBox_1->model()->index(herbivorsTable[1], 0);
        QModelIndex in2 = ui->comboBox_2->model()->index(herbivorsTable[1], 0);
        QModelIndex in4 = ui->comboBox_4->model()->index(herbivorsTable[1], 0);
        ui->comboBox_1->model()->setData(in1, v, Qt::UserRole -1);
        ui->comboBox_2->model()->setData(in2, v, Qt::UserRole -1);
        ui->comboBox_4->model()->setData(in4, v, Qt::UserRole -1);
    }
    herbivorsTable[2] = index;
}

void Init_UI::comboBox4_Activated(int index)
{
    if (index != 0)
    {
        // if h*T*[1] is different than zero enable button in other boxes
        if (herbivorsTable[3] != 0)
        {
            QVariant v(1|32);
            QModelIndex in1 = ui->comboBox_1->model()->index(herbivorsTable[3], 0);
            QModelIndex in2 = ui->comboBox_2->model()->index(herbivorsTable[3], 0);
            QModelIndex in3 = ui->comboBox_3->model()->index(herbivorsTable[3], 0);
            ui->comboBox_1->model()->setData(in1, v, Qt::UserRole -1);
            ui->comboBox_2->model()->setData(in2, v, Qt::UserRole -1);
            ui->comboBox_3->model()->setData(in3, v, Qt::UserRole -1);
        }
        QVariant v(0);
        QModelIndex in1 = ui->comboBox_1->model()->index(index, 0);
        QModelIndex in2 = ui->comboBox_2->model()->index(index, 0);
        QModelIndex in3 = ui->comboBox_3->model()->index(index, 0);
        ui->comboBox_1->model()->setData(in1, v, Qt::UserRole -1);
        ui->comboBox_2->model()->setData(in2, v, Qt::UserRole -1);
        ui->comboBox_3->model()->setData(in3, v, Qt::UserRole -1);
    }
    else
    {
        QVariant v(1|32);
        QModelIndex in1 = ui->comboBox_1->model()->index(herbivorsTable[3], 0);
        QModelIndex in3 = ui->comboBox_3->model()->index(herbivorsTable[3], 0);
        QModelIndex in4 = ui->comboBox_4->model()->index(herbivorsTable[3], 0);
        ui->comboBox_1->model()->setData(in1, v, Qt::UserRole -1);
        ui->comboBox_2->model()->setData(in3, v, Qt::UserRole -1);
        ui->comboBox_3->model()->setData(in4, v, Qt::UserRole -1);
    }
    herbivorsTable[3] = index;
}

void Init_UI::comboBox5_Activated(int index)
{
    if (index != 0)
    {
        // if h*T[1] is different than zero enable button in other boxes
        if (predatorsTable[0] != 0)
        {
            QVariant v(1|32);
            QModelIndex in6 = ui->comboBox_6->model()->index(predatorsTable[4], 0);
            QModelIndex in7 = ui->comboBox_7->model()->index(predatorsTable[4], 0);
            QModelIndex in8 = ui->comboBox_8->model()->index(predatorsTable[4], 0);
            ui->comboBox_6->model()->setData(in6, v, Qt::UserRole -1);
            ui->comboBox_7->model()->setData(in7, v, Qt::UserRole -1);
            ui->comboBox_8->model()->setData(in8, v, Qt::UserRole -1);
        }
        QVariant v(0);
        QModelIndex in6 = ui->comboBox_6->model()->index(index, 0);
        QModelIndex in7 = ui->comboBox_7->model()->index(index, 0);
        QModelIndex in8 = ui->comboBox_8->model()->index(index, 0);
        ui->comboBox_6->model()->setData(in6, v, Qt::UserRole -1);
        ui->comboBox_7->model()->setData(in7, v, Qt::UserRole -1);
        ui->comboBox_8->model()->setData(in8, v, Qt::UserRole -1);
    }
    else
    {
        QVariant v(1|32);
        QModelIndex in6 = ui->comboBox_6->model()->index(predatorsTable[0], 0);
        QModelIndex in7 = ui->comboBox_7->model()->index(predatorsTable[0], 0);
        QModelIndex in8 = ui->comboBox_8->model()->index(predatorsTable[0], 0);
        ui->comboBox_6->model()->setData(in6, v, Qt::UserRole -1);
        ui->comboBox_7->model()->setData(in7, v, Qt::UserRole -1);
        ui->comboBox_8->model()->setData(in8, v, Qt::UserRole -1);
    }
    predatorsTable[0] = index;
}

void Init_UI::comboBox6_Activated(int index)
{

    if (index != 0)
    {
        // if h*T[1] is different than zero enable button in other boxes
        if (predatorsTable[1] != 0)
        {
            QVariant v(1|32);
            QModelIndex in5 = ui->comboBox_6->model()->index(predatorsTable[1], 0);
            QModelIndex in7 = ui->comboBox_7->model()->index(predatorsTable[1], 0);
            QModelIndex in8 = ui->comboBox_8->model()->index(predatorsTable[1], 0);
            ui->comboBox_5->model()->setData(in5, v, Qt::UserRole -1);
            ui->comboBox_7->model()->setData(in7, v, Qt::UserRole -1);
            ui->comboBox_8->model()->setData(in8, v, Qt::UserRole -1);
        }
        QVariant v(0);
        QModelIndex in5 = ui->comboBox_5->model()->index(index, 0);
        QModelIndex in7 = ui->comboBox_7->model()->index(index, 0);
        QModelIndex in8 = ui->comboBox_8->model()->index(index, 0);
        ui->comboBox_5->model()->setData(in5, v, Qt::UserRole -1);
        ui->comboBox_7->model()->setData(in7, v, Qt::UserRole -1);
        ui->comboBox_8->model()->setData(in8, v, Qt::UserRole -1);
    }
    else
    {
        QVariant v(1|32);
        QModelIndex in5 = ui->comboBox_5->model()->index(predatorsTable[1], 0);
        QModelIndex in7 = ui->comboBox_7->model()->index(predatorsTable[1], 0);
        QModelIndex in8 = ui->comboBox_8->model()->index(predatorsTable[1], 0);
        ui->comboBox_5->model()->setData(in5, v, Qt::UserRole -1);
        ui->comboBox_7->model()->setData(in7, v, Qt::UserRole -1);
        ui->comboBox_8->model()->setData(in8, v, Qt::UserRole -1);
    }
    predatorsTable[1] = index;
}

void Init_UI::comboBox7_Activated(int index)
{
    if (index != 0)
    {
        // if h*T[1] is different than zero enable button in other boxes
        if (predatorsTable[2] != 0)
        {
            QVariant v(1|32);
            QModelIndex in5 = ui->comboBox_5->model()->index(predatorsTable[2], 0);
            QModelIndex in6 = ui->comboBox_6->model()->index(predatorsTable[2], 0);
            QModelIndex in8 = ui->comboBox_8->model()->index(predatorsTable[2], 0);
            ui->comboBox_5->model()->setData(in5, v, Qt::UserRole -1);
            ui->comboBox_6->model()->setData(in6, v, Qt::UserRole -1);
            ui->comboBox_8->model()->setData(in8, v, Qt::UserRole -1);
        }
        QVariant v(0);
        QModelIndex in5 = ui->comboBox_5->model()->index(index, 0);
        QModelIndex in6 = ui->comboBox_6->model()->index(index, 0);
        QModelIndex in8 = ui->comboBox_8->model()->index(index, 0);
        ui->comboBox_5->model()->setData(in5, v, Qt::UserRole -1);
        ui->comboBox_6->model()->setData(in6, v, Qt::UserRole -1);
        ui->comboBox_8->model()->setData(in8, v, Qt::UserRole -1);
    }
    else
    {
        QVariant v(1|32);
        QModelIndex in5 = ui->comboBox_5->model()->index(predatorsTable[2], 0);
        QModelIndex in6 = ui->comboBox_6->model()->index(predatorsTable[2], 0);
        QModelIndex in8 = ui->comboBox_8->model()->index(predatorsTable[2], 0);
        ui->comboBox_5->model()->setData(in5, v, Qt::UserRole -1);
        ui->comboBox_6->model()->setData(in6, v, Qt::UserRole -1);
        ui->comboBox_8->model()->setData(in8, v, Qt::UserRole -1);
    }
    predatorsTable[2] = index;
}

void Init_UI::comboBox8_Activated(int index)
{
    if (index != 0)
    {
        // if h*T[1] is different than zero enable button in other boxes
        if (predatorsTable[3] != 0)
        {
            QVariant v(1|32);
            QModelIndex in6 = ui->comboBox_6->model()->index(predatorsTable[3], 0);
            QModelIndex in7 = ui->comboBox_7->model()->index(predatorsTable[3], 0);
            QModelIndex in5 = ui->comboBox_5->model()->index(predatorsTable[3], 0);
            ui->comboBox_6->model()->setData(in6, v, Qt::UserRole -1);
            ui->comboBox_7->model()->setData(in7, v, Qt::UserRole -1);
            ui->comboBox_5->model()->setData(in5, v, Qt::UserRole -1);
        }
        QVariant v(0);
        QModelIndex in6 = ui->comboBox_6->model()->index(index, 0);
        QModelIndex in7 = ui->comboBox_7->model()->index(index, 0);
        QModelIndex in5 = ui->comboBox_5->model()->index(index, 0);
        ui->comboBox_6->model()->setData(in6, v, Qt::UserRole -1);
        ui->comboBox_7->model()->setData(in7, v, Qt::UserRole -1);
        ui->comboBox_5->model()->setData(in5, v, Qt::UserRole -1);
    }
    else
    {
        QVariant v(1|32);
        QModelIndex in6 = ui->comboBox_6->model()->index(predatorsTable[3], 0);
        QModelIndex in7 = ui->comboBox_7->model()->index(predatorsTable[3], 0);
        QModelIndex in5 = ui->comboBox_5->model()->index(predatorsTable[3], 0);
        ui->comboBox_6->model()->setData(in6, v, Qt::UserRole -1);
        ui->comboBox_7->model()->setData(in7, v, Qt::UserRole -1);
        ui->comboBox_5->model()->setData(in5, v, Qt::UserRole -1);
    }
    predatorsTable[3] = index;
}
