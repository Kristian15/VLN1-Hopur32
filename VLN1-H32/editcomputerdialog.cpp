#include "editcomputerdialog.h"
#include "ui_editcomputerdialog.h"

EditComputerDialog::EditComputerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditComputerDialog)
{
    ui->setupUi(this);
}

EditComputerDialog::~EditComputerDialog()
{
    delete ui;
}
