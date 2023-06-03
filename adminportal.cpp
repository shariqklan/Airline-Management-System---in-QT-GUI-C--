#include "adminportal.h"
#include "ui_adminportal.h"
#include "newindow1.h"
#include "adminmenu.h"
#include "./ui_adminmenu.h"
#include <QtCore/QTextStream>
#include <QtGui>
#include <QMessageBox>
adminportal::adminportal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminportal)
{
    ui->setupUi(this);

    ui->lineEdit_3->setEchoMode(QLineEdit::Password);
    ui->lineEdit_4->setEchoMode(QLineEdit::Password);

    connect(ui->checkBox, &QCheckBox::toggled, this, [this](bool checked) {
    if (checked) {
            ui->lineEdit_3->setEchoMode(QLineEdit::Normal);
        }
    else {
            ui->lineEdit_3->setEchoMode(QLineEdit::Password);
        }
  });

    connect(ui->checkBox_3, &QCheckBox::toggled, this, [this](bool checked) {
    if (checked) {
            ui->lineEdit_4->setEchoMode(QLineEdit::Normal);
        }
    else {
            ui->lineEdit_4->setEchoMode(QLineEdit::Password);
        }
  });
}

adminportal::~adminportal()
{
    delete ui;
}
void adminportal::showAdminMenu()
{
    adminmenu *newWindow = new adminmenu();
    newWindow->show();
    this->close();
}

void adminportal::on_pushButton_clicked()
{
    if(ui->lineEdit_2->text().isEmpty())
    {
        QMessageBox::warning(this,"ID Error","Can't proceed without userID");
    }
    else if(ui->lineEdit_3->text().isEmpty())
    {
        QMessageBox::warning(this,"Password Error","Kindly enter a password");
    }
    else{
    QString username = ui->lineEdit->text();
    QString userid = ui->lineEdit_2->text();
    QString password = ui->lineEdit_3->text();
    QString temppin = ui->lineEdit_4->text();
      int pin = temppin.toInt();
      int k=0;
      QFile *f;
              QString path = "Admindetails.txt";
              f = new QFile(path);
              if(!f->open(QIODevice::ReadWrite | QIODevice::Text))
                  qDebug() << "Could not open file for read/write";

  Adminmanage user(f);

  if(ui->checkBox_2->isChecked())
          {
              int res;
              res=0;
              res = user.checkCredentials(username, userid, password);
              if(user.checkpin(pin))
                  k=1;
             if(res==1)
              {
                QMessageBox::warning(this,"ID Error","UserID has already been taken");
             }
             else if(res==2)
              {

                  QMessageBox::warning(this,"Account Error","Account already present. Enter New Details.");

              }
             else if(res==0 && k==0)
             {
                QMessageBox::warning(this,"Incorrect Pin","Pin is wrong! Try Again");
             }

              else if(res==0 && k==1)
              {
                  int check;
                  check= user.saveUserDetails(username,userid,password);
                  if(check)
                 {
                      QMessageBox::information(this,"Signing","Sign Up Succesful");
                      QFile *file;
                      QString path = "Curruserdetails.txt";
                      file = new QFile(path);
                      if(!file->open(QIODevice::WriteOnly | QIODevice::Text))
                          qDebug() << "Could not open file for write";
                      QTextStream out(file);
                      out.seek(file->size());
                      out << username<< "\n";
                      file->close();
                       showAdminMenu();


                  }


              }
          }

      else
      {

              int res2;
              res2=0;
              res2= user.checkCredentials(username,userid,password);
              if(user.checkpin(pin))
                  k=1;
              if(res2==2 && k==1)
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
                   showAdminMenu();
              }
              else if(res2==2 && k==0)
              {
                 QMessageBox::warning(this,"Incorrect Pin","Pin is wrong! Try Again");
              }
              else if(res2==1)
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

