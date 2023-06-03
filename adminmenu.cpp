#include "adminmenu.h"
#include "./ui_adminmenu.h"
#include "adminportal.h"
#include "cancelticket.h"
#include "./ui_cancelticket.h"
#include "updateticket.h"
#include "./ui_updateticket.h"
#include "complainreview.h"
#include "./ui_complainreview.h"


adminmenu::adminmenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminmenu)
{
    ui->setupUi(this);

    QFile file("ComplainData.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString line;
        while (!in.atEnd()) {
            line = in.readLine();
            if (!line.isEmpty()) {
                // Found the first non-empty line
                break;
            }
        }
        file.close();

        // Display the first non-empty line in the textEdit
        ui->textEdit->setPlainText(line);
        ui->textEdit->setFont(QFont("Palatino Linotype", 10, QFont::Bold));
        ui->textEdit->selectAll();
        QTextCharFormat format;
        format.setForeground(Qt::white);
        ui->textEdit->setCurrentCharFormat(format);
    }

}
void adminmenu::showcancelticket()
{
    cancelticket *newWindow = new  cancelticket();
    newWindow->show();
    this->close();
}

void adminmenu::showupdateticket()
{
    updateticket *newWindow = new  updateticket();
    newWindow->show();
    this->close();
}

void adminmenu::showcomplainreview()
{
    complainreview *newWindow = new  complainreview();
    newWindow->show();
    this->close();
}
adminmenu::~adminmenu()
{
    delete ui;
}

void adminmenu::on_commandLinkButton_2_clicked()
{
    connect(ui->commandLinkButton_2, SIGNAL(clicked()), this, SLOT(showcancelticket()));
}


void adminmenu::on_commandLinkButton_clicked()
{
     connect(ui->commandLinkButton, SIGNAL(clicked()), this, SLOT(showupdateticket()));
}



void adminmenu::on_commandLinkButton_3_clicked()
{
    connect(ui->commandLinkButton_3, SIGNAL(clicked()), this, SLOT(showcomplainreview()));
}

