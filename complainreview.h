#ifndef COMPLAINREVIEW_H
#define COMPLAINREVIEW_H

#include <QMainWindow>
#include "adminmenu.h"
#include "./ui_adminmenu.h"

namespace Ui {
class complainreview;
}

class complainreview : public QMainWindow
{
    Q_OBJECT

public:
    explicit complainreview(QWidget *parent = nullptr);
    ~complainreview();
public slots:
    void TextForBox();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::complainreview *ui;
};

#endif // COMPLAINREVIEW_H
