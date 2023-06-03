#ifndef NEWWINDOW2_H
#define NEWWINDOW2_H

#include <QMainWindow>
#include <QLabel>
#include <QCommandLinkButton>
#include <QObject>
#include "newwindow3.h"


namespace Ui {
class NewWindow2;
}

class NewWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewWindow2(QWidget *parent = nullptr);

    ~NewWindow2();
    QDialog *newWindow;


public slots:
    void shownewwindow();
    void shownewwindow1();
    void shownewwindow2();
    void shownewwindow3();
private slots:
    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_3_clicked();

    void on_commandLinkButton_4_clicked();

private:
    Ui::NewWindow2 *ui;

};

#endif // NEWWINDOW2_H



