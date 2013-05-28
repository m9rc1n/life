#include "../include.hpp"
#include "ui_client_ui.h"

Client_UI::Client_UI(common::Config *config_p, int argc_p, char **argv_p, QWidget *parent) :
    QWidget(parent),
    config(config_p),
    argc(argc_p),
    argv(argv_p),
    ui(new Ui::Client_UI)
{
    ui->setupUi(this);
}

Client_UI::~Client_UI()
{
    delete ui;
}
