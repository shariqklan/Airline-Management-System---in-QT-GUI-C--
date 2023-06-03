#ifndef BILL_H
#define BILL_H
#include "newwindow3.h"
#include <QMainWindow>
#include "newwindow2.h"
#include "newindow1.h"
#include "./ui_newwindow2.h"
#include "adminmenu.h"
#include "./ui_adminmenu.h"

namespace Ui {
class Bill;
}

class Bill : public QMainWindow
{
    Q_OBJECT

public:
    explicit Bill(QWidget *parent = nullptr);
    ~Bill();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Bill *ui;
};

#endif // BILL_H

class FindTicket{
protected:
    QString line;
    QStringList ticketData;
    bool found = false;
public:

    bool find(QString id){
    QFile file("TicketInfo.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file";
        return false;
    }

    while (!file.atEnd())
    {
        line = file.readLine().trimmed(); // read and trim the line

        if (line == id)
        {
            found = true;
            // read the following lines until a blank line is encountered
            while (!file.atEnd() && !line.isEmpty())
            {
                line = file.readLine().trimmed();
                if (!line.isEmpty())
                {
                    ticketData.append(line);
                }
            }
            break;
        }
    }

    file.close();
    return found;
    }

    QStringList getTicketData()
    {
        return ticketData;
    }
};
