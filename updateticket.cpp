#include "updateticket.h"
#include "ui_updateticket.h"
#include "adminmenu.h"
#include "newwindow3.h"
#include "newwindow2.h"
#include "./ui_newwindow3.h"
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtCore/QStringList>
#include <QtCore/QDebug>
#include "adminportal.h"
#include "adminmenu.h"
#include "./ui_adminmenu.h"
#include <QMessageBox>
#include "bill.h"

updateticket::updateticket(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::updateticket)
{
    ui->setupUi(this);
}

updateticket::~updateticket()
{
    delete ui;
}

void updateticket::on_pushButton_clicked()
{
    QString ticketID = ui->lineEdit->text();
    FindTicket fp;
    bool search;
    search= fp.find(ticketID);
    if(search)
    {

        QFile *fp;
        QString path2 = "CurrentTicketUpdate.txt";
        fp = new QFile(path2);
        if(!fp->open(QIODevice::WriteOnly | QIODevice::Text))
            qDebug() << "Could not open file for write";
        QTextStream out1(fp);
        out1.seek(fp->size());
        out1 <<ticketID<< "\n";
        fp->close();

        QFile *file;
        QString path = "CurrentFlagValue.txt";
        file = new QFile(path);
        if(!file->open(QIODevice::WriteOnly | QIODevice::Text))
            qDebug() << "Could not open file for write";
        QTextStream out2(file);
        out2.seek(file->size());
        out2 <<"false"<< "\n";
        file->close();
        NewWindow2 obj;
        obj.shownewwindow();
        this->close();
    }

    else{
        QMessageBox::information(this, "Ticket Error", "No such ticket found.");
    }

}

void updateticket::on_pushButton_2_clicked()
{
    adminportal ob1;
    ob1.showAdminMenu();
    this->close();
}

