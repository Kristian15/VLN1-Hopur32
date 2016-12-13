#ifndef GETFACTS_H
#define GETFACTS_H

#include <QDialog>

namespace Ui {
class getFacts;
}

class getFacts : public QDialog
{
    Q_OBJECT

public:
    explicit getFacts(QWidget *parent = 0);
    ~getFacts();

private:
    Ui::getFacts *ui;
};

#endif // GETFACTS_H
