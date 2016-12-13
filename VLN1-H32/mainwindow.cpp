#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    bool temp = service.openDatabase();

    ui->setupUi(this);

    fillCompTable();
    fillSciTable();

}

MainWindow::~MainWindow()
{
    service.closeDatabase();
    ui->table_computers->clearContents();
    ui->table_links->clearContents();
    ui->table_scientists->clearContents();
    delete ui;
}

void MainWindow::fillCompTable()
{
    vector<Computer> computers;
    computers = service.sortComputers(1, 1);
    ui->table_computers->setRowCount((int)computers.size());

    QString name, designed, type, built, id;


    for(int i = 0; i < (int)computers.size(); i++)
    {
        name = QString::fromStdString(computers[i].getName());
        designed = QString::number(computers[i].getYear());
        type = QString::fromStdString(computers[i].getType());
        built = QString::number(computers[i].getBuilt());
        id = QString::number(computers[i].getID());

        ui->table_computers->setItem(i, 0, new QTableWidgetItem(name));
        ui->table_computers->setItem(i, 1, new QTableWidgetItem(type));
        ui->table_computers->setItem(i, 2, new QTableWidgetItem(designed));
        ui->table_computers->setItem(i, 3, new QTableWidgetItem(built));
        ui->table_computers->setItem(i, 4, new QTableWidgetItem(id));
    }
    ui->table_computers->setColumnHidden(4, true);
}

void MainWindow::fillSciTable()
{
    vector<Person> persons;
    persons = service.sortPersons(1, 1);
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


        ui->table_scientists->setItem(i, 0, new QTableWidgetItem(name));
        ui->table_scientists->setItem(i, 1, new QTableWidgetItem(gender));
        ui->table_scientists->setItem(i, 2, new QTableWidgetItem(nationality));
        ui->table_scientists->setItem(i, 3, new QTableWidgetItem(birthYear));
        ui->table_scientists->setItem(i, 4, new QTableWidgetItem(deathYear));
        ui->table_scientists->setItem(i, 5, new QTableWidgetItem(id));
    }
    ui->table_scientists->setColumnHidden(5, true);
}

void MainWindow::fillLinkTable()
{

}

void MainWindow::on_button_addComputer_clicked()
{
    AddComputerDialog addComp;

    addComp.exec();
    ui->table_computers->clearContents();
    fillCompTable();
    ui->button_editComputer->setEnabled(false);
    ui->button_deleteComputer->setEnabled(false);
}

void MainWindow::on_button_addScientist_clicked()
{
    AddScientistDialog addSci;

    addSci.exec();
    ui->table_scientists->clearContents();
    fillSciTable();

    ui->button_editScientist->setEnabled(false);
    ui->button_deleteScientist->setEnabled(false);
}

void MainWindow::on_button_editComputer_clicked()
{
    int rowIndex = ui->table_computers->selectionModel()->currentIndex().row();
    int id = ui->table_computers->model()->data(ui->table_computers->model()->index(rowIndex,4)).toInt();

    AddComputerDialog addComp(service.getCompByID(id));

    addComp.exec();
    ui->table_computers->clearContents();
    fillCompTable();
}

void MainWindow::on_button_editScientist_clicked()
{
    int rowIndex = ui->table_scientists->selectionModel()->currentIndex().row();
    int id = ui->table_scientists->model()->data(ui->table_scientists->model()->index(rowIndex,5)).toInt();

    AddScientistDialog addSci(service.getPersonByID(id));

    addSci.exec();

    ui->table_scientists->clearContents();
    fillSciTable();
    ui->button_editScientist->setEnabled(false);
    ui->button_deleteScientist->setEnabled(false);
}

void MainWindow::on_button_addLink_clicked()
{
    addLink.show();
}

void MainWindow::on_table_computers_clicked(const QModelIndex &index)
{
    ui->button_editComputer->setEnabled(true);
    ui->button_deleteComputer->setEnabled(true);
}

void MainWindow::on_button_deleteComputer_clicked()
{
    int currentlySelectedComputerIndex = ui->table_computers->currentIndex().row();
    int id = ui->table_computers->model()->data(ui->table_computers->model()->index(currentlySelectedComputerIndex,4)).toInt();
    DeleteConfirmationDialog delornodel(id, "computer");
    delornodel.exec();
    fillCompTable();
}

void MainWindow::on_table_scientists_itemSelectionChanged()
{
    ui->button_editScientist->setEnabled(true);
    ui->button_deleteScientist->setEnabled(true);
}

void MainWindow::on_button_deleteScientist_clicked()
{
    int currentlySelectePersonIndex = ui->table_scientists->currentIndex().row();
    int id = ui->table_scientists->model()->data(ui->table_scientists->model()->index(currentlySelectePersonIndex,5)).toInt();
    DeleteConfirmationDialog delornodel(id, "person");
    delornodel.exec();
    ui->table_scientists->clearContents();
    fillSciTable();
}
