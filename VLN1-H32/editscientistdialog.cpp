#include "editscientistdialog.h"
#include "ui_editscientistdialog.h"

EditScientistDialog::EditScientistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditScientistDialog)
{
    ui->setupUi(this);
}

EditScientistDialog::~EditScientistDialog()
{
    delete ui;
}
