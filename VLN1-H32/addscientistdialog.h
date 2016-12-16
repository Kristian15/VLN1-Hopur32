#ifndef ADDSCIENTISTDIALOG_H
#define ADDSCIENTISTDIALOG_H

#include <QDialog>
#include "servicelayer.h"

// This Ui class is used to add end edit a Person
namespace Ui {
class AddScientistDialog;
}

class AddScientistDialog : public QDialog
{
    Q_OBJECT

public:
    // cunstructor for add
    explicit AddScientistDialog(QWidget *parent = 0);
    // constructor for edit
    explicit AddScientistDialog(Person person, QWidget *parent = 0);
    // destructor
    ~AddScientistDialog();

private slots:
    void on_button_ok_clicked();
    void on_button_cancel_clicked();

private:
    Ui::AddScientistDialog *ui;
    serviceLayer service;
    Person _person;
    // _edit is false if the function is being used to add
    // _edit is true otherwise
    bool _edit;
};

#endif // ADDSCIENTISTDIALOG_H
