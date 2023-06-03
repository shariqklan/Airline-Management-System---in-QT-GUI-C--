#ifndef ADMINMENU_H
#define ADMINMENU_H

#include <QMainWindow>

namespace Ui {
class adminmenu;
}

class adminmenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminmenu(QWidget *parent = nullptr);
    ~adminmenu();

public slots:
   void  showcancelticket();

   void showupdateticket();

   void showcomplainreview();

private slots:
    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_clicked();

    void on_commandLinkButton_3_clicked();

private:
    Ui::adminmenu *ui;
};

#endif // ADMINMENU_H
