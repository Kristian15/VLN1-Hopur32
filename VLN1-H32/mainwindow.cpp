#include "mainwindow.h"
#include "ui_mainwindow.h"

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

    QString name, designed, type, built;


    for(int i = 0; i < (int)computers.size(); i++)
    {
        name = QString::fromStdString(computers[i].getName());
        designed = QString::number(computers[i].getYear());
        type = QString::fromStdString(computers[i].getType());
        built = QString::number(computers[i].getBuilt());

        ui->table_computers->setItem(i, 0, new QTableWidgetItem(name));
        ui->table_computers->setItem(i, 1, new QTableWidgetItem(type));
        ui->table_computers->setItem(i, 2, new QTableWidgetItem(designed));
        ui->table_computers->setItem(i, 3, new QTableWidgetItem(built));
    }
}

void MainWindow::fillSciTable()
{
    vector<Person> persons;
    persons = service.sortPersons(1, 1);
    ui->table_scientists->setRowCount((int)persons.size());

    QString name, gender, nationality, birthYear, deathYear;

    for(int i = 0; i < (int)persons.size(); i++)
    {
        name = QString::fromStdString(persons[i].getName());
        gender = QString::fromStdString(persons[i].getGender());
        nationality = QString::fromStdString(persons[i].getNationality());
        birthYear = QString::number(persons[i].getByear());
        deathYear = QString::number(persons[i].getDyear());


        ui->table_scientists->setItem(i, 0, new QTableWidgetItem(name));
        ui->table_scientists->setItem(i, 1, new QTableWidgetItem(gender));
        ui->table_scientists->setItem(i, 2, new QTableWidgetItem(nationality));
        ui->table_scientists->setItem(i, 3, new QTableWidgetItem(birthYear));
        ui->table_scientists->setItem(i, 4, new QTableWidgetItem(deathYear));
    }
}

void MainWindow::fillLinkTable()
{

}

void MainWindow::on_button_addComputer_clicked()
{
    addComp.show();
}

void MainWindow::on_button_addScientist_clicked()
{
    addSci.show();
}

void MainWindow::on_button_editComputer_clicked()
{
    editComp.show();
}

void MainWindow::on_button_editScientist_clicked()
{
    editSci.show();
}

void MainWindow::on_button_addLink_clicked()
{
    addLink.show();
}
