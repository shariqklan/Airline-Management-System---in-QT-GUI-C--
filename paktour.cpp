#include "paktour.h"
#include "ui_paktour.h"
#include "newwindow2.h"
#include "newindow1.h"
#include "./ui_newwindow2.h"
#include <QPixmap>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QSequentialAnimationGroup>


// global initialize current index to 0
int currentIndex = 0;


PakTour::PakTour(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PakTour)
{
    ui->setupUi(this);
    ui->label->setScaledContents(true); // Scale the image to fit the label
    // create QList of images
    QList<QImage> images;
    images.append(QImage("C:/Users/SAAD COMMUNICATION/Pictures/Badshahi Mosque.png"));
    images.append(QImage("C:/Users/SAAD COMMUNICATION/Pictures/Passu.png"));
    images.append(QImage("C:/Users/SAAD COMMUNICATION/Pictures/Attabad Lake.png"));
    images.append(QImage("C:/Users/SAAD COMMUNICATION/Pictures/Dudipatsar Lake.png"));
    images.append(QImage("C:/Users/SAAD COMMUNICATION/Pictures/Faisal Mosque.png"));
    images.append(QImage("C:/Users/SAAD COMMUNICATION/Pictures/Karakoram Highway.png"));
    images.append(QImage("C:/Users/SAAD COMMUNICATION/Pictures/Kashmir Valley.png"));
    images.append(QImage("C:/Users/SAAD COMMUNICATION/Pictures/Katpana desert.png"));
    images.append(QImage("C:/Users/SAAD COMMUNICATION/Pictures/Neelum Valley.png"));
    images.append(QImage("C:/Users/SAAD COMMUNICATION/Pictures/SeaView.png"));

    // update label with current image
    ui->label->setPixmap(QPixmap::fromImage(images[0]));
    QPropertyAnimation *animation = new QPropertyAnimation(ui->label, "geometry", this);
    animation->setDuration(2500);
    animation->setStartValue(QRect(0, 0, 1080, 629));
    animation->setEndValue(QRect(-5, -5, 1110, 659));

    // Set the easing curve of the animation to make it smoother
    animation->setEasingCurve(QEasingCurve::InOutQuad);

    // Create a new animation group to loop the animation
    QSequentialAnimationGroup *group = new QSequentialAnimationGroup(this);
    group->addAnimation(animation);

    QPropertyAnimation *reverseAnimation = new QPropertyAnimation(ui->label, "geometry", this);
    reverseAnimation->setDuration(2500);
    reverseAnimation->setStartValue(QRect(-5,-5, 1110, 659));
    reverseAnimation->setEndValue(QRect(0, 0, 1080, 629));

    // Set the easing curve of the animation to make it smoother
    reverseAnimation->setEasingCurve(QEasingCurve::InOutQuad);

    // Add the reverse animation to the animation group
    group->addAnimation(reverseAnimation);

    // Set the loop count of the animation group to 0 to make it loop infinitely
    group->setLoopCount(-1);
    group->start();

    //connect next button
    connect(ui->pushButton, &QPushButton::clicked, [=]() {
        currentIndex++;
        if (currentIndex >= images.size()) {
            currentIndex = 0;
        }
        if(currentIndex==1)
        {
            ui->label_2->setText("      Passu");
            ui->label_4->setText("Location: Hunza District, Gilgit Baltistan");
            ui->label_7->setText("-");
            ui->label_8->setText("Skardu");

        }
        else if(currentIndex==0)
        {
            ui->label_2->setText("Badshahi Mosque");
            ui->label_4->setText("Location: Walled City of Lahore, Punjab");
            ui->label_7->setText("Lahore");
            ui->label_8->setText("-");

        }
        else if(currentIndex==2)
        {
            ui->label_2->setText("  Attabad Lake");
            ui->label_4->setText("Location: Gojal Valley, Hunza, Gilgit Baltistan");
            ui->label_7->setText("-");
            ui->label_8->setText("Skardu");

        }
        else if(currentIndex==3)
        {
            ui->label_2->setText("Dudipatsar Lake");
            ui->label_4->setText("Location: Jalkhad-Sharda Rd, Mansehra, KPK");
            ui->label_7->setText("-");
            ui->label_8->setText("Skardu");

        }
        else if(currentIndex==4)
        {
            ui->label_2->setText(" Faisal Mosque");
            ui->label_4->setText("Location: Shah Faisal Ave, E-8, Islamabad");
            ui->label_7->setText("Islamabad");
            ui->label_8->setText("-");

        }
        else if(currentIndex==5)
        {
            ui->label_2->setText("Karakoram Highway");
            ui->label_4->setText("Location: Punjab to Khunjerab Pass, Gilgit-Baltistan");
            ui->label_7->setText("-");
            ui->label_8->setText("Islamabad");

        }
        else if(currentIndex==6)
        {
            ui->label_2->setText("Kashmir Valley");
            ui->label_4->setText("Location: Muzaffarabad, Azad Kashmir");
            ui->label_7->setText("-");
            ui->label_8->setText("Islamabad");

        }
        else if(currentIndex==7)
        {
            ui->label_2->setText("Katpana Desert");
            ui->label_4->setText("Location: K2 Resort, Katpana, Skardu");
            ui->label_7->setText("Skardu");
            ui->label_8->setText("-");

        }
        else if(currentIndex==8)
        {
            ui->label_2->setText("Neelum Valley");
            ui->label_4->setText("Location: Muzaffarabad, Azad Kashmir");
            ui->label_7->setText("-");
            ui->label_8->setText("Islamabad");

        }
        else if(currentIndex==9)
        {
            ui->label_2->setText("         SeaView");
            ui->label_4->setText("   Location: Clifton Beach, Karachi");
            ui->label_7->setText("Karachi");
            ui->label_8->setText("-");

        }

        ui->label->setPixmap(QPixmap::fromImage(images[currentIndex]));
        group->start();
    });

    // connect previous button
    connect(ui->pushButton_2, &QPushButton::clicked, [=]() {
        currentIndex--;
        if (currentIndex < 0) {
            currentIndex = images.size() - 1;
        }
        if(currentIndex==1)
        {
            ui->label_2->setText("       Passu");
            ui->label_4->setText("Location: Hunza District, Gilgit Baltistan");
            ui->label_7->setText("-");
            ui->label_8->setText("Skardu");

        }
        else if(currentIndex==0)
        {
            ui->label_2->setText("Badshahi Mosque");
            ui->label_4->setText("Location: Walled City of Lahore, Punjab");
            ui->label_7->setText("Lahore");
            ui->label_8->setText("-");

        }
        else if(currentIndex==2)
        {
            ui->label_2->setText("Attabad Lake");
            ui->label_4->setText("Location: Gojal Valley, Hunza, Gilgit Baltistan");
            ui->label_7->setText("-");
            ui->label_8->setText("Skardu");

        }
        else if(currentIndex==3)
        {
            ui->label_2->setText("Dudipatsar Lake");
            ui->label_4->setText("Location: Jalkhad-Sharda Rd, Mansehra, KPK");
            ui->label_7->setText("-");
            ui->label_8->setText("Skardu");

        }
        else if(currentIndex==4)
        {
            ui->label_2->setText("Faisal Mosque");
            ui->label_4->setText("Location: Shah Faisal Ave, E-8, Islamabad");
            ui->label_7->setText("Islamabad");
            ui->label_8->setText("-");

        }
        else if(currentIndex==5)
        {
            ui->label_2->setText("Karakoram Highway");
            ui->label_4->setText("Location: Hasan Abdal, Punjab to Khunjerab Pass, Gilgit-Baltistan");
            ui->label_7->setText("-");
            ui->label_8->setText("Islamabad");

        }
        else if(currentIndex==6)
        {
            ui->label_2->setText("Kashmir Valley");
            ui->label_4->setText("Location: Muzaffarabad, Azad Kashmir");
            ui->label_7->setText("-");
            ui->label_8->setText("Islamabad");

        }
        else if(currentIndex==7)
        {
            ui->label_2->setText("Katpana Desert");
            ui->label_4->setText("Location: K2 Resort, Katpana, Skardu");
            ui->label_7->setText("Skardu");
            ui->label_8->setText("-");

        }
        else if(currentIndex==8)
        {
            ui->label_2->setText("Neelum Valley");
            ui->label_4->setText("Location: Muzaffarabad, Azad Kashmir");
            ui->label_7->setText("-");
            ui->label_8->setText("Islamabad");

        }
        else if(currentIndex==9)
        {
            ui->label_2->setText("SeaView");
            ui->label_4->setText("Location: Clifton Beach, Karachi");
            ui->label_7->setText("Karachi");
            ui->label_8->setText("-");

        }
        ui->label->setPixmap(QPixmap::fromImage(images[currentIndex]));
        group->start();
    });
}

PakTour::~PakTour()
{
    delete ui;
}

void PakTour::on_pushButton_3_clicked()
{
    Newindow1 obj;
    obj.showNewWindow();
    this->close();
}

