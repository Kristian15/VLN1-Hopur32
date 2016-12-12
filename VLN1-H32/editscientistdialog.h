#ifndef EDITSCIENTISTDIALOG_H
#define EDITSCIENTISTDIALOG_H

#include <QDialog>

namespace Ui {
class EditScientistDialog;
}

class EditScientistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditScientistDialog(QWidget *parent = 0);
    ~EditScientistDialog();

private:
    Ui::EditScientistDialog *ui;
};

#endif // EDITSCIENTISTDIALOG_H
