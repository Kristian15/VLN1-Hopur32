#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    service.openDatabase();
    fillCompTable();
    fillSciTable();
    fillLinkTable();
    setTables();
}

/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    service.closeDatabase();
    ui->table_computers->clearContents();
    ui->table_links->clearContents();
    ui->table_scientists->clearContents();
    delete ui;
}

/**
 * @brief MainWindow::fillSciTable
 */
void MainWindow::fillSciTable()
{
    vector<Person> persons;
    persons = service.getAllPersons();
    fillSciTable(persons);
}

/**
 * @brief MainWindow::fillCompTable
 */
void MainWindow::fillCompTable()
{
    vector<Computer> computers;
    computers = service.getAllComputers();
    fillCompTable(computers);
}

/**
 * @brief MainWindow::fillLinkTable
 */
void MainWindow::fillLinkTable()
{
    vector<vector<int>> vec;
    vec = service.getAllLinks();
    fillLinkTable(vec);
}

/**
 * @brief MainWindow::on_button_addScientist_clicked
 */
void MainWindow::on_button_addScientist_clicked()
{
    AddScientistDialog addSci;
    addSci.exec();
    fillSciTable();
}

/**
 * @brief MainWindow::on_button_addComputer_clicked
 */
void MainWindow::on_button_addComputer_clicked()
{
    AddComputerDialog addComp;
    addComp.exec();
    fillCompTable();
}

/**
 * @brief MainWindow::on_button_addLink_clicked
 */
void MainWindow::on_button_addLink_clicked()
{
    AddLinkDialog addLink;
    addLink.exec();
    fillLinkTable();
}

/**
 * @brief MainWindow::on_button_editScientist_clicked
 */
void MainWindow::on_button_editScientist_clicked()
{
    int rowIndex = ui->table_scientists->selectionModel()->currentIndex().row();
    int id = ui->table_scientists->model()->data(ui->table_scientists->model()->index(rowIndex,5)).toInt();
    AddScientistDialog addSci(service.getPersonByID(id));
    addSci.exec();
    fillSciTable();
}

/**
 * @brief MainWindow::on_button_editComputer_clicked
 */
void MainWindow::on_button_editComputer_clicked()
{
    int rowIndex = ui->table_computers->selectionModel()->currentIndex().row();
    int id = ui->table_computers->model()->data(ui->table_computers->model()->index(rowIndex,4)).toInt();
    AddComputerDialog addComp(service.getComputerByID(id));
    addComp.exec();
    fillCompTable();
}

/**
 * @brief MainWindow::on_button_deleteScientist_clicked
 */
void MainWindow::on_button_deleteScientist_clicked()
{
    int currentlySelectePersonIndex = ui->table_scientists->currentIndex().row();
    int id = ui->table_scientists->model()->data(ui->table_scientists->model()->index(currentlySelectePersonIndex,5)).toInt();
    DeleteConfirmationDialog delornodel(id, 0, "person");
    delornodel.exec();
    ui->table_scientists->clearContents();
    fillSciTable();
}

/**
 * @brief MainWindow::on_button_deleteComputer_clicked
 */
void MainWindow::on_button_deleteComputer_clicked()
{
    int currentlySelectedComputerIndex = ui->table_computers->currentIndex().row();
    int id = ui->table_computers->model()->data(ui->table_computers->model()->index(currentlySelectedComputerIndex,4)).toInt();
    DeleteConfirmationDialog delornodel(id, 0, "computer");
    delornodel.exec();
    fillCompTable();
}

/**
 * @brief MainWindow::on_button_removeLink_clicked
 */
void MainWindow::on_button_removeLink_clicked()
{
    int currentlySelectedLinkIndex = ui->table_links->currentIndex().row();
    int personid = ui->table_links->model()->data(ui->table_links->model()->index(currentlySelectedLinkIndex,0)).toInt();
    int computerid = ui->table_links->model()->data(ui->table_links->model()->index(currentlySelectedLinkIndex,1)).toInt();
    DeleteConfirmationDialog delornodel(personid, computerid, "link");
    delornodel.exec();
    ui->table_links->clearContents();
    fillLinkTable();
}

/**
 * @brief MainWindow::on_button_scientistMoreInfo_clicked
 */
void MainWindow::on_button_scientistMoreInfo_clicked()
{
    int rowIndex = ui->table_scientists->selectionModel()->currentIndex().row();
    int id = ui->table_scientists->model()->data(ui->table_scientists->model()->index(rowIndex,5)).toInt();
    MoreInfo moreInf(service.getPersonByID(id));
    moreInf.exec();
}

/**
 * @brief MainWindow::on_button_computersMoreInfo_clicked
 */
void MainWindow::on_button_computersMoreInfo_clicked()
{
    int rowIndex = ui->table_computers->selectionModel()->currentIndex().row();
    int id = ui->table_computers->model()->data(ui->table_computers->model()->index(rowIndex,4)).toInt();
    MoreInfo moreInf(service.getComputerByID(id));
    moreInf.exec();
}

/**
 * @brief MainWindow::on_table_computers_clicked
 * @param index
 */
void MainWindow::on_table_computers_itemSelectionChanged()
{
    ui->button_editComputer->setEnabled(true);
    ui->button_deleteComputer->setEnabled(true);
    ui->button_computersMoreInfo->setEnabled(true);
}

/**
 * @brief MainWindow::on_table_scientists_itemSelectionChanged
 */
void MainWindow::on_table_scientists_itemSelectionChanged()
{
    ui->button_editScientist->setEnabled(true);
    ui->button_deleteScientist->setEnabled(true);
    ui->button_scientistMoreInfo->setEnabled(true);
}

/**
 * @brief MainWindow::on_table_links_itemSelectionChanged
 */
void MainWindow::on_table_links_itemSelectionChanged()
{
    ui->button_removeLink->setEnabled(true);
}

/**
 * @brief MainWindow::on_table_scientists_doubleClicked
 * @param index
 */
void MainWindow::on_table_scientists_doubleClicked(const QModelIndex &index)
{
    ui->button_scientistMoreInfo->clicked(true);
}

/**
 * @brief MainWindow::on_table_computers_doubleClicked
 * @param index
 */
void MainWindow::on_table_computers_doubleClicked(const QModelIndex &index)
{
    ui->button_computersMoreInfo->clicked(true);
}

/**
 * @brief MainWindow::on_input_scientistFilter_textChanged
 * @param arg1
 */
void MainWindow::on_input_scientistFilter_textChanged(const QString &arg1)
{
    string input = arg1.toStdString();
    vector<Person> persons = service.searchPersons(input);
    fillSciTable(persons);
}

/**
 * @brief MainWindow::on_input_computerFilter_textChanged
 * @param arg1
 */
void MainWindow::on_input_computerFilter_textChanged(const QString &arg1)
{
    string input = arg1.toStdString();
    vector<Computer> computers = service.searchComputers(input);
    fillCompTable(computers);
}

/**
 * @brief MainWindow::on_input_linksFilter_textChanged
 * @param arg1
 */
void MainWindow::on_input_linksFilter_textChanged(const QString &arg1)
{
    string input = arg1.toStdString();
    vector<vector<int>> vec = service.searchLinks(input);
    fillLinkTable(vec);
}

/**
 * @brief MainWindow::fillSciTable
 * @param persons
 */
void MainWindow::fillSciTable(vector<Person> persons)
{
    ui->table_scientists->clearContents();
    ui->table_scientists->setRowCount((int)persons.size());

    QString name, gender, nationality, birthYear, deathYear, id;

    for(int i = 0; i < (int)persons.size(); i++)
    {
        name = QString::fromStdString(persons[i].getName());
        gender = QString::fromStdString(persons[i].getGender());
        nationality = QString::fromStdString(persons[i].getNationality());
        birthYear = QString::number(persons[i].getByear());
        deathYear = QString::number(persons[i].getDyear());
        id = QString::number(persons[i].getID());

        if(deathYear == "0")
        {
            deathYear = "-";
        }

        ui->table_scientists->setItem(i, 0, new QTableWidgetItem(name));
        ui->table_scientists->setItem(i, 1, new QTableWidgetItem(gender));
        ui->table_scientists->setItem(i, 2, new QTableWidgetItem(nationality));
        ui->table_scientists->setItem(i, 3, new QTableWidgetItem(birthYear));
        ui->table_scientists->setItem(i, 4, new QTableWidgetItem(deathYear));
        ui->table_scientists->setItem(i, 5, new QTableWidgetItem(id));
    }
    ui->table_scientists->setColumnHidden(5, true);
    ui->button_editScientist->setEnabled(false);
    ui->button_deleteScientist->setEnabled(false);
    ui->button_scientistMoreInfo->setEnabled(false);
}

/**
 * @brief MainWindow::fillCompTable
 * @param computers
 */
void MainWindow::fillCompTable(vector<Computer> computers)
{
    ui->table_computers->clearContents();
    ui->table_computers->setRowCount((int)computers.size());

    QString name, designed, type, built, id;

    for(int i = 0; i < (int)computers.size(); i++)
    {
        name = QString::fromStdString(computers[i].getName());
        designed = QString::number(computers[i].getYear());
        type = QString::fromStdString(computers[i].getType());
        built = QString::number(computers[i].getBuilt());
        id = QString::number(computers[i].getID());

        if(built == "0")
        {
            built = "No";
        }
        else
        {
            built = "Yes";
        }

        ui->table_computers->setItem(i, 0, new QTableWidgetItem(name));
        ui->table_computers->setItem(i, 1, new QTableWidgetItem(type));
        ui->table_computers->setItem(i, 2, new QTableWidgetItem(designed));
        ui->table_computers->setItem(i, 3, new QTableWidgetItem(built));
        ui->table_computers->setItem(i, 4, new QTableWidgetItem(id));
    }

    ui->table_computers->setColumnHidden(4, true);
    ui->button_editComputer->setEnabled(false);
    ui->button_deleteComputer->setEnabled(false);
    ui->button_computersMoreInfo->setEnabled(false);
}

/**
 * @brief MainWindow::fillLinkTable
 * @param ids
 */
void MainWindow::fillLinkTable(vector<vector<int>> ids)
{
    ui->table_links->clearContents();
    ui->table_links->setRowCount((int)ids.size());

    QString personID, computerID, personName, computerName;

    for(int i = 0; i < (int)ids.size(); i++)
    {
        personID = QString::number(ids[i][0]);
        computerID = QString::number(ids[i][1]);
        personName = QString::fromStdString(service.getPersonByID(ids[i][0]).getName());
        computerName = QString::fromStdString(service.getComputerByID(ids[i][1]).getName());

        ui->table_links->setItem(i, 0, new QTableWidgetItem(personID));
        ui->table_links->setItem(i, 1, new QTableWidgetItem(computerID));
        ui->table_links->setItem(i, 2, new QTableWidgetItem(personName));
        ui->table_links->setItem(i, 3, new QTableWidgetItem(computerName));
    }

    ui->table_links->setColumnHidden(0, true);
    ui->table_links->setColumnHidden(1, true);
    ui->button_removeLink->setEnabled(false);
}

/**
 * @brief MainWindow::setTables
 */
void MainWindow::setTables()
{
    QHeaderView* header = ui->table_scientists->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    header = ui->table_computers->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    header = ui->table_links->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
}
