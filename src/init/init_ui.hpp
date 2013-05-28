#ifndef INIT_UI_H
#define INIT_UI_H

#include <QWidget>

namespace Ui {
class Init_UI;
}

class Init_UI : public QWidget
{
    Q_OBJECT
    
public:
    explicit Init_UI(QWidget *parent = 0);
    ~Init_UI();
    
private:
    Ui::Init_UI *ui;
};

#endif // INIT_UI_H
