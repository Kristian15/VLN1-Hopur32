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
    QString name = ui->input_computerName->text();
    QString type = ui->input_computerType->text();
    QString year = ui->input_computerDesignYear->text();
    QString built = ui->dropDown_computerBuilt->currentText();
    cout << name.toStdString();
    servicelayer.newComputer(name.toStdString(), year.toStdString(),
                             type.toStdString(), built.toStdString());

}
