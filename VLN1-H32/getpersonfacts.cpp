#include "getpersonfacts.h"
#include "ui_getpersonfacts.h"

getPersonFacts::getPersonFacts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getPersonFacts)
{
    ui->setupUi(this);
}

getPersonFacts::~getPersonFacts()
{
    delete ui;
}
