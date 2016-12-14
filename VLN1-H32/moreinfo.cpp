#include "moreinfo.h"
#include "ui_moreinfo.h"

MoreInfo::MoreInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MoreInfo)
{
    ui->setupUi(this);
    //getFacts();
}

MoreInfo::MoreInfo(Person person, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MoreInfo)
{
    index = 0;
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString(person.getName()));
    ui->label_name->setText(QString::fromStdString(person.getName()));

    facts = service.getFacts("person", person.getID());
    ui->textEdit_facts->insertPlainText(QString::fromStdString(facts[index]));
    index ++;
}

MoreInfo::~MoreInfo()
{
    delete ui;
}
