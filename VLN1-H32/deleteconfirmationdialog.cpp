#include "deleteconfirmationdialog.h"
#include "ui_deleteconfirmationdialog.h"

DeleteConfirmationDialog::DeleteConfirmationDialog(int id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteConfirmationDialog)
{
    ui->setupUi(this);
    _id = id;
}

DeleteConfirmationDialog::~DeleteConfirmationDialog()
{
    delete ui;
}

void DeleteConfirmationDialog::on_button_deleteYes_clicked()
{
    service.deleteComputer(_id);
    this->close();
}

void DeleteConfirmationDialog::on_button_deleteNo_clicked()
{
    this->close();
}
