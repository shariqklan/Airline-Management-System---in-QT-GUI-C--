#include "newwindow2.h"
#include "complain.h"
#include "ui_complain.h"
#include "newwindow2.h"
#include "newindow1.h"
#include "./ui_newwindow2.h"
#include <QMessageBox>

Complain::Complain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Complain)
{
    ui->setupUi(this);

}

Complain::~Complain()
{
    delete ui;
}


void Complain::on_pushButton_clicked()
{
    Newindow1 obj;
    obj.showNewWindow();
    this->close();
}

void Complain::on_pushButton_2_clicked()
{
    if(ui->lineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "TicketID Invalid", "Kindly fill the ID box to process the complain.");
    }
    else{
    QString ticketID = ui->lineEdit->text();
    QString complainType = ui->comboBox->currentText();
    QString message = ui->plainTextEdit->toPlainText();

    QFile file("ComplainData.txt");
       if (file.open(QIODevice::Append | QIODevice::Text)) {
        // Write the data to the file
        QTextStream stream(&file);
        stream << "TicketID: " << ticketID << ", Type: " << complainType << ", Message: " << message << "\n\n";
        QMessageBox::information(this, "Complain Status", "Complain is transferred to Admin department.");
        // Close the file
        file.close();
    }   
    }
}


