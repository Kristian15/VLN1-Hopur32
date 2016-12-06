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
    if(db.isOpen())
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
}
/**
 * @brief dataLayer::addNewComputer
 * @param computer
 */
void dataLayer::addNewComputer(Computer addMe)
{
    if(db.isOpen())
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
}

// **** Public ****
/**
 * @brief dataLayer::getSortedPersons
 * @param order
 * @return
 */
vector<Person> dataLayer::getSortedPersons(string column)
{
    vector<Person> persons;
    QString queryString = "SELECT * FROM persons ORDER BY persons.";
    queryString.append(QString::fromStdString(column));
    queryString.append(" COLLATE NOCASE");

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
vector<Computer> dataLayer::getSortedComputers(string column)
{
    vector<Computer> computers;
    QString queryString = "SELECT * FROM computers ORDER BY computers.";
    queryString.append(QString::fromStdString(column));
    queryString.append(" COLLATE NOCASE");

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
            computer.setId(query.value("Id").toInt());
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
        QSqlQuery query;
        query.prepare("UPDATE :table SET :column = :updateMe WHERE ID = :id");
        query.bindValue(":table", QString::fromStdString(table));
        query.bindValue(":column", QString::fromStdString(column));
        query.bindValue(":updateMe", QString::fromStdString(updateMe));
        query.bindValue(":id", id);
        query.exec();
    }
    return;
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
bool dataLayer::makeRelation(int personId, int computerId)
{

    if(db.isOpen())
    {
        QSqlQuery query;
        query.prepare("INSERT INTO Person_Computer (PersonID, ComputerID) "
                      "VALUES (:personId, :computerId)");
        query.bindValue(":personId", personId);
        query.bindValue(":computerId", computerId);
        query.exec();
        return true; // make check for it
    }

    return false;
}
/**
 * @brief dataLayer::loadData
 * @param fileName
 * @return vector<string>
 */
/*vector<string> dataLayer::loadData(string fileName)
{
   string line;

    _fileName = fileName;
    vector<string> data;
    ifstream iDataStream;
    iDataStream.open(fileName);

    if(iDataStream)
    {
        while(getline(iDataStream,line))
        {
            if(!line.empty())
            {
                data.push_back(line);
            }
        }

        iDataStream.close();
    }
    else
    {
        // Throwing error that user interface catches
        throw string("No data file found!");
    }

    return data;
}*/
