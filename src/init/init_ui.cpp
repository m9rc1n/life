#include "init_ui.hpp"
#include "init.hpp"
#include "ui_init_ui.h"
#include "../client/client_ui.hpp"

/// @TODO Dodac paramtry przy wolaniu konstruktora Init_UI w linii 10
Init_UI::Init_UI(common::Config *config_p, Client_UI *client_ui, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Init_UI()),
    cui(client_ui),
    config(config_p)
{
    ui->setupUi(this);

    QStringList predatorsPyramide = {"NONE", "HUNTING", "EATING", "DRINKING", "PROCREATING"};
    QStringList herbivorsPyramide = {"NONE", "RUNNING", "EATING", "DRINKING", "PROCREATING"};

    predatorsBool = { false, false, false, false, false };
    herbivoresBool = { false, false, false, false, false };

    ui->comboBox->addItems(herbivorsPyramide);
    ui->comboBox_2->addItems(herbivorsPyramide);
    ui->comboBox_3->addItems(herbivorsPyramide);
    ui->comboBox_4->addItems(herbivorsPyramide);

    ui->comboBox_5->addItems(predatorsPyramide);
    ui->comboBox_6->addItems(predatorsPyramide);
    ui->comboBox_7->addItems(predatorsPyramide);
    ui->comboBox_8->addItems(predatorsPyramide);

    connect( ui->comboBox, SIGNAL( activated(int) ), this, SLOT(comboBox_Activated(int)) );
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



void Init_UI::comboBox_Activated(int index)
{
    ui->comboBox_2->removeItem(index);
    ui->comboBox_3->removeItem(index);
    ui->comboBox_4->removeItem(index);
}


void Init_UI::comboBox2_Activated(int index)
{
    ui->comboBox->removeItem(index);
    ui->comboBox_3->removeItem(index);
    ui->comboBox_4->removeItem(index);
}
