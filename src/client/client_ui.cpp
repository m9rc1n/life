#include "../include.hpp"
#include "ui_client_ui.h"

Client_UI::Client_UI(common::Config *config_p, QWidget *parent) :
    QWidget(parent),
    config(config_p),
    ui(new Ui::Client_UI)
{
    ui->setupUi(this);
}

Client_UI::~Client_UI()
{
    delete ui;
}
