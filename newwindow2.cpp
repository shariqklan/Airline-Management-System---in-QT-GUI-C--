#include "newwindow2.h"
#include "newindow1.h"
#include "./ui_newwindow2.h"
#include "newwindow3.h"
#include "./ui_newwindow3.h"
#include "reviewticket.h"
#include "./ui_reviewticket.h"
#include "complain.h"
#include "./ui_complain.h"
#include "paktour.h"
#include "./ui_paktour.h"
#include <QMovie>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtCore/QStringList>
#include <QtCore/QDebug>

void NewWindow2::shownewwindow()
{
    NewWindow3 *newWindow = new NewWindow3();
    newWindow->show();
    this->close();
}

void NewWindow2::shownewwindow1()
{
    ReviewTicket *newWindow = new ReviewTicket();
    newWindow->show();
    this->close();
}

void NewWindow2::shownewwindow2()
{
    Complain *newWindow = new Complain();
    newWindow->show();
    this->close();
}

void NewWindow2::shownewwindow3()
{
    PakTour *newWindow = new PakTour();
    newWindow->show();
    this->close();
}

NewWindow2::NewWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NewWindow2)
{
    ui->setupUi(this);

    QFile file("Currentuserdetails.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Failed to open file for reading:";

        }

    QTextStream in(&file);
    QString name = in.readLine();

    file.close();
    QString finaltext= name + "!";
    ui->label_2->setText(finaltext);
    ui->label_2->setGeometry(395,60,191,50);
    QFont font("Leelawadee UI", 22, QFont::Bold);
    ui->label_2->setFont(font);

    connect(ui->commandLinkButton, SIGNAL(clicked()), this, SLOT(shownewwindow()));
     connect(ui->commandLinkButton_2, SIGNAL(clicked()), this, SLOT(shownewwindow1()));
     connect(ui->commandLinkButton_3, SIGNAL(clicked()), this, SLOT(shownewwindow2()));

}

void NewWindow2::on_commandLinkButton_clicked()
{
    connect(ui->commandLinkButton, SIGNAL(clicked()), this, SLOT(shownewwindow()));
}


void NewWindow2::on_commandLinkButton_2_clicked()
{
    connect(ui->commandLinkButton_2, SIGNAL(clicked()), this, SLOT(shownewwindow1()));
}


void NewWindow2::on_commandLinkButton_3_clicked()
{
    connect(ui->commandLinkButton_3, SIGNAL(clicked()), this, SLOT(shownewwindow2()));
}


void NewWindow2::on_commandLinkButton_4_clicked()
{
    connect(ui->commandLinkButton_4, SIGNAL(clicked()), this, SLOT(shownewwindow3()));
}


NewWindow2::~NewWindow2()
{
    delete ui;
}
