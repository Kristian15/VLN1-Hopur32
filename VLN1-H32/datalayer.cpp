#include "datalayer.h"
#include <iostream>

// **** Constructor/Destructor ****

dataLayer::dataLayer()
{
    db = QSqlDatabase::addDatabase(DB_DRIVER_TYPE);
    db.setDatabaseName(DB_NAME);
    db.open();
}

dataLayer::~dataLayer()
{
    db.close();
}

// **** Private ****

/**
 * @brief dataLayer::addNewPerson
 * @param person
 */
void dataLayer::addNewPerson(Person addMe)
{
    QSqlQuery query;
    query.prepare("INSERT INTO persons (Name, Gender, Nationality, BirthYear, DeathYear) "
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
/**
 * @brief dataLayer::addNewComputer
 * @param computer
 */
void dataLayer::addNewComputer(Computer addMe)
{
    QSqlQuery query;
    query.prepare("INSERT INTO computers (Name, Year, Type, Built) "
                 "VALUES (:name, :year, :type, :built)");
    query.bindValue(":name", QString::fromStdString(addMe.getName()));
    query.bindValue(":year", addMe.getYear());
    query.bindValue(":type", QString::fromStdString(addMe.getType()));
    query.bindValue(":built",addMe.getBuilt());
    query.exec();
}
/**
 * @brief dataLayer::deleteRow
 * @param table
 * @param id
 */
void dataLayer::deleteRow(string table, int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM :table WHERE ID = :id");
    query.bindValue(":table", QString::fromStdString(table));
    query.bindValue(":id", id);
    query.exec();

    if(table == "Persons")
    {
        query.prepare("DELETE FROM Person_Computer WHERE PersonID = :id");
        query.bindValue(":id", id);
        query.exec();
    }
    else if(table == "Computers")
    {
        query.prepare("DELETE FROM Person_Computer WHERE ComputerID = :id");
        query.bindValue(":id", id);
        query.exec();
    }
    return;
}
/**
 * @brief dataLayer::updateItem
 * @param id
 * @param table
 * @param column
 * @param updateME
 */
void dataLayer::updateItem(int id, string table, string column, string updateME)
{
    QSqlQuery query;
    query.prepare("UPDATE :table SET :column = :updateMe WHERE ID = :id");
    query.bindValue(":table", QString::fromStdString(table));
    query.bindValue(":column", QString::fromStdString(column));
    query.bindValue(":updateMe", QString::fromStdString(updateME));
    query.bindValue(":id", id);
    query.exec();
}
/**
 * @brief dataLayer::createRelation
 * @param personID
 * @param computerID
 */
void dataLayer::createRelation(int personID, int computerID)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Person_Computer (PersonID, ComputerID) "
                  "VALUES (:personID, :computerID)");
    query.bindValue(":personID", personID);
    query.bindValue(":computerID", computerID);
    query.exec();
}
/**
 * @brief dataLayer::deleteRelation
 * @param personID
 * @param computerID
 */
void dataLayer::deleteRelation(int personID, int computerID)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Person_Computer (PersonID, ComuterID) "
                  "Values (:personID, :computerID");
    query.bindValue(":personID", personID);
    query.bindValue(":computerID", computerID);
    query.exec();
}

// **** Public ****
void dataLayer::addPerson(Person person)
{
    if(db.isOpen())
    {
        addNewPerson(person);
    }
    else
    {
        throw string("Error: No database connection!");
    }
}
void dataLayer::addComputer(Computer computer)
{
    if(db.isOpen())
    {
        addNewComputer(computer);
    }
    else
    {
        throw string("Error: No database connection!");
    }
}
/**
 * @brief dataLayer::getSortedPersons
 * @param order
 * @return
 */
vector<Person> dataLayer::getSortedPersons(string column, int ascDesc)
{
    vector<Person> persons;
    QString queryString = "SELECT * FROM persons ORDER BY persons.";
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

    if(db.isOpen())
    {
        QSqlQuery query;
        query.exec(queryString);

        while (query.next())
        {
            Person person(
                        query.value("Name").toString().toStdString(),
                        query.value("Gender").toString().toStdString(),
                        query.value("Nationality").toString().toStdString(),
                        query.value("BirthYear").toInt(),
                        query.value("DeathYear").toInt());
            persons.push_back(person);
        }
    }

    return persons;
}
/**
 * @brief dataLayer::getSortedComputers
 * @param order
 * @return
 */
vector<Computer> dataLayer::getSortedComputers(string column, int ascDesc)
{
    vector<Computer> computers;
    QString queryString = "SELECT * FROM computers ORDER BY computers.";
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

    if(db.isOpen())
    {
        QSqlQuery query;
        query.exec(queryString);

        while (query.next())
        {
            Computer computer(
                    query.value("Name").toString().toStdString(),
                    query.value("Year").toInt(),
                    query.value("Type").toString().toStdString(),
                    query.value("Built").toBool());
            computers.push_back(computer);
        }
    }

    return computers;
}
/**
 * @brief dataLayer::findPersons
 * @param column
 * @param findMe
 * @return
 */
vector<Person> dataLayer::findPersons(string column, string findMe)
{
    vector<Person> persons;

    QString queryString = "SELECT * FROM Persons WHERE ";
    queryString.append(QString::fromStdString(column));
    queryString.append(" LIKE '%");
    queryString.append(QString::fromStdString(findMe));
    queryString.append("%' COLLATE NOCASE");

    if(db.isOpen())
    {
        QSqlQuery query;
        query.exec(queryString);

        while(query.next())
        {
            Person person;
            person.setID(query.value("ID").toUInt());
            person.setName(query.value("Name").toString().toStdString());
            person.setGender(query.value("Gender").toString().toStdString());
            person.setNationality(query.value("Nationality").toString().toStdString());
            person.setByear(query.value("BirthYear").toInt());
            person.setDyear(query.value("DeathYear").toInt());
            persons.push_back(person);
        }
    }

    return persons;
}
/**
 * @brief dataLayer::findComputers
 * @param column
 * @param findMe
 * @return
 */
vector<Computer> dataLayer::findComputers(string column, string findMe)
{
    vector<Computer> computers;

    QString queryString = "SELECT * FROM Computers WHERE ";
    queryString.append(QString::fromStdString(column));
    queryString.append(" LIKE '%");
    queryString.append(QString::fromStdString(findMe));
    queryString.append("%' COLLATE NOCASE");

    if(db.isOpen())
    {
        QSqlQuery query;
        query.exec(queryString);

        while(query.next())
        {
            Computer computer;
            computer.setID(query.value("Id").toInt());
            computer.setName(query.value("Name").toString().toStdString());
            computer.setYear(query.value("Year").toInt());
            computer.setType(query.value("Type").toString().toStdString());
            computer.setBuilt(query.value("Built").toBool());

            computers.push_back(computer);
        }
    }

    return computers;
}
/**
 * @brief dataLayer::updateTable
 * @param id
 * @param table
 * @param column
 * @param updateMe
 */
void dataLayer::updateTable(int id, string table, string column, string updateMe)
{
    if(db.isOpen())
    {
        updateItem(id, table, column, updateMe);
    }
    else
    {
        throw string("Error: No database connection!");
    }
    return;
}
/**
 * @brief dataLayer::deleteItem
 * @param table
 * @param id
 * @return
 */
bool dataLayer::deleteItem(string table, int id)
{
    if(db.isOpen())
    {
        deleteRow(table, id);
        return true;
    }
    else
    {
        throw string("Error: No database connection!");
    }
    return false;
}
/**
 * @brief dataLayer::deletePerson
 * @param deleteMe
 * @return
 */
bool dataLayer::deletePerson(int id)
{
    if(db.isOpen())
    {
        QSqlQuery query;
        query.prepare("DELETE FROM persons WHERE ID = :id");
        query.bindValue(":id", id);
        query.exec();
        return true;
    }

    return false;
}
/**
 * @brief dataLayer::deleteComputer
 * @param deleteMe
 * @return
 */
bool dataLayer::deleteComputer(int id)
{
    if(db.isOpen())
    {
        QSqlQuery query;
        query.prepare("DELETE FROM Computers WHERE ID = :id");
        query.bindValue(":id", id);
        query.exec();
        return true;
    }

    return false;
}
/**
 * @brief dataLayer::makeRelation
 * @param personId
 * @param computerId
 * @return
 */
bool dataLayer::makeRelation(int personID, int computerID)
{

    if(db.isOpen())
    {
        createRelation(personID, computerID);
        return true; // make check for it
    }
    else
    {
        throw string("Error: No database connection!");
    }
}
/**
 * @brief dataLayer::unMakeRelation
 * @param personID
 * @param computerID
 * @return
 */
bool dataLayer::unMakeRelation(int personID, int computerID)
{
    if(db.isOpen())
    {
        deleteRelation(personID, computerID);
    }
    else
    {
        throw string("Error: No database connection!");
    }
    return true;
}
