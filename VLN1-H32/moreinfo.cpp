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

    if(facts.size() == 1)
    {
        ui->textEdit_facts->insertPlainText(QString::fromStdString(facts[index]));
        index ++;
    }
    else
    {
        ui->textEdit_facts->insertPlainText("No facts!!");
    }
}

MoreInfo::~MoreInfo()
{
    delete ui;
}

void MoreInfo::on_button_nextFact_clicked()
{
    if(facts.size() > index)
    {
        ui->textEdit_facts->insertPlainText(QString::fromStdString(facts[index]));
        index ++;
        setNext();
    }
    else
    {
        ui->textEdit_facts->insertPlainText("No facts!!");
    }
}

void MoreInfo::setNext()
{
    if(facts.size() <= index)
    {
        ui->button_nextFact->setEnabled(false);
    }
}
