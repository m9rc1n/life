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

void Init_UI::on_spinBox_valueChanged(int arg1)
{
    std::cout << arg1;
}
