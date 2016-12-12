#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
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
