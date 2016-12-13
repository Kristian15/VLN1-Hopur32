#include "addscientistdialog.h"
#include "ui_addscientistdialog.h"

AddScientistDialog::AddScientistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScientistDialog)
{
    _edit = false;

    ui->setupUi(this);
    ui->label_scientistHeader->setText("Add a new scientist");
}

AddScientistDialog::AddScientistDialog(Person person, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScientistDialog)
{
    _edit = true;

    ui->setupUi(this);
    ui->label_scientistHeader->setText("Edit scientist");

    _person = person;
    ui->label_scientistName->setText(QString::fromStdString(person.getName()));
    ui->label_scientistNationality->setText(QString::fromStdString(person.getNationality()));
    ui->label_scientistGender->setText(QString::fromStdString(person.getGender()));
    ui->label_scientistBirthYear->setText(QString::number(person.getByear()));
    ui->label_scientistDeathYear->setText(QString::number(person.getDyear()));
}

AddScientistDialog::~AddScientistDialog()
{
    delete ui;
}

void AddScientistDialog::on_button_ok_clicked()
{
    ui->label_scientistName_Error->setText("");
    ui->label_scientistNationality_Error->setText("");
    ui->label_scientistBirthYear_Error->setText("");
    ui->label_scientistDeathYear_Error->setText("");

    QString name = ui -> input_scientistName -> text();
    QString nationality = ui->input_scientistNationality->text();
    QString gender = ui->dropDown_scientistGender->currentText();
    QString byear = ui -> input_scientistBirthYear -> text();
    QString dyear = ui -> input_scientistDeathYear -> text();

    if(name.isEmpty())
    {
        ui->label_scientistName_Error->setText("<span style='color: #ED1C58'>Name cannot be empty</span>");
    }
    if(nationality.isEmpty())
    {
        ui->label_scientistNationality_Error->setText("<span style='color: #ED1C58'>Nationality cannot be empty</span>");
    }
    if(byear.isEmpty())
    {
        ui->label_scientistBirthYear_Error->setText("<span style='color: #ED1C58'>Birth year cannot be empty</span>");
    }
    if(dyear.isEmpty())
    {
        ui->label_scientistDeathYear_Error->setText("<span style='color: #ED1C58'>Death year cannot be empty</span>");
    }

    bool validscientistinput = service.validateNewPerson(name.toStdString(), nationality.toStdString(), byear.toStdString(), dyear.toStdString());

    if(validscientistinput)
    {
        if(_edit)
        {
            _person.setName(name.toStdString());
            _person.setNationality(nationality.toStdString());
            _person.setGender(gender.toStdString());
            _person.setByear(byear.toInt());
            _person.setDyear(dyear.toInt());

            servicelayer.updatePerson(_person);
        }
        else
        {
            service.newPerson(name.toStdString(), gender.toStdString(), nationality.toStdString(), byear.toStdString(), dyear.toStdString());

        }
        ui->input_scientistName->setText("");
        ui->input_scientistNationality->setText("");
        ui->input_scientistBirthYear->setText("");
        ui->input_scientistDeathYear->setText("");
        this->close();
    }
    else
    {
        ui->label_scientistInput_Error->setText("<span style='color: #ED1C58'>Check if years are less than current year</span>");
    }

}
