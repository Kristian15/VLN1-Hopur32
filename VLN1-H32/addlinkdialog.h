#ifndef ADDLINKDIALOG_H
#define ADDLINKDIALOG_H

#include <QDialog>

namespace Ui {
class AddLinkDialog;
}

class AddLinkDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddLinkDialog(QWidget *parent = 0);
    ~AddLinkDialog();

private:
    Ui::AddLinkDialog *ui;
};

#endif // ADDLINKDIALOG_H
