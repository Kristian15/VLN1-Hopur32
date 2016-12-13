#include "deleteconfirmationdialog.h"
#include "ui_deleteconfirmationdialog.h"

DeleteConfirmationDialog::DeleteConfirmationDialog(int id, string comporpers, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteConfirmationDialog)
{
    ui->setupUi(this);
    _id = id;
    _comporpers = comporpers;

}

DeleteConfirmationDialog::~DeleteConfirmationDialog()
{
    delete ui;
}

void DeleteConfirmationDialog::on_button_deleteYes_clicked()
{
    if(_comporpers == "computer")
    {
        service.deleteComputer(_id);
        this->close();
    }
    else if(_comporpers =="person")
    {
        service.deletePerson(_id);
        this->close();
    }
}

void DeleteConfirmationDialog::on_button_deleteNo_clicked()
{
    this->close();
}
