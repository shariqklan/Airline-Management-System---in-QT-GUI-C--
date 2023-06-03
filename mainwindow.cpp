#include "mainwindow.h"
#include "newindow1.h"
#include "./ui_newindow1.h"
#include "./ui_mainwindow.h"
#include <QPropertyAnimation>
#include <QEasingCurve>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPropertyAnimation *animation = new QPropertyAnimation(ui->label_3, "geometry");
    animation->setDuration(3000);
    animation->setStartValue(QRect(530, 0, 0, 0));
    animation->setEndValue(QRect(530, 80, 111, 91));
    animation->setEasingCurve(QEasingCurve::InOutQuad);
    animation->start(QAbstractAnimation::DeleteWhenStopped);

    QPropertyAnimation *animation2 = new QPropertyAnimation(ui->label, "geometry");
    animation2->setDuration(3000);
    animation2->setStartValue(QRect(400, 560, 0, 0));
    animation2->setEndValue(QRect(400, 170, 561, 61));
    animation2->setEasingCurve(QEasingCurve::InOutQuad);
    animation2->start(QAbstractAnimation::DeleteWhenStopped);

    QPropertyAnimation *animation3 = new QPropertyAnimation(ui->label_2, "geometry");
    animation3->setDuration(3000);
    animation3->setStartValue(QRect(510, 560, 0, 0));
    animation3->setEndValue(QRect(510, 210, 341, 71));
    animation3->setEasingCurve(QEasingCurve::InOutQuad);
    animation3->start(QAbstractAnimation::DeleteWhenStopped);

    QPropertyAnimation *animation4 = new QPropertyAnimation(ui->label_5, "pos");
    animation4->setDuration(25000); // 25 seconds
    animation4->setStartValue(QPoint(width(), height() / 2));
    animation4->setEndValue(QPoint(-ui->label_5->width(), height() / 2));
    animation4->setEasingCurve(QEasingCurve::Linear);
    animation4->setLoopCount(-1); // Loop indefinitely

    // Start the animation
    animation4->start();

    QPropertyAnimation *animation5 = new QPropertyAnimation(ui->label_6, "pos");
    animation5->setDuration(25000); // 25 seconds
    animation5->setStartValue(QPoint(width(), height() / 2+ 50));
    animation5->setEndValue(QPoint(-ui->label_6->width(), height() / 2 +50));
    animation5->setEasingCurve(QEasingCurve::Linear);
    animation5->setLoopCount(-1); // Loop indefinitely

    // Start the animation
    animation5->start();

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(showNewWindow()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showNewWindow()
{
    Newindow1 *newWindow = new Newindow1;
    newWindow->show();
    this->close();
}
