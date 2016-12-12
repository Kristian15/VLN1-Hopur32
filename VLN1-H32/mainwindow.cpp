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
    vector<Computer> computers;
    computers = service.sortComputers(1, 1);
    ui->table_computers->setRowCount(5);
    ui->table_computers->setItem(0,0,new QTableWidgetItem("Hello"));

    for(size_t i = 0; i < computers.size(); i++)
    {
        string test = computers[0].getName();
    }
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

void MainWindow::on_table_computers_activated(const QModelIndex &index)
{

}
