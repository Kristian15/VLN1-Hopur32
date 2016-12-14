#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "computer.h"
#include "servicelayer.h"
#include "addscientistdialog.h"
#include "addcomputerdialog.h"
#include "addlinkdialog.h"
#include "deleteconfirmationdialog.h"
#include "moreinfo.h"


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

    void on_table_scientists_itemSelectionChanged();

    void on_button_deleteScientist_clicked();

    void on_input_computerFilter_textChanged(const QString &arg1);
    void on_input_scientistFilter_textChanged(const QString &arg1);
    void fillCompTable(vector<Computer> computers);
    void fillSciTable(vector<Person> persons);
    void fillLinkTable(vector<vector<int>>);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    void fillCompTable();
    void fillSciTable();
    void fillLinkTable();
    serviceLayer service;
    Computer computer;
    Ui::MainWindow *ui;
    AddLinkDialog addLink;
};

#endif // MAINWINDOW_H
