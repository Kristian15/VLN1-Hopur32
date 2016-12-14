#ifndef EDITCOMPUTERDIALOG_H
#define EDITCOMPUTERDIALOG_H

#include <QDialog>

namespace Ui {
class EditComputerDialog;
}

class EditComputerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditComputerDialog(QWidget *parent = 0);
    ~EditComputerDialog();

private:
    Ui::EditComputerDialog *ui;
};

#endif // EDITCOMPUTERDIALOG_H
