#include "addscientistdialog.h"
#include "ui_addscientistdialog.h"

AddScientistDialog::AddScientistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScientistDialog)
{
    _edit = false;

    ui->setupUi(this);
    this->setWindowTitle("Add scientist");
    ui->label_scientistHeader->setText("Add a new scientist");
    service.addImage("Person", _person.getID());
}

AddScientistDialog::AddScientistDialog(Person person, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScientistDialog)
{
    _edit = true;

    ui->setupUi(this);
    this->setWindowTitle("Edit Scientist");
    ui->label_scientistHeader->setText(QString::fromStdString(person.getName()));

    _person = person;
    ui->input_scientistName->setText(QString::fromStdString(_person.getName()));
    ui->input_scientistNationality->setText(QString::fromStdString(_person.getNationality()));
    if(person.getGender() == "female")
    {
        ui->dropDown_scientistGender->setCurrentIndex(0);
    }
    else
    {
        ui->dropDown_scientistGender->setCurrentIndex(1);
    }
    ui->input_scientistBirthYear->setText(QString::number(_person.getByear()));
    ui->input_scientistDeathYear->setText(QString::number(_person.getDyear()));
}

AddScientistDialog::~AddScientistDialog()
{
    delete ui;
}

void AddScientistDialog::on_button_ok_clicked()
{
    bool isValid = true;

    ui->label_scientistName_Error->clear();
    ui->label_scientistNationality_Error->clear();
    ui->label_scientistBirthYear_Error->clear();
    ui->label_scientistDeathYear_Error->clear();

    QString qName = ui -> input_scientistName -> text();
    QString qNationality = ui-> input_scientistNationality->text();
    QString qGender = ui->dropDown_scientistGender->currentText();
    QString qByear = ui -> input_scientistBirthYear -> text();
    QString qDyear = ui -> input_scientistDeathYear -> text();

    string name = qName.toStdString();
    string nationality = qNationality.toStdString();
    string gender = qGender.toStdString();
    string byear = qByear.toStdString();
    string dyear = qDyear.toStdString();

    if(qName.isEmpty())
    {
        ui->label_scientistName_Error->setText("<span style='color: #ED1C58'>Name cannot be empty</span>");
        isValid = false;
    }
    if(qNationality.isEmpty())
    {
        ui->label_scientistNationality_Error->setText("<span style='color: #ED1C58'>Nationality cannot be empty</span>");
        isValid = false;
    }
    if(qByear.isEmpty())
    {
        ui->label_scientistBirthYear_Error->setText("<span style='color: #ED1C58'>Birth year cannot be empty</span>");
        isValid = false;
    }
    if(qDyear.isEmpty())
    {
        dyear = "-";
    }

    bool validScientistInput = service.validateNewPerson(name, nationality, byear, dyear);

    if(validScientistInput && isValid)
    {
        if(_edit)
        {
            _person.setName(name);
            _person.setNationality(nationality);
            _person.setGender(gender);
            _person.setByear(stoi(byear));
            _person.setDyear(stoi(dyear));

            service.updatePerson(_person);
        }
        else
        {
            service.newPerson(name, gender, nationality, byear, dyear);

        }

        ui->input_scientistName->clear();
        ui->input_scientistNationality->clear();
        ui->input_scientistBirthYear->clear();
        ui->input_scientistDeathYear->clear();
        this->close();
    }
    else
    {
        ui->label_scientistInput_Error->setText("<span style='color: #ED1C58'>Invalid Input</span>");
    }

}

void AddScientistDialog::on_button_cancel_clicked()
{
    this->close();
}
