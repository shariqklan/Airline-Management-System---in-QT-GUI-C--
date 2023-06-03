#include "newindow1.h"
#include "./ui_newindow1.h"
#include "newwindow2.h"
#include "./ui_newwindow2.h"
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtCore/QStringList>
#include <QtCore/QDebug>
#include <iostream>
#include <iomanip>
#include <QMessageBox>
#include "adminportal.h"
#include "./ui_adminportal.h"


void Newindow1::showNewWindow()
{
    NewWindow2 *newWindow = new NewWindow2();
    newWindow->show();
    this->close();
}
void Newindow1::showNewWindow2()
{
    adminportal *newWindow = new adminportal();
    newWindow->show();
    this->close();
}

Newindow1::Newindow1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Newindow1)
{
    ui->setupUi(this);
    ui->passlineEdit->setEchoMode(QLineEdit::Password);

    connect(ui->checkBox, &QCheckBox::toggled, this, [this](bool checked) {
    if (checked) {
            ui->passlineEdit->setEchoMode(QLineEdit::Normal);
        }
    else {
            ui->passlineEdit->setEchoMode(QLineEdit::Password);
        }
  });

}

Newindow1::~Newindow1()
{
    delete ui;
}


void Newindow1::on_pushButton_clicked()
{

    QFile *fp;
    QString path1 = "CurrentFlagValue.txt";
    fp = new QFile(path1);
    if(!fp->open(QIODevice::WriteOnly | QIODevice::Text))
        qDebug() << "Could not open file for write";
    QTextStream out(fp);
    out.seek(fp->size());
    out <<"true"<< "\n";
    fp->close();
    QString username = ui->namelineEdit->text();
    QString userid = ui->idlineEdit->text();
    QString password = ui->passlineEdit->text();
    if(ui->idlineEdit->text().isEmpty())
    {
        QMessageBox::warning(this,"ID Error","Can't proceed without userID");
    }
    else if(ui->passlineEdit->text().isEmpty())
    {
        QMessageBox::warning(this,"Password Error","Kindly enter a password");
    }
    else{
    QFile *f;
            QString path = "Userdetails.txt";
            f = new QFile(path);
            if(!f->open(QIODevice::ReadWrite | QIODevice::Text))
                qDebug() << "Could not open file for read/write";

UserManager user(f);

    if(ui->logincheck->isChecked())
        {
            int res;
            res = user.checkCredentials(username, userid, password);
            if(res==1)
            {
                QMessageBox::warning(this,"ID Error","UserID has already been taken");
            }

            else if(res==2)
            {

                QMessageBox::warning(this,"Account Error","Account already present. Enter New Details.");

            }
            else if(res==0)
            {
                int check;
                check= user.saveUserDetails(username,userid,password);
                if(check)
               {
                    QMessageBox::information(this,"Signing","Sign Up Succesful");
                    QFile *file;
                    QString path = "Currentuserdetails.txt";
                    file = new QFile(path);
                    if(!file->open(QIODevice::WriteOnly | QIODevice::Text))
                        qDebug() << "Could not open file for write";
                    QTextStream out(file);
                    out.seek(file->size());
                    out << username<< "\n";
                    file->close();
                    showNewWindow();
                }
            }
        }

    else{

            int res2=0;
            res2= user.checkCredentials(username,userid,password);
            if(res2==2)
            {
                QFile *file;
                QString path = "Currentuserdetails.txt";
                file = new QFile(path);
                if(!file->open(QIODevice::WriteOnly | QIODevice::Text))
                    qDebug() << "Could not open file for write";
                QTextStream out(file);
                out.seek(file->size());
                out << username<< "\n";
                file->close();
                showNewWindow();
            }

            else if(res2)
            {
                QMessageBox::warning(this,"Incorrect Password","Password is wrong! Try Again");
            }
            else if(res2==0)
            {
                 QMessageBox::warning(this,"Login Error","No Such Account Present!");
            }
        }
}

}


void Newindow1::on_pushButton_2_clicked()
{
    showNewWindow2();
}

