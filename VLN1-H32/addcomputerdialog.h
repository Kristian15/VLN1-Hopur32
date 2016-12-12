#ifndef ADDCOMPUTERDIALOG_H
#define ADDCOMPUTERDIALOG_H

#include <QDialog>
#include "servicelayer.h"
#include <vector>

namespace Ui {
class AddComputerDialog;
}

class AddComputerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddComputerDialog(QWidget *parent = 0);
    ~AddComputerDialog();

private slots:
    void on_button_ok_clicked();

    void on_button_cancel_clicked();



private:
    Ui::AddComputerDialog *ui;
    serviceLayer servicelayer;
    void displayAllComputers();
};

#endif // ADDCOMPUTERDIALOG_H
