#ifndef UPDATETICKET_H
#define UPDATETICKET_H

#include <QMainWindow>
#include "newwindow3.h"
#include "newwindow2.h"
#include "./ui_newwindow3.h"
#include "adminmenu.h"
#include "./ui_adminmenu.h"
namespace Ui {
class updateticket;
}

class updateticket : public QMainWindow
{
    Q_OBJECT

public:
    explicit updateticket(QWidget *parent = nullptr);
    ~updateticket();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::updateticket *ui;
};

#endif // UPDATETICKET_H
