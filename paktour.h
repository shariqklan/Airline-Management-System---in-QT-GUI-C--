#ifndef PAKTOUR_H
#define PAKTOUR_H

#include <QMainWindow>
#include "newwindow2.h"
#include "newindow1.h"
#include "./ui_newwindow2.h"
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QPushButton>
#include <QMouseEvent>

namespace Ui {
class PakTour;
}

class PakTour : public QMainWindow
{
    Q_OBJECT

public:
    explicit PakTour(QWidget *parent = nullptr);
    ~PakTour();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::PakTour *ui;
};

#endif // PAKTOUR_H
