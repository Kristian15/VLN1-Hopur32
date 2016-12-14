#include "deleteconfirmationdialog.h"
#include "ui_deleteconfirmationdialog.h"

DeleteConfirmationDialog::DeleteConfirmationDialog(int id, int idb, string comporpers, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteConfirmationDialog)
{
    ui->setupUi(this);
    _id = id;
    _idb = idb;
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
    else if(_comporpers == "link")
    {
        service.unLink(_id, _idb);
        this->close();
    }
}

void DeleteConfirmationDialog::on_button_deleteNo_clicked()
{
    this->close();
}
