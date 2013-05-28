#include "initui.h"
#include "ui_initui.h"

InitUI::InitUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InitUI)
{
    ui->setupUi(this);
}

InitUI::~InitUI()
{
    delete ui;
}
