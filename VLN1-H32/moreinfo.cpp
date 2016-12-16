#include "moreinfo.h"
#include "ui_moreinfo.h"

/**
 * @brief MoreInfo::MoreInfo
 * @param parent
 */
MoreInfo::MoreInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MoreInfo)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString("..."));
}

/**
 * @brief MoreInfo::MoreInfo
 * @param person
 * @param parent
 */
MoreInfo::MoreInfo(Person person, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MoreInfo)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString("More information"));
    ui->label_name->setText(QString::fromStdString(person.getName()));
    table = "person";

    id = person.getID();
    setPhoto();
    facts = service.getFacts("person", id);

    setFirstFact();
}

/**
 * @brief MoreInfo::MoreInfo
 * @param computer
 * @param parent
 */
MoreInfo::MoreInfo(Computer computer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MoreInfo)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString("More information"));
    ui->label_name->setText(QString::fromStdString(computer.getName()));
    table = "computer";
    id = computer.getID();
    setPhoto();
    facts = service.getFacts("computer", id);

    setFirstFact();
}

/**
 * @brief MoreInfo::~MoreInfo
 */
MoreInfo::~MoreInfo()
{
    delete ui;
}

/**
 * @brief MoreInfo::on_button_addFact_clicked
 */
void MoreInfo::on_button_addFact_clicked()
{
    QString theFact = ui->textEdit_facts->toPlainText();
    string stheFact = theFact.toStdString();

    if(stheFact != "")
    {
        service.addFact(table, id, stheFact);

        facts.push_back(stheFact);
        ui->label_factAdded->setText("<span style='color: #009900'>Fact added !</span>");
        ui->button_nextFact->setEnabled(true);
        ui->button_addFact->setEnabled(false);
        ui->textEdit_facts->setReadOnly(true);
        setNext();
    }
}

/**
 * @brief MoreInfo::on_button_addPhoto_clicked
 */
void MoreInfo::on_button_addPhoto_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Select image to add"), "/home/", tr("Image Files (*.png *.jpg *.bmp)"));

    if(table == "person")
    {
        service.updatePersonImage(id, fileName.toStdString());
    }
    else
    {
        service.updateComputerImage(id, fileName.toStdString());
    }

    ui->button_addPhoto->setEnabled(false);
    ui->button_deletePhoto->setEnabled(true);
    setPhoto();
}

/**
 * @brief MoreInfo::on_button_deletePhoto_clicked
 */
void MoreInfo::on_button_deletePhoto_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation window", "Are you sure you want to delete?",
                                  QMessageBox::Yes|QMessageBox::No);

    if(reply == QMessageBox::Yes)
    {
        service.deleteImage(table, id);
        setPhoto();
        ui->button_addPhoto->setEnabled(true);
        ui->button_deletePhoto->setEnabled(false);
    }
}

/**
 * @brief MoreInfo::on_button_deleteFact_clicked
 */
void MoreInfo::on_button_deleteFact_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation window", "Are you sure you want to delete?",
                                  QMessageBox::Yes|QMessageBox::No);

    if(reply == QMessageBox::Yes)
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
}

/**
 * @brief MoreInfo::on_button_nextFact_clicked
 */
void MoreInfo::on_button_nextFact_clicked()
{
    ui->textEdit_facts->clear();
    ui->label_factAdded->clear();
    getNextFact();
}

/**
 * @brief MoreInfo::on_button_prevFact_clicked
 */
void MoreInfo::on_button_prevFact_clicked()
{
    ui->textEdit_facts->clear();
    ui->label_factAdded->clear();
    ui->button_addFact->setEnabled(false);
    getPrevFact();
}

/**
 * @brief MoreInfo::setPhoto
 */
void MoreInfo::setPhoto()
{
    QString path = QString::fromStdString(service.getImage(table, id));
    QFileInfo checkImage = path;

    if(checkImage.exists() && checkImage.isFile())
    {
        QPixmap pixmap(path);
        ui->image->setPixmap(pixmap);
        ui->image->setMask(pixmap.mask());
        ui->button_deletePhoto->setEnabled(true);
        ui->button_addPhoto->setEnabled(false);
    }
    else
    {
        QPixmap pixmap (".\\images\\noImage.jpg");
        ui->image->setPixmap(pixmap);
        ui->image->setMask(pixmap.mask());
        ui->button_deletePhoto->setEnabled(false);
        ui->button_addPhoto->setEnabled(true);
    }
}

/**
 * @brief MoreInfo::setFirstFact
 */
void MoreInfo::setFirstFact()
{
    index = 0;

    if((int)facts.size() > index)
    {
        ui->textEdit_facts->insertPlainText(QString::fromStdString(facts[index]));
    }
    else
    {
        ui->button_addFact->setEnabled(true);
        ui->textEdit_facts->setReadOnly(false);
        ui->button_nextFact->setEnabled(false);
        ui->button_prevFact->setEnabled(false);
    }
}

/**
 * @brief MoreInfo::setNext
 */
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

/**
 * @brief MoreInfo::getNextFact
 */
void MoreInfo::getNextFact()
{
    index++;

    if((int)facts.size() > index)
    {
        ui->textEdit_facts->insertPlainText(QString::fromStdString(facts[index]));
    }
    else if((int) facts.size() == 0)
    {
        ui->button_addFact->setEnabled(true);
        ui->textEdit_facts->setReadOnly(false);
        ui->button_nextFact->setEnabled(false);
        ui->button_prevFact->setEnabled(false);
    }

    if(!(index == 0))
    {
       ui->button_prevFact->setEnabled(true);
    }

    setNext();
}

/**
 * @brief MoreInfo::getPrevFact
 */
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
