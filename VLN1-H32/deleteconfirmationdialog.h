#ifndef DELETECONFIRMATIONDIALOG_H
#define DELETECONFIRMATIONDIALOG_H

#include <QDialog>

namespace Ui {
class DeleteConfirmationDialog;
}

class DeleteConfirmationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteConfirmationDialog(QWidget *parent = 0);
    ~DeleteConfirmationDialog();

private:
    Ui::DeleteConfirmationDialog *ui;
};

#endif // DELETECONFIRMATIONDIALOG_H
