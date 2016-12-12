#include "addcomputerdialog.h"
#include "ui_addcomputerdialog.h"

AddComputerDialog::AddComputerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputerDialog)
{
    ui->setupUi(this);
}

AddComputerDialog::~AddComputerDialog()
{
    delete ui;
}

void AddComputerDialog::on_button_ok_clicked()
{

    ui->label_computerName_Error->setText("");
    ui->label_computerType_Error->setText("");
    ui->label_computerDesignYear_Error->setText("");
    bool iftherewasanerror;


    QString name = ui->input_computerName->text();
    QString type = ui->input_computerType->text();
    QString year = ui->input_computerDesignYear->text();
    QString built = ui->dropDown_computerBuilt->currentText();

    servicelayer.newComputer(name.toStdString(), year.toStdString(),
                             type.toStdString(), built.toStdString());

}

void AddComputerDialog::on_button_cancel_clicked()
{
    this->close();
}

