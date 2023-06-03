#include "complainreview.h"
#include "ui_complainreview.h"
#include "adminportal.h"
#include "adminmenu.h"
#include "./ui_adminmenu.h"
#include <QMessageBox>
#include "bill.h"

complainreview::complainreview(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::complainreview)
{
    ui->setupUi(this);
    TextForBox();
}

complainreview::~complainreview()
{
    delete ui;
}

void complainreview::on_pushButton_clicked()
{
    adminportal ob1;
    ob1.showAdminMenu();
    this->close();
}

void complainreview::TextForBox()
{
    QFile file("ComplainData.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file";
        return;
    }

    QTextStream in(&file);
    QString data = in.readAll();

        // Split the data into lines
        QStringList lines = data.split("\n");

        // Filter out the empty lines
        QStringList filteredLines;
        for (const QString& line : lines) {
            if (!line.trimmed().isEmpty()) {
                filteredLines << line;
            }
        }

        ui->textEdit->setPlainText(filteredLines.join("\n\n"));


        file.close();

}

void complainreview::on_pushButton_2_clicked()
{
    QString ticketID1 = ui->lineEdit->text();
    QString complainType1 = ui->comboBox->currentText();

    QFile file("ComplainData.txt");
    if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {

        QString line;
        QStringList lines;
        QTextStream in(&file);
        while (!in.atEnd()) {
            line = in.readLine();

            // Check if the line contains the given ticketID and complainType
            if (!line.contains("TicketID: " + ticketID1 + ", Type: " + complainType1)) {
                lines << line;
            }
        }

        // Clear the file and write back all the other lines
        file.resize(0);
        QTextStream out(&file);
        for (const QString& line : lines) {
            out << line << "\n";
        }

        // Close the file
        file.close();
    }

    TextForBox();
}


void complainreview::on_pushButton_3_clicked()
{
   QString id=  ui->lineEdit->text();
   FindTicket fp;
   bool search;
   search= fp.find(id);
   if(search)
   {
       QMessageBox::information(this, "ID Status", "Ticket is available for action.");
   }
   else{
       QMessageBox::warning(this, "ID Status", "Ticket is not available.");
   }
}

