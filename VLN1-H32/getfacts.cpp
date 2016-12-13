#include "getfacts.h"
#include "ui_getfacts.h"

getFacts::getFacts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getFacts)
{
    ui->setupUi(this);
}

getFacts::~getFacts()
{
    delete ui;
}
