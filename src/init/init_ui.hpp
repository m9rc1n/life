#ifndef INIT_UI_H
#define INIT_UI_H

#include <QMainWindow>
#include "../common/Config.hpp"
#include "ui_init_ui.h"
#include "../common/MaslovPyramid.hpp"


namespace Ui
{
    class Init_UI;
}

class Client_UI;

class Init_UI : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Init_UI(common::Config *config, QMainWindow *parent = 0);
    ~Init_UI();

    void enableItemFromPredator_0(int index, QVariant v);
    void enableItemFromPredator_1(int index, QVariant v);
    void enableItemFromPredator_2(int index, QVariant v);
    void enableItemFromPredator_3(int index, QVariant v);

    void enableItemFromHerbivore_0(int index, QVariant v);
    void enableItemFromHerbivore_1(int index, QVariant v);
    void enableItemFromHerbivore_2(int index, QVariant v);
    void enableItemFromHerbivore_3(int index, QVariant v);
    void enableItemFromHerbivore_4(int index, QVariant v);

private slots:
    void on_pushButton_clicked();

    void comboBox0_Activated(int);
    void comboBox1_Activated(int);
    void comboBox2_Activated(int);
    void comboBox3_Activated(int);
    void comboBox4_Activated(int);

    void comboBox5_Activated(int);
    void comboBox6_Activated(int);
    void comboBox7_Activated(int);
    void comboBox8_Activated(int);

    void on_spinBox_1_editingFinished();
    void on_spinBox_2_editingFinished();
    void on_spinBox_3_editingFinished();
    void on_spinBox_4_editingFinished();
    void on_spinBox_5_editingFinished();
    void about();

private:

    void createActions();
    void createMenus();

private:
    Ui::Init_UI     *ui;
    common::Config  *config;
    int             prevIndex;

    QStringList     predatorsPyramide;
    QStringList     herbivorsPyramide;
    QVector<int>    predatorsTable;
    QVector<int>    herbivorsTable;

    QModelIndex     index_1;
    QModelIndex     index_2;
    QModelIndex     index_3;
    QModelIndex     index_4;

    QMenu           *helpMenu;
    QMenu           *fileMenu;

    QAction         *exitAct;
    QAction         *aboutAct;
    QAction         *aboutQtAct;
};

#endif // INIT_UI_H
