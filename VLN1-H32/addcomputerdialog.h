#ifndef ADDCOMPUTERDIALOG_H
#define ADDCOMPUTERDIALOG_H

#include <QDialog>
#include "servicelayer.h"
#include <vector>

// This class is used to add and edit a computer
namespace Ui {
class AddComputerDialog;
}

class AddComputerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddComputerDialog(QWidget *parent = 0);
    explicit AddComputerDialog(Computer computer, QWidget *parent = 0);
    ~AddComputerDialog();

private slots:
    void on_button_ok_clicked();
    void on_button_cancel_clicked();

private:
    bool _edit;
    Computer _computer;
    serviceLayer servicelayer;
    void displayAllComputers();
    void displayComputers(vector<Computer> computers);
    Ui::AddComputerDialog *ui;
};

#endif // ADDCOMPUTERDIALOG_H
