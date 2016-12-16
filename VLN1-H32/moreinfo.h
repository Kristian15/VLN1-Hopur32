#ifndef MOREINFO_H
#define MOREINFO_H

#include "servicelayer.h"
#include <QDialog>
#include <QGraphicsItem>
#include <QBitmap>
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
class MoreInfo;
}

class MoreInfo : public QDialog
{
    Q_OBJECT

public:
    // Constructor
    explicit MoreInfo(QWidget *parent = 0);
    // Constructor for Person
    explicit MoreInfo(Person person, QWidget *parent = 0);
    // Constructor for Computer
    explicit MoreInfo(Computer computer, QWidget *parent = 0);
    // Destructor
    ~MoreInfo();

private slots:
    void on_button_addFact_clicked();
    void on_button_addPhoto_clicked();
    void on_button_deletePhoto_clicked();
    void on_button_deleteFact_clicked();
    void on_button_nextFact_clicked();
    void on_button_prevFact_clicked();

private:
    Ui::MoreInfo *ui;
    serviceLayer service;
    vector<string> facts;
    int index;
    int id;
    string table;
    void setPhoto();
    void setFirstFact();
    void setNext();
    void getNextFact();
    void getPrevFact();
};

#endif // MOREINFO_H
