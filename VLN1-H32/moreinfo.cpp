#include "moreinfo.h"
#include "ui_moreinfo.h"
#include <QGraphicsItem>
#include <QBitmap>
#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>

MoreInfo::MoreInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MoreInfo)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString("..."));
}

MoreInfo::MoreInfo(Person person, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MoreInfo)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString("More information"));
    ui->label_name->setText(QString::fromStdString(person.getName()));
    table = "person";

    setPhoto();

    id = person.getID();
    facts = service.getFacts("person", id);

    setFirstFact();
}

MoreInfo::MoreInfo(Computer computer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MoreInfo)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString("More information"));
    ui->label_name->setText(QString::fromStdString(computer.getName()));
    table = "computer";

    setPhoto();

    id = computer.getID();
    facts = service.getFacts("computer", id);

    setFirstFact();
}

MoreInfo::~MoreInfo()
{
    delete ui;
}

void MoreInfo::setFirstFact()
{
    index = 0;

    if(facts.size() > index)
    {
        ui->textEdit_facts->insertPlainText(QString::fromStdString(facts[index]));
    }
}

void MoreInfo::setPhoto()
{
    QString path = ".\\images\\";
    QFileInfo checkImage = path; // = database path
    if(checkImage.exists() && checkImage.isFile())
    {
        QPixmap pixmap(".\\images\\random.jpg"); // todo fix path information using path from db
        ui->image->setPixmap(pixmap);
        ui->image->setMask(pixmap.mask());
        ui->button_deletePhoto->setEnabled(true);
    }
    else
    {
        QPixmap pixmap (".\\images\\noImage.jpg");
        ui->image->setPixmap(pixmap);
        ui->image->setMask(pixmap.mask());
        ui->button_deletePhoto->setEnabled(false);
    }
}

void MoreInfo::on_button_nextFact_clicked()
{
    ui->textEdit_facts->clear();
    ui->label_factAdded->clear();
    getNextFact();
}

void MoreInfo::getNextFact()
{
    index++;

    if((int)facts.size() > index)
    {
        ui->textEdit_facts->insertPlainText(QString::fromStdString(facts[index]));
        ui->button_prevFact->setEnabled(true);
    }

    setNext();
}

void MoreInfo::setNext()
{
    if((int)facts.size() <= index)
    {
        ui->button_nextFact->setEnabled(false);
        ui->button_deleteFact->setEnabled(false);
        ui->button_addFact->setEnabled(true);
        ui->textEdit_facts->clear();
        ui->textEdit_facts->setReadOnly(false);
    }
}

void MoreInfo::on_button_addFact_clicked()
{
    QString theFact = ui->textEdit_facts->toPlainText();
    string stheFact = theFact.toStdString();

    if(stheFact != "")
    {
        service.createFact(table, id, stheFact);

        facts.push_back(stheFact);
        ui->label_factAdded->setText("<span style='color: #009900'>Fact added !</span>");
        ui->button_nextFact->setEnabled(true);
        ui->button_addFact->setEnabled(false);
        ui->textEdit_facts->setReadOnly(true);
        setNext();
    }
}

void MoreInfo::on_button_addPhoto_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Select image to add"), "/home/", tr("Image Files (*.png *.jpg *.bmp)"));

    QFile::copy(fileName, ".\\images\\test.jpg");

    // todo function that saves image ath to db using selected person's id
}

void MoreInfo::on_button_deletePhoto_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation window", "Are you sure you want to delete?",
                                  QMessageBox::Yes|QMessageBox::No);
    ui->button_deletePhoto->setEnabled(false);
}

void MoreInfo::on_button_deleteFact_clicked()
{
    ui->textEdit_facts->clear();

    service.deleteFact(table, id, facts[index]);
    facts = service.getFacts(table, id);

    ui->label_factAdded->setText("<span style='color: #009900'>Fact deleted !</span>");
    ui->button_nextFact->setEnabled(true);
    ui->button_addFact->setEnabled(false);
    ui->textEdit_facts->setReadOnly(true);
    index--;
    getNextFact();
}

void MoreInfo::on_button_prevFact_clicked()
{
    ui->textEdit_facts->clear();
    ui->label_factAdded->clear();
    getPrevFact();
}

void MoreInfo::getPrevFact()
{
    index --;

    if(index >= 0)
    {
        ui->textEdit_facts->insertPlainText(QString::fromStdString(facts[index]));
        ui->button_nextFact->setEnabled(true);
        ui->button_deleteFact->setEnabled(true);
    }
    if(index == 0)
    {
        ui->button_prevFact->setEnabled(false);
    }
}
