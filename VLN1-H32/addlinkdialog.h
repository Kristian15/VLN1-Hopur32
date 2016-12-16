#ifndef ADDLINKDIALOG_H
#define ADDLINKDIALOG_H

#include <QDialog>
#include "servicelayer.h"

namespace Ui {
class AddLinkDialog;
}

class AddLinkDialog : public QDialog
{
    Q_OBJECT

public:
    // constructor
    explicit AddLinkDialog(QWidget *parent = 0);
    // destructor
    ~AddLinkDialog();
    void fillPersonTable();
    void fillComputerTable();

private slots:
    void on_table_addLinkComputer_itemSelectionChanged();
    void on_table_addLinkScientist_itemSelectionChanged();
    void on_button_addLinkLink_clicked();
    void on_button_addLinkCancel_clicked();
    void on_input_filterScientists_textChanged(const QString &arg1);
    void on_input_filterComputers_textChanged(const QString &arg1);

private:
    // conn is true if user has chosen one scientist or computer
    bool conn;
    Ui::AddLinkDialog *ui;
    serviceLayer service;
    // fill the tables to choose from
    void fillPersonTable(vector<Person> persons);
    void fillComputerTable(vector<Computer> computers);
};

#endif // ADDLINKDIALOG_H
