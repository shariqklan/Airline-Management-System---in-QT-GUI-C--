#include "newwindow3.h"
#include "ui_newwindow3.h"
#include <QMessageBox>
#include <QComboBox>
#include <QString>
#include <QDate>
#include <QDateEdit>
#include "newwindow2.h"
#include "newindow1.h"
#include "./ui_newwindow2.h"
#include "bill.h"
#include "./ui_bill.h"
#include "updateticket.h"
#include "./ui_updateticket.h"
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtCore/QStringList>
#include <QtCore/QDebug>
#include <QMainWindow>
#include <QLabel>
#include <QComboBox>
#include <QPainter>
#include <QPoint>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QMovie>
#include <QTimer>
#include "adminportal.h"
#include "adminmenu.h"
#include "./ui_adminmenu.h"

// Define variables to store origin and destination cities
QString origin_city = "";
QString destination_city = "";

NewWindow3::NewWindow3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NewWindow3)
{
    ui->setupUi(this);

    connect(ui->comboBox_3, &QComboBox::currentTextChanged, this, &NewWindow3::updateLineEdit);
    connect(ui->comboBox_2, &QComboBox::currentTextChanged, this, &NewWindow3::updateLineEdit);
    connect(ui->lineEdit_6, &QLineEdit::textChanged, this, &NewWindow3::updateLineEdit);

    QPropertyAnimation *animation4 = new QPropertyAnimation(ui->label_16, "geometry");
    animation4->setDuration(25000); // 25 seconds
    animation4->setStartValue(QRect(0, 215, ui->label_16->width(), ui->label_16->height()));
    animation4->setEndValue(QRect(this->width()-ui->label_16->width(), 215, ui->label_16->width(), ui->label_16->height()));
    animation4->setEasingCurve(QEasingCurve::Linear);
    animation4->setLoopCount(-1);

    animation4->start();

    QFile file("CurrentFlagValue.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Failed to open file for reading:";

        }

    QTextStream in(&file);
    QString flag = in.readLine();
    file.close();
    if(flag=="false"){
            QFile file1("CurrentTicketUpdate.txt");
                if (!file1.open(QIODevice::ReadOnly | QIODevice::Text))
                {
                    qDebug() << "Failed to open file for reading:";

                }

            QTextStream ini(&file1);
            QString flag1 = ini.readLine();
            file1.close();
            FindTicket fp;
            bool search;
            search= fp.find(flag1);
            QStringList Data= fp.getTicketData();
            if (search)
            {
                QString fname1 = Data.at(0);
                QString lname1 = Data.at(1);
             QString   address1 = Data.at(2);
             QString   a1 = Data.at(3);

             QString   flight1 = Data.at(4);
             QString   origin1 = Data.at(5);
             QString   destination1 = Data.at(6);
             QString   meal1 = Data.at(7);
             QString   seat1 = Data.at(8);
             QString   c1 = Data.at(9);

             QString   depDate1 = Data.at(10);
             QString   card_type1 = Data.at(11);
              QString  b1 = Data.at(12);

             QString   d1 = Data.at(13);

              QString  carddate1 = Data.at(14);
              QString bill = Data.at(15);
                ui->lineEdit->setText(fname1);
                ui->lineEdit_2->setText(lname1);
                ui->lineEdit_3->setText(a1);
                ui->lineEdit_4->setText(address1);
                ui->lineEdit_5->setText(b1);
                ui->lineEdit_6->setText(c1);
                ui->lineEdit_7->setText(d1);
                ui->comboBox->setCurrentText(flight1);
                ui->comboBox_2->setCurrentText(destination1);
                ui->comboBox_3->setCurrentText(origin1);
                QDateTime dateTime = QDateTime::fromString(depDate1 + " 00:00:00", "yyyy-MM-dd hh:mm:ss");
                QDate date = dateTime.date();
                ui->dateEdit_2->setDate(date);
                QDateTime dateTime2 = QDateTime::fromString(carddate1 + " 00:00:00", "yyyy-MM-dd hh:mm:ss");
                QDate date1 = dateTime2.date();
                ui->dateEdit->setDate(date1);
                if(meal1=="Veg")
                {
                    ui->checkBox->setChecked(true);
                }
                else if(meal1=="Non-Veg")
                {
                    ui->checkBox_2->setChecked(true);
                }
                if(seat1=="Business")
                {
                    ui->checkBox_3->setChecked(true);
                }
                else if(seat1=="Economy")
                {
                    ui->checkBox_4->setChecked(true);
                }
                if(card_type1=="VisaCard")
                {
                    ui->radioButton->setChecked(true);
                }
                else if(card_type1=="MasterCard")
                {
                    ui->radioButton_2->setChecked(true);
                }
                else if(card_type1=="PayPak")
                {
                    ui->radioButton_3->setChecked(true);
                }
            }

            QFile inputFile("TicketInfo.txt");
            inputFile.open(QIODevice::ReadOnly | QIODevice::Text);

            QFile tempFile("temp.txt");
            tempFile.open(QIODevice::WriteOnly | QIODevice::Text);

            QTextStream init(&inputFile);
            QTextStream out(&tempFile);

            while (!init.atEnd()) {
                QString line = init.readLine();
                if (line.startsWith(flag1)) {
                    for (int i = 0; i < 16; i++) {
                        init.readLine();
                    }
                } else {
                    out << line << "\n";
                }
            }

            // Step 5: Close both files
            inputFile.close();
            tempFile.close();

            QFile::remove("TicketInfo.txt");
            QFile::rename("temp.txt", "TicketInfo.txt");
            QMessageBox::warning(this,"Admin View","You are in admin view");
        }
    else{
        QDate currentDate = QDate::currentDate();
        ui->dateEdit->setDate(currentDate);
        ui->dateEdit_2->setDate(currentDate);
    }
}

NewWindow3::~NewWindow3()
{
    delete ui;
}

void NewWindow3::updateLineEdit()
{
    QString comboBox1Text = ui->comboBox_3->currentText();
    QString comboBox2Text = ui->comboBox_2->currentText();
    QString c1 = ui->lineEdit_6->text();
    int n = c1.toInt();

    Ticket t;
    int value = t.l_payment(comboBox1Text, comboBox2Text);
    int bus_value = value;

    if(comboBox1Text=="-" || comboBox2Text=="-")
    {
        bus_value = value ;
    }
    else{
        bus_value = value + 20000;
    }
    ui->lineEdit_8->setText(QString::number(value));
    ui->lineEdit_10->setText(QString::number(bus_value));

    if(ui->checkBox_3->isChecked() && ui->checkBox_4->isChecked())
    {
        ui->lineEdit_9->setText("50");
        ui->lineEdit_11->setText("150");
    }
    if(ui->checkBox_3->isChecked())
    {
        if(n<=50)
        {
            int a= 50-n;
            ui->lineEdit_9->setText(QString::number(a));
            ui->lineEdit_11->setText("150");
        }
    }

    else if(ui->checkBox_4->isChecked())
    {
        if(n<=150)
        {
            int a= 150-n;
            ui->lineEdit_11->setText(QString::number(a));
            ui->lineEdit_9->setText("50");
        }
    }

    else{
        ui->lineEdit_9->setText("50");
        ui->lineEdit_11->setText("150");
    }
}

void NewWindow3::showbillwindow()
{
    Bill *newWindow = new Bill();
    newWindow->show();
    this->close();
}

void NewWindow3::on_pushButton_clicked()
{
    QFile file("CurrentFlagValue.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Failed to open file for reading:";

        }

    QTextStream in(&file);
    QString flag = in.readLine();
    file.close();
    QDate selectedDate = ui->dateEdit->date();
    QDate selectedDate_2 = ui->dateEdit_2->date();
    QDate currentDate = QDate::currentDate();

    if((!(ui->checkBox->isChecked()) && !(ui->checkBox_2->isChecked())) || (!(ui->checkBox_3->isChecked()) && !(ui->checkBox_4->isChecked())) || !(selectedDate.isValid()) || (!(selectedDate_2.isValid())||!(ui->radioButton->isChecked()) && !(ui->radioButton_2->isChecked()) && !(ui->radioButton_3->isChecked())) || (ui->lineEdit->text().isEmpty()) || (ui->lineEdit_2->text().isEmpty()) || (ui->lineEdit_3->text().isEmpty()) || (ui->lineEdit_4->text().isEmpty()) || (ui->lineEdit_5->text().isEmpty()) || (ui->lineEdit_6->text().isEmpty()) || (ui->lineEdit_7->text().isEmpty()) )
    {
        QMessageBox::warning(this,"Error","Please Fill every detail");
    }

    else if(((ui->checkBox->isChecked()) && (ui->checkBox_2->isChecked())) || ((ui->checkBox_3->isChecked()) && (ui->checkBox_4->isChecked())))
    {
        QMessageBox::warning(this,"Error","Please Choose 1 option b/w Meal or Seat Type");
    }

    else if((ui->comboBox_3->currentText()=="-") || (ui->comboBox_2->currentText()== "-"))
    {
        QMessageBox::warning(this,"Error","Please Choose a City to travel");
    }

    else{
    if(flag=="true"){
    if(currentDate > selectedDate)
    {
        QMessageBox::warning(this,"Error","Please Choose correct Card Expiration date");
    }

    if(currentDate > selectedDate_2)
    {
        QMessageBox::warning(this,"Error","Please Choose correct Departure date");
    }
    }
    if(flag=="false" || (flag=="true" && (selectedDate>=currentDate && selectedDate_2>=currentDate))){

        QString fname = ui->lineEdit->text();
        QString lname = ui->lineEdit_2->text();
        QString a = ui->lineEdit_3->text();
        qint64 phone= a.toLongLong();
        QString address = ui->lineEdit_4->text();
        QString b = ui->lineEdit_5->text();
        qint64 cardno = b.toLongLong();
        QString c = ui->lineEdit_6->text();
        int noseats = c.toInt();
        QString d = ui->lineEdit_7->text();
        int cvv = d.toInt();
        QString origin = ui->comboBox_3->currentText();
        QString destination = ui->comboBox_2->currentText();
        QString flight = ui->comboBox->currentText();
        QString meal, seat, card;
        QString depDate= selectedDate_2.toString(Qt::ISODate);
        QString carddate = selectedDate.toString(Qt::ISODate);
        if(ui->checkBox->isChecked())
            meal= "Veg";
        else if(ui->checkBox_2->isChecked())
            meal= "Non-Veg";
        if(ui->checkBox_3->isChecked())
            seat= "Business";
        else if(ui->checkBox_4->isChecked())
            seat= "Economy";
        if(ui->radioButton->isChecked())
            card= "VisaCard";
        else if(ui->radioButton_2->isChecked())
            card = "MasterCard";
        else if(ui->radioButton_3->isChecked())
            card = "PayPak";

        Passenger p1(fname,lname,address,origin,destination,meal,seat,flight,card,phone,depDate,cardno,cvv,carddate);
        TicketType* ticketType;
        if (seat=="Economy") {
            ticketType = new Economy(&p1);
        } else if(seat =="Business"){
            ticketType = new Business(&p1);
        }
        Ticket t1;
        t1= Ticket(noseats,p1, ticketType);
        if(t1.checkCard())
        {
            if(t1.checkDestiny())
            {

                if(t1.seat())
                {
                    if(flag=="false"){
                            QFile file1("CurrentTicketUpdate.txt");
                                if (!file1.open(QIODevice::ReadOnly | QIODevice::Text))
                                {
                                    qDebug() << "Failed to open file for reading:";

                                }

                            QTextStream ini(&file1);
                            QString flag2 = ini.readLine();
                            t1.setTicketID(flag2);
                            file1.close();
                    }
                    t1.registration();
                    t1.saveTicketID();
                    showbillwindow();
                }
                else
                {
                    if(seat=="Economy")
                        QMessageBox::warning(this,"Seats Unavaialable!","Sorry, the quantity of Economy Class seats are not available!");
                    else if(seat=="Business")
                        QMessageBox::warning(this,"Seats Unavaialable!","Sorry, the quantity of Business Class seats are not available!");
                }
            }

            else{
                QMessageBox::warning(this,"Origin and Destination Same!","Enter correct origin and destination cities!");
            }
        }
        else{
            QMessageBox::warning(this,"Card InValid","Enter Valid Card Details!");}

    }

    }

}

//function to reset variables when a new origin or destination is selected
void NewWindow3::resetCities(QString city) {
    if (city != origin_city && city != destination_city) {
        if (origin_city == city) {
            origin_city = "";
            ui->comboBox_3->setCurrentText("-");
        }
        if (destination_city == city) {
            destination_city = "";
            ui->comboBox_2->setCurrentText("-");
        }
        if (origin_city != "" && destination_city != "") {
            origin_city = city;
            destination_city = "";
            ui->comboBox_2->setCurrentText("-");
            ui->comboBox_3->setCurrentText(city);
        }
    }
}

// Define functions for each city
void NewWindow3::cityFunction(QString city1) {
    resetCities(city1);
    if (origin_city == city1) {
        origin_city = "";
        ui->comboBox_3->setCurrentText("-");
    } else if (destination_city == city1) {
        destination_city = "";
        ui->comboBox_2->setCurrentText("-");
    } else if (origin_city == "" && destination_city != city1) {
        origin_city = city1;
        ui->comboBox_3->setCurrentText(city1);
    } else if (destination_city == "" && origin_city != city1) {
        destination_city = city1;
        ui->comboBox_2->setCurrentText(city1);
    }
}

void NewWindow3::on_pushButton_2_clicked()
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

//Karachi
void NewWindow3::on_pushButton_3_clicked()
{
    cityFunction("Karachi");
}

//Islamabad
void NewWindow3::on_pushButton_4_clicked()
{
    cityFunction("Islamabad");
}

//Lahore
void NewWindow3::on_pushButton_5_clicked()
{
    cityFunction("Lahore");
}

//Faisalabad
void NewWindow3::on_pushButton_12_clicked()
{
    cityFunction("Faisalabad");
}

//Multan
void NewWindow3::on_pushButton_9_clicked()
{
    cityFunction("Multan");
}

//Sialkot
void NewWindow3::on_pushButton_11_clicked()
{
    cityFunction("Sialkot");
}

//Quetta
void NewWindow3::on_pushButton_7_clicked()
{
    cityFunction("Quetta");
}

//Peshawar
void NewWindow3::on_pushButton_6_clicked()
{
    cityFunction("Peshawar");
}

//Chitral
void NewWindow3::on_pushButton_10_clicked()
{
    cityFunction("Chitral");
}

//Skardu
void NewWindow3::on_pushButton_8_clicked()
{
    cityFunction("Skardu");
}

