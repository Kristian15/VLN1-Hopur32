#include "datalayer.h"
#include <iostream>

// **** Constructor ****

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
 * @brief dataLayer::updateData
 * @param person
 */
void dataLayer::addNewPerson(Person person)
{
    if(db.isOpen())
    {
       QSqlQuery query;
       query.prepare("INSERT INTO persons (Name, Gender, Nationality, BirthYear, DeathYear) "
                     "VALUES (:name, :gender, :nationality, :byear, :dyear)");
       query.bindValue(":name", QString::fromStdString(person.getName()));
       query.bindValue(":gender", QString::fromStdString(person.getGender()));
       query.bindValue(":nationality", QString::fromStdString(person.getNationality()));
       query.bindValue(":byear", person.getByear());
       query.bindValue(":dyear", person.getDyear());
       query.exec();
    }

    string data = "";
    bool match = false;

    if(_persons.empty())
    {
        _fileName = "backup.txt";
        match = true;
    }

    _persons.push_back(person);
    data = person.getName() + _d + person.getGender() + _d + person.getNationality() + _d + to_string(person.getByear()) + _d;

    if(person.getDyear() != 0)
    {
        data += to_string(person.getDyear()) + _d;
    }

    ofstream dataStream;
    dataStream.open(_fileName, ios::app);

    if(dataStream)
    {
        if(match == false)
        {
            dataStream << endl;
        }
        dataStream << data;
        dataStream.close();
    }
}

void dataLayer::addNewComputer(Computer computer)
{
    if(db.isOpen())
    {
       QSqlQuery query;
       query.prepare("INSERT INTO computers (Name, Year, Type, Built) "
                     "VALUES (:name, :year, :type, :built)");
       query.bindValue(":name", QString::fromStdString(computer.getName()));
       query.bindValue(":year", computer.getYear());
       query.bindValue(":type", QString::fromStdString(computer.getType()));
       query.bindValue(":built",computer.getBuilt());
       query.exec();
    }
}

// **** Public ****

vector<Person> dataLayer::getSortedPersons(string order)
{
    vector<Person> persons;
    QString queryString = "SELECT * FROM persons ORDER BY persons.";
    queryString.append(QString::fromStdString(order));
    queryString.append(" COLLATE NOCASE");

    if(db.isOpen())
    {
        QSqlQuery query;
        query.exec(queryString);

        while (query.next())
        {
            Person person;
            //person.setId(query.value("ID").toInt());
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

vector<Computer> dataLayer::getSortedComputers(string order)
{
    vector<Computer> computers;
    QString queryString = "SELECT * FROM computers ORDER BY computers.";
    queryString.append(QString::fromStdString(order));
    queryString.append(" COLLATE NOCASE");

    if(db.isOpen())
    {
        QSqlQuery query;
        query.exec(queryString);

        while (query.next())
        {
            Computer computer;
            computer.setId(query.value("Id").toInt());
            computer.setName(query.value("Name").toString().toStdString());
            computer.setYear(query.value("Year").toInt());
            computer.setType(query.value("Type").toString().toStdString());
            computer.setBuilt(query.value("Built").toInt());


            computers.push_back(computer);
        }
    }

    return computers;
}

vector<Person> dataLayer::findPersons(string column, string findMe)
{
    vector<Person> persons;

    if(db.isOpen())
    {
        QSqlQuery query;
        query.prepare("SELECT * FROM persons WHERE :column LIKE %:findMe% COLLATE NOCASE");
        query.bindValue(":column", QString::fromStdString(column));
        query.bindValue(":findMe", QString::fromStdString(findMe));
        query.exec();

        while(query.next())
        {
            Person person;
            //person.setId(query.value("ID").toUInt());
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

vector<Computer> dataLayer::findComputers(string column, string findMe)
{
    vector<Computer> computers;

    if(db.isOpen())
    {
        QSqlQuery query;
        query.prepare("SELECT * FROM computers WHERE :column LIKE %:findMe% COLLATE NOCASE");
        query.bindValue(":column", QString::fromStdString(column));
        query.bindValue(":findMe", QString::fromStdString(findMe));
        query.exec();

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

bool dataLayer::deletePerson(string deleteMe)
{
    if(db.isOpen())
    {
        QSqlQuery query;
        query.prepare("DELETE FROM persons WHERE name = :deleteMe");
        query.bindValue(":deleteMe", QString::fromStdString(deleteMe));
        query.exec();
        return true; // TODO: make check for this
    }

    return false;
}

bool dataLayer::deleteComputer(string deleteMe)
{
    if(db.isOpen())
    {
        QSqlQuery query;
        query.prepare("DELETE FROM Computers WHERE Name = :deleteMe");
        query.bindValue(":deleteMe", QString::fromStdString(deleteMe));
        query.exec();
        return true; // TODO: make check for this
    }

    return false;
}

bool dataLayer::makeRelation(int personId, int computerId)
{

    if(db.isOpen())
    {
        QSqlQuery query;
        query.prepare("INSERT INTO PersonAndComputer (PersonID, ComputerID) "
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
vector<string> dataLayer::loadData(string fileName)
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
}

