#include "client_ui.h"
#include "ui_client_ui.h"

Client_UI::Client_UI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client_UI)
{
    ui->setupUi(this);
}

Client_UI::~Client_UI()
{
    delete ui;
}
