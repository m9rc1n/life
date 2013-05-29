#ifndef INIT_UI_H
#define INIT_UI_H

#include <QWidget>
#include "../common/Config.hpp"
#include "ui_init_ui.h"


namespace Ui
{
    class Init_UI;
}

class Client_UI;

class Init_UI : public QWidget
{
    Q_OBJECT
    
public:
    explicit Init_UI(common::Config *config, Client_UI *client_ui, QWidget *parent = 0);
    ~Init_UI();

    
private slots:
    void on_pushButton_clicked();
    void comboBox1_Activated(int);
    void comboBox2_Activated(int);
    void comboBox3_Activated(int);
    void comboBox4_Activated(int);
    void comboBox5_Activated(int);
    void comboBox6_Activated(int);
    void comboBox7_Activated(int);
    void comboBox8_Activated(int);

private:
    Ui::Init_UI     *ui;
    Client_UI       *cui;
    common::Config  *config;
    int             prevIndex;

    QStringList     predatorsPyramide;
    QStringList     herbivorsPyramide;
    QVector<int>    predatorsTable;
    QVector<int>    herbivorsTable;
};

#endif // INIT_UI_H
