#include "moreinfo.h"
#include "ui_moreinfo.h"

MoreInfo::MoreInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MoreInfo)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString("..."));
    //getFacts();
}

MoreInfo::MoreInfo(Person person, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MoreInfo)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString("More information"));
    ui->label_name->setText(QString::fromStdString(person.getName()));

    index = 0;
    facts = service.getFacts("person", person.getID());
    setNext();

    if(facts.size() > 0)
    {
        ui->textEdit_facts->insertPlainText(QString::fromStdString(facts[index]));
        index ++;
    }

    setNext();
}

MoreInfo::~MoreInfo()
{
    delete ui;
}

void MoreInfo::on_button_nextFact_clicked()
{
    ui->textEdit_facts->clear();

    if(facts.size() > index)
    {
        ui->textEdit_facts->insertPlainText(QString::fromStdString(facts[index]));
        index ++;
    }

    setNext();
}

void MoreInfo::setNext()
{
    if(facts.size() <= index)
    {
        ui->button_nextFact->setEnabled(false);
        ui->button_addFact->setEnabled(true);
    }
}

void MoreInfo::on_button_addFact_clicked()
{

}
