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
    explicit AddLinkDialog(QWidget *parent = 0);
    ~AddLinkDialog();
    void fillCompTable();
    void fillCompTable(vector<Computer> computers);
    void fillPersonTable();
    void fillPersonTable(vector<Person> persons);

private slots:
    void on_table_addLinkComputer_clicked(const QModelIndex &index);
    void on_table_addLinkScientist_clicked(const QModelIndex &index);
    void on_button_addLinkLink_clicked();

    void on_button_addLinkCancel_clicked();

private:
    bool conn;
    Ui::AddLinkDialog *ui;
    serviceLayer service;
};

#endif // ADDLINKDIALOG_H
