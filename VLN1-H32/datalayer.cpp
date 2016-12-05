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
void dataLayer::updateData(Person person)
{
    if(db.isOpen())
    {
       query.prepare("INSERT INTO Persons (Name, Gender, Nationality, BirthYear, DeathYear) "
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


// **** Public ****

vector<Person> dataLayer::getSortedPersons(string order)
{
    vector<Person> persons;

    if(db.isOpen())
    {
        query.prepare("SELECT * FROM persons ORDER BY order"
                      "VALUES (:order)");
        query.bindValue(":order", QString::fromStdString(order));
        query.exec();

        while (query.next())
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

vector<Person> dataLayer::findPersons(string column, string findMe)
{
    vector<Person> persons;

    if(db.isOpen())
    {
        query.prepare("SELECT * FROM persons WHERE CONTAINS(Column, findMe) "
                      "VALUES (:Column, :findMe)");
        query.bindValue(":Column", QString::fromStdString(column));
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

bool dataLayer::deletePerson(string deleteMe)
{
    QString localQuery = "DELETE FROM persons WHERE name=";
    localQuery.append(QString::fromStdString(deleteMe));
    localQuery.append("COLLATE NOCASE");
    if(db.isOpen())
    {
        query.prepare(localQuery);
        query.exec();
        return true; // þarf að skila true ef eyðsla heppnaðist
    }

    return false;
}

bool dataLayer::deleteComputer(string deleteMe)
{
    QString localQuery = "DELETE FROM computers WHERE name=";
    localQuery.append(QString::fromStdString(deleteMe));
    localQuery.append("COLLATE NOCASE");
    if(db.isOpen())
    {
        query.prepare(localQuery);
        query.exec();
        return true; // þarf að skila true ef eyðsla heppnaðist
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

/**
 * @brief dataLayer::saveData
 * @param fileName
 * @param persons
 */
void dataLayer::saveData(string fileName, vector<Person> persons)
{
    string name = "", gender = "", nationality = "", bYear = "", dYear = "";
    vector<string> data;

    if (fileName != "current")
    {
        _fileName = fileName;
    }

    for (unsigned int i = 0; i < persons.size(); i++)
    {
        name = persons[i].getName() + _d;
        gender = persons[i].getGender() + _d;
        nationality = persons[i].getNationality() + _d;
        bYear = to_string(persons[i].getByear()) + _d;

        if(persons[i].getDyear() != 0)
        {
            dYear = to_string(persons[i].getDyear()) + _d;
        }

        data.push_back(name + gender + nationality + bYear + dYear);

        name = "";
        gender = "";
        nationality = "";
        bYear = "";
        dYear = "";
    }

    ofstream dataStream;
    dataStream.open(_fileName, ios::trunc);

    if(dataStream)
    {
        for(unsigned int i = 0; i < data.size(); i++)
        {
            dataStream << data[i] << endl;
        }

        dataStream.close();
    }
}
