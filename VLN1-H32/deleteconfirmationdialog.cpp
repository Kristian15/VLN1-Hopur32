#include "deleteconfirmationdialog.h"
#include "ui_deleteconfirmationdialog.h"

DeleteConfirmationDialog::DeleteConfirmationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteConfirmationDialog)
{
    ui->setupUi(this);
}

DeleteConfirmationDialog::~DeleteConfirmationDialog()
{
    delete ui;
}
