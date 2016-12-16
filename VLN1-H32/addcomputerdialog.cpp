#include "addcomputerdialog.h"
#include "ui_addcomputerdialog.h"

/**
 * @brief AddComputerDialog::AddComputerDialog
 * @param parent
 */
AddComputerDialog::AddComputerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputerDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Add computer");
    ui->label_computerHeader->setText("Add a new computer");
}

/**
 * @brief AddComputerDialog::AddComputerDialog
 * @param computer
 * @param parent
 */
AddComputerDialog::AddComputerDialog(Computer computer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputerDialog)
{
    _edit = true;

    ui->setupUi(this);
    this->setWindowTitle("Edit computer");
    ui->label_computerHeader->setText(QString::fromStdString(computer.getName()));

    _computer = computer;
    ui->input_computerName->setText(QString::fromStdString(_computer.getName()));
    ui->input_computerType->setText(QString::fromStdString(_computer.getType()));
    ui->input_computerDesignYear->setText(QString::number(_computer.getYear()));

    if(computer.getBuilt() == true)
    {
        ui->dropDown_computerBuilt->setCurrentIndex(0);
    }
    else
    {
        ui->dropDown_computerBuilt->setCurrentIndex(1);
    }
}

/**
 * @brief AddComputerDialog::~AddComputerDialog
 */
AddComputerDialog::~AddComputerDialog()
{
    delete ui;
}

/**
 * @brief AddComputerDialog::on_button_ok_clicked
 */
void AddComputerDialog::on_button_ok_clicked()
{
    bool isValid = true;

    ui->label_computerName_Error->clear();
    ui->label_computerType_Error->clear();
    ui->label_computerDesignYear_Error->clear();
    ui->label_computerInput_Error->clear();

    QString qName = ui->input_computerName->text();
    QString qType = ui->input_computerType->text();
    QString qYear = ui->input_computerDesignYear->text();
    QString qBuilt = ui->dropDown_computerBuilt->currentText();

    string name = qName.toStdString();
    string type = qType.toStdString();
    string year = qYear.toStdString();
    string built = qBuilt.toStdString();

    if(qName.isEmpty())
    {
        ui->label_computerName_Error->setText("<span style='color: #ED1C58'>Name cannot be empty</span>");
        isValid = false;
    }
    if(qType.isEmpty())
    {
        ui->label_computerType_Error->setText("<span style='color: #ED1C58'>Type cannot be empty</span>");
        isValid = false;
    }
    if(qYear.isEmpty())
    {
        ui->label_computerDesignYear_Error->setText("<span style='color: #ED1C58'>Year cannot be empty</span>");
        isValid = false;
    }

    bool validComputerInput = service.validateNewComputer(year);

    if(validComputerInput && isValid)
    {
        if(_edit)
        {
            _computer.setName(name);
            _computer.setType(type);
            _computer.setYear(stoi(year));
            _computer.setBuilt(stoi(built));

            service.updateComputer(_computer);
        }
        else
        {
            service.newComputer(name, year, type, built);
            service.addImage("Computer", _computer.getID());
        }

        ui->input_computerName->clear();
        ui->input_computerType->clear();
        ui->input_computerDesignYear->clear();
        this->close();
    }
    else
    {
        ui->label_computerInput_Error->setText("<span style='color: #ED1C58'>Invalid input</span>");
    }
}

/**
 * @brief AddComputerDialog::on_button_cancel_clicked
 */
void AddComputerDialog::on_button_cancel_clicked()
{
    this->close();
}
