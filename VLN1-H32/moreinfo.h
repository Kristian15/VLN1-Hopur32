#ifndef MOREINFO_H
#define MOREINFO_H

#include "servicelayer.h"
#include <QDialog>

namespace Ui {
class MoreInfo;
}

class MoreInfo : public QDialog
{
    Q_OBJECT

public:
    explicit MoreInfo(QWidget *parent = 0);
    explicit MoreInfo(Person person, QWidget *parent = 0);
    ~MoreInfo();

private slots:
    void on_button_nextFact_clicked();

    void on_button_addFact_clicked();

private:
    Ui::MoreInfo *ui;
    void setNext();
    serviceLayer service;
    vector<string> facts;
    int index;
};

#endif // MOREINFO_H