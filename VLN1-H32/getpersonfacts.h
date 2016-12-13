#ifndef GETPERSONFACTS_H
#define GETPERSONFACTS_H

#include <QDialog>

namespace Ui {
class getPersonFacts;
}

class getPersonFacts : public QDialog
{
    Q_OBJECT

public:
    explicit getPersonFacts(QWidget *parent = 0);
    ~getPersonFacts();

private:
    Ui::getPersonFacts *ui;
};

#endif // GETPERSONFACTS_H
