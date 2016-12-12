#include "addscientistdialog.h"
#include "ui_addscientistdialog.h"

AddScientistDialog::AddScientistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScientistDialog)
{
    ui->setupUi(this);
}

AddScientistDialog::~AddScientistDialog()
{
    delete ui;
}

void AddScientistDialog::on_button_ok_clicked()
{
    bool error = service.openDatabase();
    QString name = ui -> input_scientistName -> text();
    QString byear = ui -> input_scientistBirthYear -> text();
    QString dyear = ui -> input_scientistDeathYear -> text();

    error = service.validateNewPerson(name.toStdString(), "gender", "nationality", byear.toStdString(), dyear.toStdString());
    /*if(name == true)
    {
        return true;
    }
    return false;*/

 //ef validation er true þá vil ég kalla í service Newperson
 // ef  false þá kalla eg i error

    service.closeDatabase();
}
