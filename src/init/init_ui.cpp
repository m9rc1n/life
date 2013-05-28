#include "../include.hpp"
#include "ui_init_ui.h"

Init_UI::Init_UI(common::Config *config_p, int argc_p, char **argv_p, Ui::Client_UI *client_ui, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Init_UI),
    cui(client_ui),
    config(config_p),
    argc(argc_p),
    argv(argv_p)
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
