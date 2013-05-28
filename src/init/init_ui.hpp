#ifndef INIT_UI_H
#define INIT_UI_H

#include <QWidget>
#include "../include.hpp"

namespace Ui
{
    // class Init_UI;
    class Client_UI;


class Init_UI : public QWidget
{
    Q_OBJECT
    
public:
    explicit Init_UI(common::Config *config, Ui::Client_UI *client_ui, QWidget *parent = 0);
    ~Init_UI();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::Init_UI *ui;
    Ui::Client_UI *cui;

    common::Config *config;
};

}
#endif // INIT_UI_H
