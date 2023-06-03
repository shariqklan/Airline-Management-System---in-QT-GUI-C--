#ifndef COMPLAIN_H
#define COMPLAIN_H

#include <QMainWindow>
#include "newwindow2.h"
#include "newindow1.h"
#include "./ui_newwindow2.h"

namespace Ui {
class Complain;
}

class Complain : public QMainWindow
{
    Q_OBJECT

public:
    explicit Complain(QWidget *parent = nullptr);
    ~Complain();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Complain *ui;
};

#endif // COMPLAIN_H
