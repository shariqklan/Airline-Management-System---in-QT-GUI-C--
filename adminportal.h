#ifndef ADMINPORTAL_H
#define ADMINPORTAL_H
#include "newindow1.h"
#include <QMainWindow>

namespace Ui {
class adminportal;
}

class adminportal : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminportal(QWidget *parent = nullptr);
    ~adminportal();
 public slots:
    void showAdminMenu();

private slots:
    void on_pushButton_clicked();

private:
    Ui::adminportal *ui;
};

#endif // ADMINPORTAL_H

class Adminmanage: public UserManager
{
       const int pin=1234 ;
public:
Adminmanage(QFile *f):UserManager(f)
{
}
bool checkpin(int a)
{
    if(a==pin)
    {
        return true;
    }
    else
    {
        return false;
    }
}
 };
