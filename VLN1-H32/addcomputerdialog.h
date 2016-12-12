#ifndef ADDCOMPUTERDIALOG_H
#define ADDCOMPUTERDIALOG_H

#include <QDialog>
#include "servicelayer.h"

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

private:
    Ui::AddComputerDialog *ui;
    serviceLayer servicelayer;
};

#endif // ADDCOMPUTERDIALOG_H
