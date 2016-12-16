#include "addlinkdialog.h"
#include "ui_addlinkdialog.h"

/**
 * @brief AddLinkDialog::AddLinkDialog
 * @param parent
 */
AddLinkDialog::AddLinkDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddLinkDialog)
{
    ui->setupUi(this);
    conn = false;
    fillCompTable();
    fillPersonTable();
}

/**
 * @brief AddLinkDialog::~AddLinkDialog
 */
AddLinkDialog::~AddLinkDialog()
{
    delete ui;
}

/**
 * @brief AddLinkDialog::on_table_addLinkScientist_itemSelectionChanged
 */
void AddLinkDialog::on_table_addLinkScientist_itemSelectionChanged()
{
    if(conn)
    {
        ui->button_addLinkLink->setEnabled(true);
    }
    else
    {
        conn = true;
        ui->label_linked->clear();
    }
}

/**
 * @brief AddLinkDialog::on_table_addLinkComputer_itemSelectionChanged
 */
void AddLinkDialog::on_table_addLinkComputer_itemSelectionChanged()
{
    if(conn)
    {
        ui->button_addLinkLink->setEnabled(true);
    }
    else
    {
        conn = true;
        ui->label_linked->clear();
    }
}

/**
 * @brief AddLinkDialog::on_button_addLinkLink_clicked
 */
void AddLinkDialog::on_button_addLinkLink_clicked()
{
    int sRowIndex = ui->table_addLinkScientist->selectionModel()->currentIndex().row();
    int personID = ui->table_addLinkScientist->model()->data(ui->table_addLinkScientist->model()->index(sRowIndex,0)).toInt();
    int cRowIndex = ui->table_addLinkComputer->selectionModel()->currentIndex().row();
    int computerID = ui->table_addLinkComputer->model()->data(ui->table_addLinkComputer->model()->index(cRowIndex,0)).toInt();

    if(service.ifLinked(personID, computerID))
    {
        ui->label_linked->setText("<span style='color: #ED1C58'>Link already exists</span>");
        ui->table_addLinkComputer->clearSelection();
        ui->table_addLinkScientist->clearSelection();
        conn = false;
    }
    else
    {
        service.addLink(personID, computerID);
        this->close();
    }

    ui->button_addLinkLink->setEnabled(false);
}

/**
 * @brief AddLinkDialog::on_button_addLinkCancel_clicked
 */
void AddLinkDialog::on_button_addLinkCancel_clicked()
{
    this->close();
}

/**
 * @brief AddLinkDialog::fillPersonTable
 */
void AddLinkDialog::fillPersonTable()
{
    vector<Person> persons;
    persons = service.getAllPersons();
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

/**
 * @brief AddLinkDialog::fillCompTable
 */
void AddLinkDialog::fillCompTable()
{
    vector<Computer> computers;
    computers = service.getAllComputers();
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
}
