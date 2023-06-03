#ifndef NEWINDOW1_H
#define NEWINDOW1_H

#include <QMainWindow>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtCore/QStringList>
#include <QtCore/QDebug>
#include <iostream>
#include <iomanip>

namespace Ui {
class Newindow1;
}

class Newindow1 : public QMainWindow
{
    Q_OBJECT
    QString username;

public:
    explicit Newindow1(QWidget *parent = nullptr);
    ~Newindow1();
    QDialog *newWindow;

public slots:
    void showNewWindow();
    void showNewWindow2();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Newindow1 *ui;
};



class UserManager {
public:
    UserManager(QFile *f ){
        file = f;

    }

    int checkCredentials(QString username, QString userid, QString password) {
        QTextStream in(file);

        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(",");

            if(parts[1]==userid && parts[2]==password)
            {
                return 2;
            }
            else if(parts[1] == userid )
            {
                return 1;
            }
        }
        return 0;
    }

    bool saveUserDetails(QString username,QString userid, QString password) {

        QTextStream out(file);
        out.seek(file->size()); // Move to end of file
        out << username << "," << userid << "," << password << "\n";
        return true;
    }

    ~UserManager() {
        file->close();
    }

public:
    QFile* file;
};


#endif // NEWINDOW1_H
