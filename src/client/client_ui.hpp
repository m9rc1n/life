#ifndef CLIENT_UI_H
#define CLIENT_UI_H

#include <QWidget>

namespace Ui
{


class Client_UI : public QWidget
{
    Q_OBJECT

    public:
        explicit Client_UI(common::Config *config_p, QWidget *parent = 0);
        ~Client_UI();
    
    private:
        Ui::Client_UI *ui;
        common::Config *config;
};

}
#endif // CLIENT_UI_H
