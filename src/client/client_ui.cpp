#include "client_ui.hpp"
#include "ui_client_ui.h"

/// @TODO Dodac parametry zamiast null dla konstruktora ClientUI w linii 11
Client_UI::Client_UI(common::Config *config_p, QWidget *parent) :
    QWidget(parent),
    config(config_p),
    ui(new Ui::Client_UI())
{
    ui->setupUi(this); // nie kompilowalo sie
}

Client_UI::~Client_UI()
{
    delete ui;
}
