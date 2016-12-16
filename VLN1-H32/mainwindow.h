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
    // constructor
    explicit MainWindow(QWidget *parent = 0);
    // destructor
    ~MainWindow();
    // fill tables
    void fillCompTable();
    void fillSciTable();
    void fillLinkTable();

private slots:
    void on_button_addScientist_clicked();
    void on_button_addComputer_clicked();
    void on_button_addLink_clicked();
    void on_button_editScientist_clicked();
    void on_button_editComputer_clicked();
    void on_button_deleteScientist_clicked();
    void on_button_deleteComputer_clicked();
    void on_button_removeLink_clicked();
    void on_button_scientistMoreInfo_clicked();
    void on_button_computersMoreInfo_clicked();
    void on_table_computers_clicked(const QModelIndex &index);
    void on_table_scientists_itemSelectionChanged();
    void on_table_links_itemSelectionChanged();
    void on_table_scientists_doubleClicked(const QModelIndex &index);
    void on_table_computers_doubleClicked(const QModelIndex &index);
    void on_input_scientistFilter_textChanged(const QString &arg1);
    void on_input_computerFilter_textChanged(const QString &arg1);
    void on_input_linksFilter_textChanged(const QString &arg1);

private:
    serviceLayer service;
    Ui::MainWindow *ui;
    AddLinkDialog addLink;
    void fillCompTable(vector<Computer> computers);
    void fillSciTable(vector<Person> persons);
    void fillLinkTable(vector<vector<int>>);
    // sets columns width in tables
    void setTables();
};

#endif // MAINWINDOW_H
