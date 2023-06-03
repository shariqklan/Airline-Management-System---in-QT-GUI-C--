#include "bill.h"
#include "./ui_bill.h"
#include "newwindow3.h"
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QMessageBox>
#include "newwindow2.h"
#include "newindow1.h"
#include "./ui_newwindow2.h"
#include "adminportal.h"
#include "adminmenu.h"
#include "./ui_adminmenu.h"
#include <QtWidgets/QTextEdit>

Bill::Bill(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Bill)
{
    ui->setupUi(this);
    QString fname,lname,flight, current, desti,seatType,depDate, seatNo, bill;

    QFile fp("TicketID.txt");
        if (!fp.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Failed to open file for reading:";

        }

    QTextStream init(&fp);
    QString id = init.readLine();

    fp.close();

    FindTicket tick;
    bool search = tick.find(id);
    QStringList Data= tick.getTicketData();
    if (search)
    {
        fname = Data.at(0);
        lname = Data.at(1);
        flight = Data.at(4);
        current = Data.at(5);
        desti = Data.at(6);
        seatType = Data.at(8);
        seatNo = Data.at(9);
        depDate = Data.at(10);
        bill = Data.at(15);
    }
    else
    {
        qDebug() << "ID not found";
    }
    QString imagepath;
    if(desti=="Karachi")
    {
        imagepath= "C:/Users/SAAD COMMUNICATION/Pictures/Karachi.jpg";
        QPixmap pixmap(imagepath);
        ui->label_10->setPixmap(pixmap.scaled(ui->label_10->size()));
    }
    else if(desti=="Islamabad")
    {
        imagepath= "C:/Users/SAAD COMMUNICATION/Pictures/Islamabad.jpg";
        QPixmap pixmap1(imagepath);
        ui->label_10->setPixmap(pixmap1.scaled(ui->label_10->size()));
    }
    else if(desti=="Lahore")
    {
        imagepath= "C:/Users/SAAD COMMUNICATION/Pictures/Lahore.jpg";
        QPixmap pixmap2(imagepath);
        ui->label_10->setPixmap(pixmap2.scaled(ui->label_10->size()));
    }
    else if(desti=="Peshawar")
    {
        imagepath= "C:/Users/SAAD COMMUNICATION/Pictures/Peshawar.png";
        QPixmap pixmap3(imagepath);
        ui->label_10->setPixmap(pixmap3.scaled(ui->label_10->size()));
    }
    else if(desti=="Quetta")
    {
        imagepath= "C:/Users/SAAD COMMUNICATION/Pictures/Quetta.jpg";
        QPixmap pixmap4(imagepath);
        ui->label_10->setPixmap(pixmap4.scaled(ui->label_10->size()));
    }
    else if(desti=="Sialkot")
    {
        imagepath= "C:/Users/SAAD COMMUNICATION/Pictures/Sialkot.png";
        QPixmap pixmap5(imagepath);
        ui->label_10->setPixmap(pixmap5.scaled(ui->label_10->size()));
    }
    else if(desti=="Faisalabad")
    {
        imagepath= "C:/Users/SAAD COMMUNICATION/Pictures/Faisalabad.jpg";
        QPixmap pixmap6(imagepath);
        ui->label_10->setPixmap(pixmap6.scaled(ui->label_10->size()));
    }
    else if(desti=="Chitral")
    {
        imagepath= "C:/Users/SAAD COMMUNICATION/Pictures/Chitral.jpg";
        QPixmap pixmap7(imagepath);
        ui->label_10->setPixmap(pixmap7.scaled(ui->label_10->size()));
    }
    else if(desti=="Skardu")
    {
        imagepath= "C:/Users/SAAD COMMUNICATION/Pictures/Skardu.jpg";
        QPixmap pixmap8(imagepath);
        ui->label_10->setPixmap(pixmap8.scaled(ui->label_10->size()));
    }
    else if(desti=="Multan")
    {
        imagepath= "C:/Users/SAAD COMMUNICATION/Pictures/Multan.jpg";
        QPixmap pixmap9(imagepath);
        ui->label_10->setPixmap(pixmap9.scaled(ui->label_10->size()));
    }

    QPropertyAnimation *animation = new QPropertyAnimation(ui->label_12, "geometry");
    animation->setDuration(2000);
    animation->setStartValue(QRect(360, 430, 0, 0));
    animation->setEndValue(QRect(360, 430, 111, 101));
    animation->setEasingCurve(QEasingCurve::InOutQuad);
    animation->start(QAbstractAnimation::DeleteWhenStopped);

    QPropertyAnimation *animation2 = new QPropertyAnimation(ui->label_13, "geometry");
    animation2->setDuration(2000);
    animation2->setStartValue(QRect(350, 510, 0, 0));
    animation2->setEndValue(QRect(350, 510, 131, 71));
    animation2->setEasingCurve(QEasingCurve::InOutQuad);
    animation2->start(QAbstractAnimation::DeleteWhenStopped);

    QFont ai("MV Boli ", 22, QFont::Bold);
    QFont font("Segoe UI ", 9, QFont::Bold);
    ui->label->setFont(ai);
    ui->label->setText(current);
    ui->label->setFont(ai);
    ui->label_2->setText(desti);
    QString fullName = fname + " " + lname;
    ui->label_3->setFont(font);
    ui->label_3->setText(fullName);
    ui->label_4->setFont(font);
    ui->label_4->setText(id);
    ui->label_5->setFont(font);
    ui->label_5->setText(flight);
    ui->label_6->setFont(font);
    ui->label_6->setText(seatType);
    ui->label_7->setFont(font);
    ui->label_7->setText(seatNo);
    ui->label_8->setFont(font);
    ui->label_8->setText(depDate);
    QFont my("Segoe UI ", 13, QFont::Bold);
    ui->label_9->setFont(my);
    ui->label_9->setText(bill);

}

Bill::~Bill()
{
    delete ui;
}

void Bill::on_pushButton_clicked()
{
    QFile file("CurrentFlagValue.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Failed to open file for reading:";

        }

    QTextStream in(&file);
    QString flag = in.readLine();
    file.close();
    if(flag=="false")
    {
        adminportal ob1;
        ob1.showAdminMenu();
        this->close();
    }

    else{
        Newindow1 obj;
        obj.showNewWindow();
        this->close();

       }
}


void Bill::on_pushButton_2_clicked()
{
    if(ui->radioButton->isChecked())
    {
        if (ui->textEdit->toPlainText().isEmpty()) {
            ui->label_27->setText("Kindly provide pickup location");

         } else {
                  ui->label_27->setText("An Uber Driver is on its way!");
               }
    }

    else{
        ui->label_27->setText(" ");
    }
}

