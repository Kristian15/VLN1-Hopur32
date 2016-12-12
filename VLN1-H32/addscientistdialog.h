#ifndef ADDSCIENTISTDIALOG_H
#define ADDSCIENTISTDIALOG_H

#include <QDialog>
#include "servicelayer.h"

namespace Ui {
class AddScientistDialog;
}

class AddScientistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddScientistDialog(QWidget *parent = 0);
    ~AddScientistDialog();

private slots:
    void on_button_ok_clicked();

private:
    serviceLayer service;
   // bool validatePerson();

    Ui::AddScientistDialog *ui;
};

#endif // ADDSCIENTISTDIALOG_H
