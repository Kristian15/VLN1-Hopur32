#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    populateTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::populateTable()
{
    bool temp = service.openDatabase();
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
        ui->table_computers->setItem(i, 0, new QTableWidgetItem(designed));
        ui->table_computers->setItem(i, 0, new QTableWidgetItem(type));
        ui->table_computers->setItem(i, 0, new QTableWidgetItem(built));
    }
    service.closeDatabase();
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
