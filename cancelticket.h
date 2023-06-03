#ifndef CANCELTICKET_H
#define CANCELTICKET_H

#include <QMainWindow>
#include "adminmenu.h"
#include "./ui_adminmenu.h"

namespace Ui {
class cancelticket;
}

class cancelticket : public QMainWindow
{
    Q_OBJECT

public:
    explicit cancelticket(QWidget *parent = nullptr);
    ~cancelticket();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::cancelticket *ui;
};

#endif // CANCELTICKET_H
