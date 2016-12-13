#include "addcomputerdialog.h"
#include "ui_addcomputerdialog.h"

AddComputerDialog::AddComputerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputerDialog)
{
    ui->setupUi(this);
    ui->label_computerHeader->setText("Add a new computer");
}

AddComputerDialog::AddComputerDialog(Computer computer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputerDialog)
{
    ui->setupUi(this);
    ui->label_computerHeader->setText("Edit computer");

    ui->input_computerName->setText(QString::fromStdString(computer.getName()));
    ui->input_computerType->setText(QString::fromStdString(computer.getType()));
    ui->input_computerDesignYear->setText(QString::number(computer.getYear()));

    if(computer.getBuilt() == true)
    {
        ui->dropDown_computerBuilt->setCurrentIndex(0);
    }
    else
    {
        ui->dropDown_computerBuilt->setCurrentIndex(1);
    }
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
    ui->label_computerInput_Error->setText("");

    QString name = ui->input_computerName->text();
    QString type = ui->input_computerType->text();
    QString year = ui->input_computerDesignYear->text();
    QString built = ui->dropDown_computerBuilt->currentText();

    if(name.isEmpty())
    {
        ui->label_computerName_Error->setText("<span style='color: #ED1C58'>Name cannot be empty</span>");
    }
    if(type.isEmpty())
    {
        ui->label_computerType_Error->setText("<span style='color: #ED1C58'>Type cannot be empty</span>");
    }
    if(year.isEmpty())
    {
        ui->label_computerDesignYear_Error->setText("<span style='color: #ED1C58'>Year cannot be empty</span>");
    }

    bool validcomputerinput = servicelayer.validateNewComputer(name.toStdString(), year.toStdString(), type.toStdString());

    if(validcomputerinput)
    {
        servicelayer.newComputer(name.toStdString(), year.toStdString(),
                             type.toStdString(), built.toStdString());
        ui->input_computerName->setText("");
        ui->input_computerType->setText("");
        ui->input_computerDesignYear->setText("");
        this->close();
    }
    else if (!validcomputerinput && !name.isEmpty() && !type.isEmpty())
    {
        ui->label_computerInput_Error->setText("<span style='color: #ED1C58'>Check if design year is less than current year</span>");
    }
}

void AddComputerDialog::on_button_cancel_clicked()
{
    this->close();
}

void AddComputerDialog::displayAllComputers()
{
    vector<Computer> computers = servicelayer.sortComputers(1,1);
    displayComputers(computers);
}

void AddComputerDialog::displayComputers(vector<Computer> computers)
{
    ui ->listComputers->clear();
    for (unsigned int i = 0; i < computers.size(); i++)
    {
        Computer currentcomputer = computers[i];
        ui->listComputers->addItem(QString::fromStdString(currentcomputer.getName()));
    }
}

