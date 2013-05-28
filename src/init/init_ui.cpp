#include "init_ui.hpp"
#include "ui_init_ui.h"

using namespace Ui;


/// @TODO Dodac paramtry przy wolaniu konstruktora Init_UI w linii 10
Init_UI::Init_UI(common::Config *config_p, Ui::Client_UI *client_ui, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Init_UI(NULL, NULL, NULL)),
    cui(client_ui),
    config(config_p)
{
  //  ui->setupUi(this); // nie kompilowalo sie (?)
}

Init_UI::~Init_UI()
{
    delete ui;
}

void Init_UI::on_pushButton_clicked()
{
    //init::startGame();
    //this->hide();
    //this->cui->show();
}
