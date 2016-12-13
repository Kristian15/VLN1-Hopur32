#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "computer.h"
#include "servicelayer.h"
#include "addscientistdialog.h"
#include "addcomputerdialog.h"
#include "addlinkdialog.h"
#include "editscientistdialog.h"
#include "editcomputerdialog.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_button_addScientist_clicked();

    void on_button_addComputer_clicked();

    void on_button_editComputer_clicked();

    void on_button_editScientist_clicked();

    void on_button_addLink_clicked();

    void on_button_deleteComputer_clicked();

    void on_table_computers_clicked(const QModelIndex &index);

private:
    void fillCompTable();
    void fillSciTable();
    void fillLinkTable();
    serviceLayer service;
    Computer computer;
    Ui::MainWindow *ui;
    AddScientistDialog addSci;
    AddComputerDialog addComp;
    EditComputerDialog editComp;
    EditScientistDialog editSci;
    AddLinkDialog addLink;
    vector<Computer> currentlyDisplayedComputers;
};

#endif // MAINWINDOW_H
