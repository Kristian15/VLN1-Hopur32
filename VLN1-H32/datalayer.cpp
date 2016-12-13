#include "datalayer.h"
#include <iostream>

// **** Private ****

/**
 * @brief dataLayer::addNewPerson
 * @param addMe
 */
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

/**
 * @brief dataLayer::addNewComputer
 * @param addMe
 */
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

void dataLayer::createPersonFact(int personID, string fact)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Person_Computer (PersonID, Fact) "
                  "VALUES (:personID, :fact)");
    query.bindValue(":personID", personID);
    query.bindValue(":fact", QString::fromStdString(fact));
    query.exec();
}

/**
 * @brief dataLayer::getPersons
 * @param queryString
 * @return vector<Person>
 */
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

/**
 * @brief dataLayer::getComputers
 * @param queryString
 * @return vector<Computer>
 */
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

/**
 * @brief dataLayer::deleteRow
 * @param table
 * @param id
 */
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

/**
 * @brief dataLayer::deleteRelation
 * @param personID
 * @param computerID
 */
void dataLayer::deleteRelation(int personID, int computerID)
{
    QString qPersID = QString::number(personID);
    QString qCompID = QString::number(computerID);
    QSqlQuery query;
    query.prepare("DELETE FROM Person_Computer WHERE PersonID = " +
                  qPersID + " AND computerID = " + qCompID);
    query.exec();
}

void dataLayer::deletePersonFact(int factID)
{
    QString qFactID = QString::number(factID);
    QSqlQuery query;
    query.prepare("DELETE FROM Person_Fact WHERE FactID = " +
                  qFactID);
    query.exec();
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
    QString qTable = QString::fromStdString(table);
    QString qColumn = QString::fromStdString(column);
    QString queryString = "UPDATE " + qTable + " SET " + qColumn + " = (:updateME) WHERE ID = (:id)";
    QString qUpdateME = QString::fromStdString(updateME);

    if(column == "Built" && updateME == "y")
    {
        qUpdateME = "1";
    }
    else if(column == "Built" && updateME == "n")
    {
        qUpdateME = "0";
    }

    QSqlQuery query;
    query.prepare(queryString);
    query.bindValue(":updateME", qUpdateME);
    query.bindValue(":id", id);
    query.exec();
}

// **** Public ****

/**
 * @brief dataLayer::dataLayer
 */
dataLayer::dataLayer()
{
}

/**
 * @brief dataLayer::~dataLayer
 */
dataLayer::~dataLayer()
{
    db.close();
}

/**
 * @brief dataLayer::openDatabase
 * @return bool
 */
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

/**
 * @brief dataLayer::addPerson
 * @param person
 */
void dataLayer::addPerson(Person person)
{
    addNewPerson(person);
}

/**
 * @brief dataLayer::addComputer
 * @param computer
 */
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
       /* person(
                query.value("ID").toInt(),
                query.value("Name").toString().toStdString(),
                query.value("Gender").toString().toStdString(),
                query.value("Nationality").toString().toStdString(),
                query.value("BirthYear").toInt(),
                query.value("DeathYear").toInt());*/
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
        /*Computer computer(
                    query.value("ID").toInt(),
                    query.value("Name").toString().toStdString(),
                    query.value("Year").toInt(),
                    query.value("Type").toString().toStdString(),
                    query.value("Built").toBool());*/
        computer.setID(query.value("ID").toInt());
        computer.setName(query.value("Name").toString().toStdString());
        computer.setYear(query.value("Year").toInt());
        computer.setType(query.value("Type").toString().toStdString());
        computer.setBuilt(query.value("Built").toBool());
    }

    return computer;
}

/**
 * @brief dataLayer::getSortedPersons
 * @param column
 * @param ascDesc
 * @return vector<Person>
 */
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

/**
 * @brief dataLayer::getSortedComputers
 * @param column
 * @param ascDesc
 * @return vector<Computer>
 */
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

/**
 * @brief dataLayer::findPersons
 * @param column
 * @param findMe
 * @return vector<Person>
 */
vector<Person> dataLayer::findPersons(string column, string findMe)
{
    QString queryString = "SELECT * FROM Person WHERE ";
    queryString.append(QString::fromStdString(column));
    queryString.append(" LIKE '");

    if(column != "Gender") // so female do not come up when searching for male
    {
        queryString.append("%");
    }

    queryString.append(QString::fromStdString(findMe));
    queryString.append("%' COLLATE NOCASE");

    return getPersons(queryString);
}

/**
 * @brief dataLayer::findComputers
 * @param column
 * @param findMe
 * @return vector<Person>
 */
vector<Computer> dataLayer::findComputers(string column, string findMe)
{
    vector<Computer> computers;

    QString queryString = "SELECT * FROM Computer WHERE ";
    queryString.append(QString::fromStdString(column));
    queryString.append(" LIKE '%");
    queryString.append(QString::fromStdString(findMe));
    queryString.append("%' COLLATE NOCASE");

    return getComputers(queryString);
}

/**
 * @brief dataLayer::searchPersonYears
 * @param column
 * @param from
 * @param to
 * @return vector<Person>
 */
vector<Person> dataLayer::searchPersonYears(string column, int from, int to)
{
    vector<Person> persons;

    QString qColumn = QString::fromStdString(column);
    QSqlQuery query;
    query.prepare("SELECT * FROM Person WHERE " + qColumn + " BETWEEN :from AND :to");
    query.bindValue(":from", from);
    query.bindValue(":to", to);
    query.exec();

    while(query.next())
    {
        Person person(
                    query.value("ID").toUInt(),
                    query.value("Name").toString().toStdString(),
                    query.value("Gender").toString().toStdString(),
                    query.value("Nationality").toString().toStdString(),
                    query.value("BirthYear").toInt(),
                    query.value("DeathYear").toInt());
        persons.push_back(person);
    }
    return persons;
}

/**
 * @brief dataLayer::searchComputerYears
 * @param from
 * @param to
 * @return vector<Computer>
 */
vector<Computer> dataLayer::searchComputerYears(int from, int to)
{
    vector<Computer> computers;

    QSqlQuery query;
    query.prepare("SELECT * FROM Computer WHERE BirthYear BETWEEN :from AND :to");
    query.bindValue(":from", from);
    query.bindValue(":to", to);
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

/**
 * @brief dataLayer::getRelation
 * @param column
 * @return vector<vector<string>>
 */
vector<vector<string>> dataLayer::getRelation(string column)
{
    vector<vector<string>> resultMatrix;

    QString queryString = "SELECT DISTINCT name FROM ";
    queryString.append(QString::fromStdString(column));
    queryString.append(" AS p JOIN Person_Computer AS pc ON p.id = pc.");
    queryString.append(QString::fromStdString(column));
    queryString.append("id");

    QSqlQuery query;
    query.exec(queryString); // Get all Distinct names from Person_Computer table

    while(query.next())
    {
        vector<string> item;
        item.push_back(query.value("Name").toString().toStdString());
        resultMatrix.push_back(item);
    }

    queryString = "SELECT p.name, c.name FROM person_computer AS pc JOIN person as p"
            " ON p.ID = pc.personID JOIN computer AS c ON c.ID = pc.computerID";

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
            if(a == resultMatrix[i][0])
            {
                pos = i;
            }
        }

        resultMatrix[pos].push_back(b);
    }

    return resultMatrix;
}

/**
 * @brief dataLayer::searchRelation
 * @param id
 * @param table
 * @return vector<string>
 */
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

/**
 * @brief dataLayer::updateTable
 * @param id
 * @param table
 * @param column
 * @param updateME
 */
void dataLayer::updateTable(int id, string table, string column, string updateME)
{
    updateItem(id, table, column, updateME);
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

/**
 * @brief dataLayer::deleteItem
 * @param table
 * @param id
 */
void dataLayer::deleteItem(string table, int id)
{
    deleteRow(table, id);
}

/**
 * @brief dataLayer::makeRelation
 * @param personID
 * @param computerID
 */
void dataLayer::makeRelation(int personID, int computerID)
{
    createRelation(personID, computerID);
}

/**
 * @brief dataLayer::unMakeRelation
 * @param personID
 * @param computerID
 */
void dataLayer::unMakeRelation(int personID, int computerID)
{
    deleteRelation(personID, computerID);
}
