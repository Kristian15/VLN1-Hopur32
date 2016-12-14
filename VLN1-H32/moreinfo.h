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
    explicit MoreInfo(Computer computer, QWidget *parent = 0);
    ~MoreInfo();

private slots:
    void on_button_nextFact_clicked();

    void on_button_addFact_clicked();

    void on_button_addPhoto_clicked();

    void on_button_deletePhoto_clicked();

    void on_button_deleteFact_clicked();

private:
    Ui::MoreInfo *ui;
    void setNext();
    serviceLayer service;
    vector<string> facts;
    int index;
    int id;
    string table;
    void setPhoto();
    void getNextFact();
};

#endif // MOREINFO_H
