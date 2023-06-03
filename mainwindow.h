#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QPushButton>
#include <QMouseEvent>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QDialog *newWindow;


public slots:

    void showNewWindow();

private slots:


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
