#include "newwindow2.h"
#include "reviewticket.h"
#include "ui_reviewticket.h"
#include "bill.h"
#include "newwindow2.h"
#include "newindow1.h"
#include "./ui_newwindow2.h"
#include <QMessageBox>

ReviewTicket::ReviewTicket(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ReviewTicket)
{
    ui->setupUi(this);
}

ReviewTicket::~ReviewTicket()
{
    delete ui;

}

void ReviewTicket::on_pushButton_clicked()
{
    QString fname,lname,address, phone, flight, current, desti,mealtype,seatType , seatNo,depDate,cardtype,cardno,cardcvv,cardexpdate, bill;
    QString id= ui->lineEdit->text();
    FindTicket fp;
    bool search;
    search= fp.find(id);
    QStringList Data= fp.getTicketData();
    if (search)
    {
        fname = Data.at(0);
        lname = Data.at(1);
        address = Data.at(2);
        phone = Data.at(3);
        flight = Data.at(4);
        current = Data.at(5);
        desti = Data.at(6);
        mealtype = Data.at(7);
        seatType = Data.at(8);
        seatNo = Data.at(9);
        depDate = Data.at(10);
        cardtype = Data.at(11);
        cardno = Data.at(12);
        cardcvv = Data.at(13);
        cardexpdate = Data.at(14);
        bill = Data.at(15);

        QString fullName = fname + " " + lname;
        ui->label_2->setText(fullName);
        ui->label_3->setText(address);
        ui->label_4->setText(phone);
        ui->label_5->setText(flight);
        ui->label_6->setText(current);
        ui->label_7->setText(desti);
        ui->label_8->setText(mealtype);
        ui->label_9->setText(seatType);
        ui->label_10->setText(seatNo);
        ui->label_11->setText(depDate);
        ui->label_12->setText(cardtype);
        ui->label_13->setText(cardno);
        ui->label_14->setText(cardcvv);
        ui->label_15->setText(cardexpdate);
        ui->label_16->setText(bill);
    }
    else
    {
       QMessageBox::information(this, "Ticket Error", "No such ticket found.");
       ui->label_2->setText("-");
       ui->label_3->setText("-");
       ui->label_4->setText("-");
       ui->label_5->setText("-");
       ui->label_6->setText("-");
       ui->label_7->setText("-");
       ui->label_8->setText("-");
       ui->label_9->setText("-");
       ui->label_10->setText("-");
       ui->label_11->setText("-");
       ui->label_12->setText("-");
       ui->label_13->setText("-");
       ui->label_14->setText("-");
       ui->label_15->setText("-");
       ui->label_16->setText("-");
    }
}


void ReviewTicket::on_pushButton_2_clicked()
{
    Newindow1 obj;
    obj.showNewWindow();
    this->close();
}

