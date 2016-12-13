#ifndef DELETECONFIRMATIONDIALOG_H
#define DELETECONFIRMATIONDIALOG_H

#include <QDialog>
#include "servicelayer.h"

namespace Ui {
class DeleteConfirmationDialog;
}

class DeleteConfirmationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteConfirmationDialog(int id, QWidget *parent = 0);
    ~DeleteConfirmationDialog();

private slots:
    void on_button_deleteYes_clicked();

    void on_button_deleteNo_clicked();

private:
    Ui::DeleteConfirmationDialog *ui;
    int _id;
    serviceLayer service;
};

#endif // DELETECONFIRMATIONDIALOG_H
