#ifndef ADDCOMPUTERDIALOG_H
#define ADDCOMPUTERDIALOG_H

#include <QDialog>
#include "servicelayer.h"
#include <vector>

// This Ui class is used to add and edit a computer
namespace Ui {
class AddComputerDialog;
}

class AddComputerDialog : public QDialog
{
    Q_OBJECT

public:
    // constructor for add
    explicit AddComputerDialog(QWidget *parent = 0);
    // constructor for editi
    explicit AddComputerDialog(Computer computer, QWidget *parent = 0);
    // destructor
    ~AddComputerDialog();

private slots:
    void on_button_ok_clicked();
    void on_button_cancel_clicked();

private:
    Ui::AddComputerDialog *ui;
    serviceLayer service;
    Computer _computer;
    // _edit is false if the function is being used to add a new computer
    // _edit is true otherwise
    bool _edit;
};

#endif // ADDCOMPUTERDIALOG_H
