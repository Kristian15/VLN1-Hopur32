#include "datalayer.h"
#include <iostream>

// **** Private ****

void dataLayer::addNewPerson(Person addMe)
{
    QSqlQuery query;
    query.prepare("INSERT INTO person (Name, Gender, Nationality, BirthYear, DeathYear) "
                 "VALUES (:name, :gender, :nationality, :byear, :dyear)");
    query.bindValue(":name", QString::fromStdString(addMe.getName()));
    query.bindValue(":gender", QString::fromStdString(addMe.getGender()));
    query.bindValue(":nationality", QString::fromStdString(addMe.getNationality()));
    query.bindValue(":byear", addMe.getByear());

    if(addMe.getDyear() != 0)
    {
       query.bindValue(":dyear", addMe.getDyear());
    }
    else
    {
       query.bindValue(":dyear", "");
    }

    query.exec();

}

void dataLayer::addNewComputer(Computer addMe)
{
    QSqlQuery query;
    query.prepare("INSERT INTO computer (Name, Year, Type, Built) "
                 "VALUES (:name, :year, :type, :built)");
    query.bindValue(":name", QString::fromStdString(addMe.getName()));
    query.bindValue(":year", addMe.getYear());
    query.bindValue(":type", QString::fromStdString(addMe.getType()));
    query.bindValue(":built",addMe.getBuilt());
    query.exec();
}

void dataLayer::createRelation(int personID, int computerID)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Person_Computer (PersonID, ComputerID) "
                  "VALUES (:personID, :computerID)");
    query.bindValue(":personID", personID);
    query.bindValue(":computerID", computerID);
    query.exec();
}

void dataLayer::createPersonFact(int personID, string fact)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Person_Fact (PersonID, Fact) "
                  "VALUES (:personID, :fact)");
    query.bindValue(":personID", personID);
    query.bindValue(":fact", QString::fromStdString(fact));
    query.exec();
}

void dataLayer ::createComputerFact(int computerID, string fact)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Computer_Fact (ComputerID, Fact) "
                  "VALUES (:computerID, :fact)");
    query.bindValue(":computerID", computerID);
    query.bindValue(":fact", QString::fromStdString(fact));
    query.exec();
}

vector<Person> dataLayer::getPersons(QString queryString)
{
    vector<Person> persons;

    QSqlQuery query;
    query.exec(queryString);

    while(query.next())
    {
        Person person(
                    query.value("ID").toInt(),
                    query.value("Name").toString().toStdString(),
                    query.value("Gender").toString().toStdString(),
                    query.value("Nationality").toString().toStdString(),
                    query.value("BirthYear").toInt(),
                    query.value("DeathYear").toInt());
        persons.push_back(person);
    }

    return persons;
}

vector<Computer> dataLayer::getComputers(QString queryString)
{
    vector<Computer> computers;

    QSqlQuery query;
    query.exec(queryString);

    while (query.next())
    {
        Computer computer(
                    query.value("ID").toInt(),
                    query.value("Name").toString().toStdString(),
                    query.value("Year").toInt(),
                    query.value("Type").toString().toStdString(),
                    query.value("Built").toBool());
        computers.push_back(computer);
    }

    return computers;
}

void dataLayer::deleteRow(string table, int id)
{
    QString qTable = QString::fromStdString(table);

    QSqlQuery query;
    query.prepare("DELETE FROM " + qTable + " WHERE ID = :id ");
    query.bindValue(":id", id);
    query.exec();

    qTable.append("ID");

    QSqlQuery query2;
    query2.prepare("DELETE FROM Person_Computer WHERE " + qTable + " = :id");
    query2.bindValue(":id", id);
    query2.exec();
}

void dataLayer::deleteRelation(int personID, int computerID)
{
    QString qPersID = QString::number(personID);
    QString qCompID = QString::number(computerID);
    QSqlQuery query;
    query.prepare("DELETE FROM Person_Computer WHERE PersonID = " +
                  qPersID + " AND computerID = " + qCompID);
    query.exec();
}

void dataLayer::deleteFact(QString queryString)
{
    QSqlQuery query;
    query.exec(queryString);
}

// **** Public ****

dataLayer::dataLayer()
{

}

dataLayer::~dataLayer()
{
    db.close();
}

bool dataLayer::openDatabase()
{
    db = QSqlDatabase::addDatabase(DB_DRIVER_TYPE);
    db.setDatabaseName(DB_NAME);
    QFileInfo checkFile(DB_NAME);
    if(checkFile.exists() && checkFile.isFile())
    {
        db.open();
        return true;
    }
    else
    {
        return false;
    }
}

void dataLayer::closeDatabase()
{
    if(db.open())
    {
        db.close();
    }
}

void dataLayer::addPerson(Person person)
{
    addNewPerson(person);
}

void dataLayer::addComputer(Computer computer)
{
    addNewComputer(computer);
}

Person dataLayer::getPersonByID(int id)
{
    QSqlQuery query;

    query.prepare("SELECT * FROM Person WHERE ID = :id");
    query.bindValue(":id", id);
    query.exec();
    Person person;

    while(query.next())
    {
        person.setID(query.value("ID").toInt());
        person.setName(query.value("Name").toString().toStdString());
        person.setGender(query.value("Gender").toString().toStdString());
        person.setNationality(query.value("Nationality").toString().toStdString());
        person.setByear(query.value("BirthYear").toInt());
        person.setDyear(query.value("DeathYear").toInt());
    }

    return person;
}

Computer dataLayer::getCompByID(int id)
{
    QSqlQuery query;

    query.prepare("SELECT * FROM Computer WHERE ID = :id");
    query.bindValue(":id", id);
    query.exec();
    Computer computer;

    while(query.next())
    {
        computer.setID(query.value("ID").toInt());
        computer.setName(query.value("Name").toString().toStdString());
        computer.setYear(query.value("Year").toInt());
        computer.setType(query.value("Type").toString().toStdString());
        computer.setBuilt(query.value("Built").toBool());
    }

    return computer;
}

vector<Person> dataLayer::getPers()
{
    vector<Person> persons;
    QSqlQuery query;

    query.prepare("SELECT * FROM Person ORDER BY Name");
    query.exec();

    while(query.next())
    {
        Person person(
                    query.value("ID").toInt(),
                    query.value("Name").toString().toStdString(),
                    query.value("Gender").toString().toStdString(),
                    query.value("Nationality").toString().toStdString(),
                    query.value("BirthYear").toInt(),
                    query.value("DeathYear").toInt());
        persons.push_back(person);
    }
    return persons;
}

vector<Computer> dataLayer::getComps()
{
    vector<Computer> computers;
    QSqlQuery query;

    query.prepare("SELECT * FROM Computer ORDER BY Name");
    query.exec();

    while(query.next())
    {
        Computer computer(
                    query.value("ID").toInt(),
                    query.value("Name").toString().toStdString(),
                    query.value("Year").toInt(),
                    query.value("Type").toString().toStdString(),
                    query.value("Built").toBool());
        computers.push_back(computer);
    }
    return computers;
}

vector<Person> dataLayer::getSortedPersons(string column, int ascDesc)
{
    QString queryString = "SELECT * FROM person ORDER BY person.";
    queryString.append(QString::fromStdString(column));
    queryString.append(" COLLATE NOCASE");

    if(ascDesc == 1)
    {
        queryString.append(" ASC");
    }
    else if(ascDesc == 2)
    {
        queryString.append(" DESC");
    }

    return getPersons(queryString);
}

vector<Computer> dataLayer::getSortedComputers(string column, int ascDesc)
{
    QString queryString = "SELECT * FROM computer ORDER BY computer.";
    queryString.append(QString::fromStdString(column));
    queryString.append(" COLLATE NOCASE");

    if(ascDesc == 1)
    {
        queryString.append(" ASC");
    }
    else if(ascDesc == 2)
    {
        queryString.append(" DESC");
    }

    return getComputers(queryString);
}

vector<vector<int>> dataLayer::getRelation()
{
    vector<vector<int>> resultMatrix;

    QSqlQuery query;
    QString queryString = "SELECT * FROM person_computer";

    query.exec(queryString);

    while(query.next())
    {
        int personID = query.value(0).toInt();
        int computerID = query.value(1).toInt();

        vector<int> vec;
        vec.push_back(personID);
        vec.push_back(computerID);

        resultMatrix.push_back(vec);
    }

    return resultMatrix;
}

vector<string> dataLayer::searchRelation(int id, string table)
{
        vector<string> resultVector;
        QString idCheck;

        if(table == "Person")
        {
            idCheck = "pc.ComputerID";
        }
        else
        {
            idCheck = "pc.PersonID";
        }

        QString qTable = QString::fromStdString(table);
        QString queryString = "SELECT DISTINCT " + qTable + ".Name from " + qTable;
        queryString.append(" JOIN Person_Computer AS pc ON pc." + qTable + "ID = " + qTable + ".ID");
        queryString.append(" WHERE " + idCheck + " = :id");

        QSqlQuery query;
        query.prepare(queryString);
        query.bindValue(":id", id);
        query.exec();

        while(query.next())
        {
            resultVector.push_back(query.value("Name").toString().toStdString());
        }

        return resultVector;
}

void dataLayer::updatePerson(Person person)
{
    QSqlQuery query;

    query.prepare("UPDATE Person SET name = :name, gender = gender, nationality = :nat, "
                  "birthyear = :byear, deathyear = :dyear WHERE ID = :id");
    query.bindValue(":name", QString::fromStdString(person.getName()));
    query.bindValue(":gender", QString::fromStdString(person.getGender()));
    query.bindValue(":nat", QString::fromStdString(person.getNationality()));
    query.bindValue(":byear", person.getByear());
    query.bindValue(":dyear", person.getDyear());
    query.bindValue(":id", person.getID());
    query.exec();
}

void dataLayer::updateComputer(Computer computer)
{
    QSqlQuery query;

    query.prepare("UPDATE Computer SET name = :name, year = :year, type = :type, "
                  "built = :built WHERE id = :id");
    query.bindValue(":name", QString::fromStdString(computer.getName()));
    query.bindValue(":year", computer.getYear());
    query.bindValue(":type", QString::fromStdString(computer.getType()));
    query.bindValue(":built", computer.getBuilt());
    query.bindValue(":id", computer.getID());
    query.exec();
}

void dataLayer::deleteItem(string table, int id)
{
    deleteRow(table, id);
}

void dataLayer::makeRelation(int personID, int computerID)
{
    createRelation(personID, computerID);
}

void dataLayer::unMakeRelation(int personID, int computerID)
{
    deleteRelation(personID, computerID);
}

void dataLayer::createFact(string table, int id, string fact)
{
    if(table == "person")
    {
        createPersonFact(id, fact);
    }
    else
    {
        createComputerFact(id, fact);
    }
}

void dataLayer::deleteFact(string table, int id, string fact)
{
    QString queryString = "DELETE FROM ";
    queryString.append(QString::fromStdString(table));
    queryString.append("_Fact WHERE personID LIKE ");
    queryString.append(QString::number(id));
    queryString.append(" AND Fact LIKE '");
    queryString.append(QString::fromStdString(fact));
    queryString.append("'");

    deleteFact(queryString);
}

vector<string> dataLayer::getFacts(string table, int id)
{
    vector<string> resultMatrix;

    QString queryString = "SELECT Fact FROM ";
    queryString.append(QString::fromStdString(table));
    queryString.append("_Fact WHERE ");
    queryString.append(QString::fromStdString(table));
    queryString.append("ID = ");
    queryString.append(QString::number(id));

    QSqlQuery query;
    query.exec(queryString);

    while(query.next())
    {
        resultMatrix.push_back(query.value(0).toString().toStdString());
    }

    return resultMatrix;
}

vector<Computer> dataLayer::searchComputers(string findMe)
{
    QString queryString = "SELECT * FROM Computer WHERE Name LIKE '%";
    queryString.append(QString::fromStdString(findMe));
    queryString.append("%' COLLATE NOCASE OR Year LIKE '%");
    queryString.append(QString::fromStdString(findMe));
    queryString.append("%' OR Type LIKE '%");
    queryString.append(QString::fromStdString(findMe));
    queryString.append("%' COLLATE NOCASE");

    return getComputers(queryString);
}

vector<Person> dataLayer::searchPersons(string findMe)
{
    QString queryString = "SELECT * FROM Person WHERE Name LIKE '%";
    queryString.append(QString::fromStdString(findMe));
    queryString.append("%' COLLATE NOCASE OR Gender LIKE '%");
    queryString.append(QString::fromStdString(findMe));
    queryString.append("%' COLLATE NOCASE OR Nationality LIKE '%");
    queryString.append(QString::fromStdString(findMe));
    queryString.append("%' COLLATE NOCASE OR BirthYear LIKE '%");
    queryString.append(QString::fromStdString(findMe));
    queryString.append("%' OR DeathYear LIKE '%");
    queryString.append(QString::fromStdString(findMe));
    queryString.append("%'");

    return getPersons(queryString);
}

void dataLayer::updateImage(string table, int id, string path)
{
    QString queryString = "UPDATE ";
    queryString.append(QString::fromStdString(table));
    queryString.append("_Image SET Image = '");
    queryString.append(QString::fromStdString(path));
    queryString.append("' WHERE ");
    queryString.append(QString::fromStdString(table));
    queryString.append("ID = ");
    queryString.append(QString::number(id));

    QSqlQuery query;
    query.exec(queryString);
}

void dataLayer::deleteImage(string table, int id)
{
    updateImage(table, id, "");
}

void dataLayer::addNewImage(string table, int id)
{
    QString queryString = "INSERT INTO";
    queryString.append(QString::fromStdString(table));
    queryString.append("_Image (");
    queryString.append(QString::fromStdString(table));
    queryString.append("ID, Image) VALUES (");
    queryString.append(QString::number(id));
    queryString.append(", '')");

    QSqlQuery query;
    query.exec(queryString);
}
