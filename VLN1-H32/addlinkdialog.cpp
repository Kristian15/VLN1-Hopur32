#include "addlinkdialog.h"
#include "ui_addlinkdialog.h"

AddLinkDialog::AddLinkDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddLinkDialog)
{
    ui->setupUi(this);
    a = false;
    fillCompTable();
    fillPersonTable();
}

AddLinkDialog::~AddLinkDialog()
{
    delete ui;
}

void AddLinkDialog::on_table_addLinkScientist_clicked(const QModelIndex &index)
{
    if(a)
    {
        ui->pushButton_2->setEnabled(true);
    }
    else
    {
        ui->label_linked->clear();
        a = true;
    }
}

void AddLinkDialog::on_table_addLinkComputer_clicked(const QModelIndex &index)
{
    if(a)
    {
        ui->pushButton_2->setEnabled(true);
    }
    else
    {
        a = true;
    }
}

void AddLinkDialog::on_pushButton_2_clicked()
{
    int sRowIndex = ui->table_addLinkScientist->selectionModel()->currentIndex().row();
    int personid = ui->table_addLinkScientist->model()->data(ui->table_addLinkScientist->model()->index(sRowIndex,0)).toInt();
    int cRowIndex = ui->table_addLinkComputer->selectionModel()->currentIndex().row();
    int computerid = ui->table_addLinkComputer->model()->data(ui->table_addLinkComputer->model()->index(cRowIndex,0)).toInt();
    service.link(personid, computerid);
    fillCompTable();
    fillPersonTable();
    ui->table_addLinkComputer->clearSelection();
    ui->table_addLinkScientist->clearSelection();
    ui->pushButton_2->setEnabled(false);
    ui->label_linked->setText("<span style='color: #009900'>Linked has been made !</span>");
}

void AddLinkDialog::fillCompTable()
{
    vector<Computer> computers;
    computers = service.getAllComputers();
    fillCompTable(computers);
}

void AddLinkDialog::fillCompTable(vector<Computer> computers)
{
    ui->table_addLinkComputer->setRowCount((int)computers.size());

    QString name, id;


    for(int i = 0; i < (int)computers.size(); i++)
    {
        name = QString::fromStdString(computers[i].getName());
        id = QString::number(computers[i].getID());

        ui->table_addLinkComputer->setItem(i, 0, new QTableWidgetItem(id));
        ui->table_addLinkComputer->setItem(i, 1, new QTableWidgetItem(name));
    }

    ui->table_addLinkComputer->setColumnHidden(0, true);

    a = false;
}

void AddLinkDialog::fillPersonTable()
{
    vector<Person> persons;
    persons = service.getAllPersons();
    fillPersonTable(persons);
}

void AddLinkDialog::fillPersonTable(vector<Person> persons)
{
    ui->table_addLinkScientist->setRowCount((int)persons.size());

    QString name, id;

    for(int i = 0; i < (int)persons.size(); i++)
    {
        name = QString::fromStdString(persons[i].getName());
        id = QString::number(persons[i].getID());

        ui->table_addLinkScientist->setItem(i, 0, new QTableWidgetItem(id));
        ui->table_addLinkScientist->setItem(i, 1, new QTableWidgetItem(name));
    }

    ui->table_addLinkScientist->setColumnHidden(0, true);
}

void AddLinkDialog::on_button_addLinkCancel_clicked()
{
    this->close();
}
