#include "datalayer.h"
#include <iostream>

// **** Constructor/Destructor ****

dataLayer::dataLayer()
{
    db = QSqlDatabase::addDatabase(DB_DRIVER_TYPE);
    db.setDatabaseName(DB_NAME);
    db.open();
    if(!db.isOpen())
    {
        throw string("Error!\nDatabase file not found!\nPlease check if database file is present!");
    }
}

dataLayer::~dataLayer()
{
    db.close();
}

// **** Private ****

void dataLayer::addNewPerson(Person addMe)
{
    // sama og í addNewComputer
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
    // er eðlilegra að senda upplýsingarnar áfram í dataLayer án þess að búa til nýja manneskju í service?
    // addNewComputer(name, year, type, built)

    QSqlQuery query;
    query.prepare("INSERT INTO computer (Name, Year, Type, Built) "
                 "VALUES (:name, :year, :type, :built)");
    query.bindValue(":name", QString::fromStdString(addMe.getName()));
    query.bindValue(":year", addMe.getYear());
    query.bindValue(":type", QString::fromStdString(addMe.getType()));
    query.bindValue(":built",addMe.getBuilt());
    query.exec();
}

void dataLayer::deleteRow(string table, int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM :table WHERE ID = :id");
    query.bindValue(":table", QString::fromStdString(table));
    query.bindValue(":id", id);
    query.exec();

    //  Getum sett column inn i strenginn í staðin fyrir að gera if lykkju

    QString queryString = "DELETE FROM Person_Computer WHERE ";
    queryString.append(QString::fromStdString(table));
    queryString.append("ID = ");
    queryString.append(id);
    query.exec();

   /* if(table == "Persons")
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
    }*/
}

void dataLayer::updateItem(int id, string table, string column, string updateME)
{
    // VIRKAR EKKI
    cout << id << " " << table << " " << column << " " << updateME << endl;
    QSqlQuery query;
    query.prepare("UPDATE :table SET :column = :updateMe WHERE ID = :id");
    query.bindValue(":table", QString::fromStdString(table));
    query.bindValue(":column", QString::fromStdString(column));
    query.bindValue(":updateMe", QString::fromStdString(updateME));
    query.bindValue(":id", id);
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

vector<Person> dataLayer::getSortedPersons(string column, int ascDesc)
{
    // setja í private ??

    vector<Person> persons;
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

vector<Computer> dataLayer::getSortedComputers(string column, int ascDesc)
{
    // setja í private ??

    vector<Computer> computers;
    QString queryString = "SELECT * FROM computer ORDER BY computers.";
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

vector<Person> dataLayer::findPersons(string column, string findMe)
{
    // setja í private ??

    vector<Person> persons;

    QString queryString = "SELECT * FROM Person WHERE ";
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

vector<Computer> dataLayer::findComputers(string column, string findMe)
{
    // setja í private ??
    vector<Computer> computers;

    QString queryString = "SELECT * FROM Computer WHERE ";
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

vector<vector<string>> dataLayer::getRelation(string column)
{
    // setja í private ??

    vector<vector<string>> resultMatrix;

    QString queryString = "SELECT DISTINCT name FROM ";
    queryString.append(QString::fromStdString(column));
    queryString.append(" AS p JOIN Person_Computer AS pc ON p.id = pc.");
    queryString.append(QString::fromStdString(column));
    queryString.append("id");

    if(db.isOpen())
    {
        QSqlQuery query;
        query.exec(queryString);

        while(query.next())
        {
            vector<string> item;
            item.push_back(query.value("Name").toString().toStdString());
            resultMatrix.push_back(item);
        }
    }

    queryString = "SELECT p.name, c.name FROM person_computer AS pc JOIN person as p"
            " ON p.ID = pc.personID JOIN computer AS c ON c.ID = pc.computerID";

    if(db.isOpen())
    {
        QSqlQuery query;
        query.exec(queryString);

        while(query.next())
        {
            string a = query.value(0).toString().toStdString();
            string b = query.value(1).toString().toStdString();

            if(column == "Computer")
            {
                string tmp = a;
                a = b;
                b = tmp;
            }

            unsigned int pos;

            for(unsigned int i = 0; i < resultMatrix.size(); i++)
            {
                cout << endl;
                if(a == resultMatrix[i][0])
                {
                    pos = i;
                }
            }

            resultMatrix[pos].push_back(b);
        }
    }

    return resultMatrix;
}

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

/*bool dataLayer::deletePerson(int id, string column)
{
    if(db.isOpen())
    {
        QSqlQuery query;
        query.prepare("DELETE FROM column WHERE ID = :id");
        query.bindValue(":id", id);
        query.exec();
        return true;
    }

    return false;
}*/

/*bool dataLayer::deleteComputer(int id)
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
}*/

bool dataLayer::makeRelation(int personID, int computerID)
{

    if(db.isOpen())
    {
        createRelation(personID, computerID);
        return true;
    }
    else
    {
        throw string("Error: No database connection!");
    }
}

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
