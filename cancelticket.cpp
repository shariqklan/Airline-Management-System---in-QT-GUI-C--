#include "cancelticket.h"
#include "ui_cancelticket.h"
#include "adminmenu.h"
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QMessageBox>
#include <QComboBox>
#include <QString>
#include "adminportal.h"
#include "adminmenu.h"
#include "./ui_adminmenu.h"
#include "bill.h"

cancelticket::cancelticket(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cancelticket)
{
    ui->setupUi(this);
}

cancelticket::~cancelticket()
{
    delete ui;
}

void cancelticket::on_pushButton_clicked()
{
    QString ticketId = ui->lineEdit->text();
    FindTicket fp;
    bool search;
    search= fp.find(ticketId);
    if(search)
    {

    QFile inputFile("TicketInfo.txt");
    inputFile.open(QIODevice::ReadOnly | QIODevice::Text);

    QFile tempFile("temp.txt");
    tempFile.open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream in(&inputFile);
    QTextStream out(&tempFile);

    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.startsWith(ticketId)) {
            for (int i = 0; i < 16; i++) {
                in.readLine();
            }
        } else {
            out << line << "\n";
        }
    }

    inputFile.close();
    tempFile.close();

    QFile::remove("TicketInfo.txt");
    QFile::rename("temp.txt", "TicketInfo.txt");

    QMessageBox::information(this, "Ticket Deleted", "The ticket data has been deleted successfully.");
    }

    else{
        QMessageBox::information(this, "Ticket Error", "No such ticket found.");
    }

}

void cancelticket::on_pushButton_2_clicked()
{
    adminportal ob1;
    ob1.showAdminMenu();
    this->close();
}

