#ifndef NEWWINDOW3_H
#define NEWWINDOW3_H
#include "newwindow2.h"
#include "newindow1.h"
#include "./ui_newwindow2.h"
#include <QMainWindow>
#include <iostream>
#include <QRandomGenerator>
#include <bits/stdc++.h>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtCore/QStringList>
#include <cmath>
#include <QDateTime>
#include <QCoreApplication>
#include <QLabel>
#include <QComboBox>
#include <QPainter>
#include <QPoint>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QMouseEvent>
#include "adminmenu.h"
#include "./ui_adminmenu.h"

namespace Ui {
class NewWindow3;
}

class NewWindow3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewWindow3(QWidget *parent = nullptr);
    ~NewWindow3();

public slots:
    void showbillwindow();
    void resetCities(QString city);
    void cityFunction(QString city1);
    void updateLineEdit();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::NewWindow3 *ui;
};


class Passenger{

protected:
    QString first_name, last_name, address, origin, destination, meal_type, seat_type, flight_name, card_type , card_expiry_date , date_departure;
    qint64 phone,card_no;
    int card_cvv;
    const int eco_seats, bus_seats;

public:
    int eco, bus;
    Passenger(QString a, QString b, QString c, QString d, QString e, QString f, QString g, QString h, QString i, qint64 v, QString w, qint64 x, int y, QString z): eco_seats(150),bus_seats(50)
    {
        first_name= a;
        last_name = b;
        address = c;
        origin = d;
        destination = e;
        meal_type= f;
        seat_type= g;
        flight_name = h;
        card_type = i;
        phone = v;
        date_departure= w;
        card_no = x;
        card_cvv = y;
        card_expiry_date= z;
        eco= eco_seats;
        bus= bus_seats;
    }

    QString getFirstName()
    {
        return first_name ;
    }

    QString getLastName()
    {
        return last_name ;
    }

    QString getAddress()
    {
        return address ;
    }

    QString getOrigin()
    {
        return origin ;
    }

    QString getDestination()
    {
        return destination ;
    }

    QString getMeal()
    {
        return meal_type ;
    }

    QString getSeat()
    {
        return seat_type ;
    }

    QString getFlight()
    {
        return flight_name ;
    }

    QString getCardType()
    {
        return card_type ;
    }

    qint64 getPhone()
    {
        return phone;
    }

    QString getDepDate()
    {
        return date_departure;
    }

    qint64 getCardNo()
    {
        return card_no;
    }

    int getCardCVV()
    {
        return card_cvv;
    }

    QString getCardExp()
    {
        return card_expiry_date;
    }

    int getEco()
    {
        return eco;
    }

    int getBus()
    {
        return bus;
    }
};

class TicketType{
public:
    int no_seats;
    int bill;

public:
    TicketType()
    {

    }

    void Bill(int a)
    {
        bill = a;
    }
    void NoSeats(int b)
    {
        no_seats = b;
    }
    virtual bool seat() = 0;
};

class Economy: public TicketType{
private:
    Passenger *p;

public:

    Economy(Passenger *passenger) : p(passenger){}
    bool seat() override
    {
        if(TicketType::no_seats>p->getEco())
            return false;
        else
        {
            TicketType::bill= TicketType::bill*TicketType::no_seats;
            return true;
        }
    }

    ~Economy(){}

};

class Business: public TicketType{

private:
    Passenger *p1;
public:

    Business(Passenger *passenger): p1(passenger){}
    bool seat() override
    {
        if(no_seats>p1->getBus())
            return false;
        else
        {
            TicketType::bill= (TicketType::bill*TicketType::no_seats)+(20000*TicketType::no_seats);
            return true;
        }
    }

    ~Business(){}
};

class Ticket{
protected:
    QString ticket_id;
    Passenger *passenger;
    TicketType *ticketType;
    int bill1,noseat1;

public:
    Ticket():ticketType(){}
    Ticket(int a, Passenger p, TicketType *t):ticketType(t)
    {
        noseat1= a;
        passenger = &p;
        qint64 seed = QDateTime::currentMSecsSinceEpoch() ^ qint64(QCoreApplication::applicationPid());

            // Create a random number generator with the unique seed value
        QRandomGenerator generator(seed);
        int randomValue = generator.bounded(10000);
        ticket_id = "HF" + QString::number(randomValue);
    }

    bool checkDestiny()
    {
        if(passenger->getOrigin()== passenger->getDestination())
        {
            return false;
        }
        else
        {
            bill1= l_payment(passenger->getOrigin(),passenger->getDestination());
            ticketType->Bill(bill1);
            ticketType->NoSeats(noseat1);
            return true;
        }
    }
    bool checkCard()
    {
        if((floor(log10(passenger->getCardNo())) + 1 == 16) && (floor(std::log10(passenger->getCardCVV())) + 1 == 3))
            return true;
        else
            return false;
    }

    void registration()
    {
        QFile *f;
        QString path = "TicketInfo.txt";
        f = new QFile(path);
        if(!f->open(QIODevice::Append | QIODevice::Text))
             qDebug() << "Could not open file for read/write";
        QTextStream out(f);
        out.seek(f->size());
        out << ticket_id << "\n" << passenger->getFirstName() << "\n" << passenger->getLastName() << "\n" << passenger->getAddress() << "\n" << passenger->getPhone() << "\n" << passenger->getFlight() << "\n" << passenger->getOrigin() << "\n" << passenger->getDestination() << "\n" << passenger->getMeal() << "\n" << passenger->getSeat() << "\n" << ticketType->no_seats << "\n" << passenger->getDepDate() << "\n" << passenger->getCardType() << "\n" << passenger->getCardNo() << "\n" << passenger->getCardCVV() << "\n" << passenger->getCardExp() << "\n" << ticketType->bill<< "\n\n";
        f->close();
    }

    void saveTicketID()
    {
        QFile *fp;
        QString path = "TicketID.txt";
        fp = new QFile(path);
        if(!fp->open(QIODevice::WriteOnly | QIODevice::Text))
             qDebug() << "Could not open file for read/write";
        QTextStream out(fp);
        out.seek(fp->size());
        out << ticket_id<< "\n";
        fp->close();
    }

    bool seat(){
        if(ticketType->seat())
            return true;
        else
            return false;
    }

    void setTicketID(QString a)
    {
        ticket_id= a;
    }

    int l_payment(QString orig, QString dest)
    {
        if((orig=="Karachi" && dest=="Islamabad") || (orig=="Islamabad" && dest== "Karachi"))
                    return 80000;
        else if((orig=="Karachi" && dest=="Lahore") || (orig=="Lahore" && dest== "Karachi"))
            return 60000;
        else if((orig=="Karachi" && dest=="Peshawar") || (orig=="Peshawar" && dest== "Karachi"))
             return 81000;
        else if((orig=="Karachi" && dest=="Quetta") || (orig=="Quetta" && dest== "Karachi"))
             return 40000;
        else if((orig=="Karachi" && dest=="Multan") || (orig=="Multan" && dest== "Karachi"))
             return 45000;
        else if((orig=="Karachi" && dest=="Skardu") || (orig=="Skardu" && dest== "Karachi"))
             return 90000;
        else if((orig=="Karachi" && dest=="Faisalabad") || (orig=="Faisalabad" && dest== "Karachi"))
             return 55000;
        else if((orig=="Karachi" && dest=="Sialkot") || (orig=="Sialkot" && dest== "Karachi"))
             return 53000;
        else if((orig=="Karachi" && dest=="Chitral") || (orig=="Chitral" && dest== "Karachi"))
             return 95000;
        else if((orig=="Karachi" && dest=="Islamabad") || (orig=="Islamabad" && dest== "Karachi"))
             return 80000;
        else if((orig=="Islamabad" && dest=="Lahore") || (orig=="Lahore" && dest== "Islamabad"))
             return 30000;
        else if((orig=="Islamabad" && dest=="Peshawar") || (orig=="Peshawar" && dest== "Islamabad"))
             return 12000;
        else if((orig=="Islamabad" && dest=="Quetta") || (orig=="Quetta" && dest== "Islamabad"))
             return 49000;
        else if((orig=="Islamabad" && dest=="Multan") || (orig=="Multan" && dest== "Islamabad"))
             return 39000;
        else if((orig=="Islamabad" && dest=="Skardu") || (orig=="Skardu" && dest== "Islamabad"))
             return 37000;
        else if((orig=="Islamabad" && dest=="Faisalabad") || (orig=="Faisalabad" && dest== "Islamabad"))
             return 29000;
        else if((orig=="Islamabad" && dest=="Sialkot") || (orig=="Sialkot" && dest== "Islamabad"))
             return 20000;
        else if((orig=="Islamabad" && dest=="Chitral") || (orig=="Chitral" && dest== "Islamabad"))
             return 30000;
        else if((orig=="Lahore" && dest=="Peshawar") || (orig=="Peshawar" && dest== "Lahore"))
             return 43000;
        else if((orig=="Lahore" && dest=="Quetta") || (orig=="Quetta" && dest== "Lahore"))
             return 59000;
        else if((orig=="Lahore" && dest=="Multan") || (orig=="Multan" && dest== "Lahore"))
             return 27000;
        else if((orig=="Lahore" && dest=="Skardu") || (orig=="Skardu" && dest== "Lahore"))
             return 51000;
        else if((orig=="Lahore" && dest=="Faisalabad") || (orig=="Faisalabad" && dest== "Lahore"))
             return 12000;
        else if((orig=="Lahore" && dest=="Sialkot") || (orig=="Sialkot" && dest== "Lahore"))
             return 13000;
        else if((orig=="Lahore" && dest=="Chitral") || (orig=="Chitral" && dest== "Lahore"))
             return 55000;
        else if((orig=="Peshawar" && dest=="Quetta") || (orig=="Quetta" && dest== "Peshawar"))
             return 52000;
        else if((orig=="Peshawar" && dest=="Multan") || (orig=="Multan" && dest== "Peshawar"))
             return 39000;
        else if((orig=="Peshawar" && dest=="Skardu") || (orig=="Skardu" && dest== "Peshawar"))
             return 20000;
        else if((orig=="Peshawar" && dest=="Faisalabad") || (orig=="Faisalabad" && dest== "Peshawar"))
             return 27000;
        else if((orig=="Peshawar" && dest=="Sialkot") || (orig=="Sialkot" && dest== "Peshawar"))
             return 29000;
        else if((orig=="Peshawar" && dest=="Chitral") || (orig=="Chitral" && dest== "Peshawar"))
             return 20000;
        else if((orig=="Quetta" && dest=="Multan") || (orig=="Multan" && dest== "Quetta"))
             return 27000;
        else if((orig=="Quetta" && dest=="Skardu") || (orig=="Skardu" && dest== "Quetta"))
             return 80000;
        else if((orig=="Quetta" && dest=="Faisalabad") || (orig=="Faisalabad" && dest== "Quetta"))
             return 46000;
        else if((orig=="Quetta" && dest=="Sialkot") || (orig=="Sialkot" && dest== "Quetta"))
             return 50000;
        else if((orig=="Quetta" && dest=="Chitral") || (orig=="Chitral" && dest== "Quetta"))
             return 83000;
        else if((orig=="Multan" && dest=="Skardu") || (orig=="Skardu" && dest== "Multan"))
             return 77000;
        else if((orig=="Multan" && dest=="Faisalabad") || (orig=="Faisalabd" && dest== "Multan"))
             return 29000;
        else if((orig=="Multan" && dest=="Sialkot") || (orig=="Sialkot" && dest== "Multan"))
             return 36000;
        else if((orig=="Multan" && dest=="Chitral") || (orig=="Chitral" && dest== "Multan"))
                     return 50000;
      else if((orig=="Skardu" && dest=="Faislabad") || (orig=="Faisalabad" && dest== "Skardu"))
                     return 30000;
        else if((orig=="Skardu" && dest=="Sialkot") || (orig=="Sialkot" && dest== "Skardu"))
                     return 27000;
        else if((orig=="Skardu" && dest=="Chitral") || (orig=="Chitral" && dest== "Skardu"))
                     return 20000;
        else if((orig=="Faisalabad" && dest=="Sialkot") || (orig=="Sialkot" && dest== "Faisalabad"))
                     return 19000;
        else if((orig=="Faisalabad" && dest=="Chitral") || (orig=="Chitral" && dest== "Faisalabad"))
                     return 52000;
        else if((orig=="Sialkot" && dest=="Chitral") || (orig=="Chitral" && dest== "Sialkot"))
                     return 30000;
        else{
                    return 0;
                }
              }
};


#endif // NEWWINDOW3_H
