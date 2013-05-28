#ifndef INITUI_H
#define INITUI_H

#include <QWidget>

namespace Ui {
class InitUI;
}

class InitUI : public QWidget
{
    Q_OBJECT
    
public:
    explicit InitUI(QWidget *parent = 0);
    ~InitUI();
    
private:
    Ui::InitUI *ui;
};

#endif // INITUI_H
