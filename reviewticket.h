#ifndef REVIEWTICKET_H
#define REVIEWTICKET_H

#include <QMainWindow>
#include "newwindow2.h"
#include "newindow1.h"
#include "./ui_newwindow2.h"

namespace Ui {
class ReviewTicket;
}

class ReviewTicket : public QMainWindow
{
    Q_OBJECT

public:
    explicit ReviewTicket(QWidget *parent = nullptr);
    ~ReviewTicket();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ReviewTicket *ui;
};

#endif // REVIEWTICKET_H
