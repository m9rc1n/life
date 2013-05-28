#include "init_ui.hpp"
#include "ui_init_ui.h"

Init_UI::Init_UI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Init_UI)
{
    ui->setupUi(this);
}

Init_UI::~Init_UI()
{
    delete ui;
}
