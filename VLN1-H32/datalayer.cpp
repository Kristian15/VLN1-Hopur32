#include "datalayer.h"

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
 * @brief dataLayer::addNewLink
 * @param personID
 * @param computerID
 */
void dataLayer::addNewLink(int personID, int computerID)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Person_Computer (PersonID, ComputerID) "
                  "VALUES (:personID, :computerID)");
    query.bindValue(":personID", personID);
    query.bindValue(":computerID", computerID);
    query.exec();
}

/**
 * @brief dataLayer::addNewFact
 * @param table
 * @param id
 * @param fact
 */
void dataLayer::addNewFact(string table, int id, string fact)
{
    QString qTable = QString::fromStdString(table);
    qTable.append("_Fact");
    QSqlQuery query;
    query.prepare("INSERT INTO " + qTable + " (ID, Fact) VALUES ( :id, :fact )");
    query.bindValue(":id", id);
    query.bindValue(":fact", QString::fromStdString(fact));
    query.exec();
}

/**
 * @brief dataLayer::addNewImage
 * @param table
 * @param id
 */
void dataLayer::addNewImage(string table, int id)
{
    QString qTable = QString::fromStdString(table);
    qTable.append("_Image");
    QSqlQuery query;
    query.prepare("INSERT INTO " + qTable + " (ID, Image) VALUES ( :id, "" )");
    query.bindValue(":id", QString::number(id));
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
 * @brief dataLayer::getLinks
 * @param queryString
 * @return vector<vector<int>>
 */
vector<vector<int>> dataLayer::getLinks(QString queryString)
{
    vector<vector<int>> resultMatrix;

    QSqlQuery query;
    query.exec(queryString);

    while(query.next())
    {
        int personID = query.value("PersonID").toInt();
        int computerID = query.value("ComputerID").toInt();

        vector<int> vec;
        vec.push_back(personID);
        vec.push_back(computerID);

        resultMatrix.push_back(vec);
    }

    return resultMatrix;
}

/**
 * @brief dataLayer::deleteItem
 * @param table
 * @param id
 */
void dataLayer::deleteItem(string table, int id)
{
    QString qTable = QString::fromStdString(table);

    QSqlQuery query;
    query.prepare("DELETE FROM " + qTable + " WHERE ID = :id ");
    query.bindValue(":id", id);
    query.exec();

    deleteItemLinks(qTable, id);
    deleteItemFacts(qTable, id);
    deleteItemImage(qTable, id);
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

/**
 * @brief dataLayer::deleteFactPriv
 * @param table
 * @param id
 * @param fact
 */
void dataLayer::deleteFactPriv(string table, int id, string fact)
{
    QString qTable = QString::fromStdString(table);
    qTable.append("_Fact");
    QSqlQuery query;
    query.prepare("DELETE FROM " + qTable + " WHERE ID LIKE :id AND Fact LIKE :fact");
    query.bindValue(":id", id);
    query.bindValue(":fact", QString::fromStdString(fact));
    query.exec();
}

/**
 * @brief dataLayer::deleteItemLinks
 * @param qTable
 * @param id
 */
void dataLayer:: deleteItemLinks(QString qTable, int id)
{
    qTable.append("ID");
    QSqlQuery query;
    query.prepare("DELETE FROM Person_Computer WHERE " + qTable + " = :id");
    query.bindValue(":id", id);
    query.exec();
}

/**
 * @brief dataLayer::deleteItemFacts
 * @param qTable
 * @param id
 */
void dataLayer:: deleteItemFacts(QString qTable, int id)
{
    qTable.append("_Fact");
    QSqlQuery query;
    query.prepare("DELETE FROM " + qTable + " WHERE ID = :id");
    query.bindValue(":id", id);
    query.exec();
}

/**
 * @brief dataLayer::deleteItemImage
 * @param qTable
 * @param id
 */
void dataLayer:: deleteItemImage(QString qTable, int id)
{
    qTable.append("_Image");
    QSqlQuery query;
    query.prepare("DELETE FROM " + qTable + " WHERE ID = :id");
    query.bindValue(":id", QString::number(id));
    query.exec();
}

// **** Public ****

/**
 * @brief dataLayer::openDatabase
 */
void dataLayer::openDatabase()
{
    db = QSqlDatabase::addDatabase(DB_DRIVER_TYPE);
    db.setDatabaseName(DB_NAME);
    QFileInfo checkFile(DB_NAME);

    if(checkFile.exists() && checkFile.isFile())
    {
        db.open();
    }
}

/**
 * @brief dataLayer::closeDatabase
 */
void dataLayer::closeDatabase()
{
    if(db.open())
    {
        db.close();
    }
}

/**
 * @brief dataLayer::getAllPersons
 * @return vector<Person>
 */
vector<Person> dataLayer::getAllPersons()
{
    QString queryString = "Select * FROM Person ORDER BY Name ";
    return getPersons(queryString);
}

/**
 * @brief dataLayer::getAllComputers
 * @return vector<Computer>
 */
vector<Computer> dataLayer::getAllComputers()
{
    QString queryString = "Select * FROM Computer ORDER BY Name ";
    return getComputers(queryString);
}

/**
 * @brief dataLayer::getAllLinks
 * @return vector<vector<int>>
 */
vector<vector<int>> dataLayer::getAllLinks()
{
    vector<vector<int>> resultMatrix;
    QString queryString = "SELECT * FROM person_computer";
    return getLinks(queryString);
}

/**
 * @brief dataLayer::getPersonByID
 * @param id
 * @return Person
 */
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

/**
 * @brief dataLayer::getComputerByID
 * @param id
 * @return Computer
 */
Computer dataLayer::getComputerByID(int id)
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

/**
 * @brief dataLayer::getFacts
 * @param table
 * @param id
 * @return vector<string>
 */
vector<string> dataLayer::getFacts(string table, int id)
{
    vector<string> resultMatrix;
    QString qTable = QString::fromStdString(table);
    qTable.append("_Fact");
    QSqlQuery query;
    query.prepare("SELECT Fact FROM " + qTable + " WHERE ID = :id");
    query.bindValue(":id", id);
    query.exec();

    while(query.next())
    {
        resultMatrix.push_back(query.value(0).toString().toStdString());
    }

    return resultMatrix;
}

/**
 * @brief dataLayer::getImage
 * @param table
 * @param id
 * @return string
 */
string dataLayer::getImage(string table, int id)
{
    string result;
    QString qTable = QString::fromStdString(table);
    qTable.append("_Image");
    QSqlQuery query;
    query.prepare("SELECT Image FROM " + qTable + " WHERE ID = :id");
    query.bindValue(":id", id);
    query.exec();

    while(query.next())
    {
        result = query.value("Image").toString().toStdString();
    }

    return result;
}

/**
 * @brief dataLayer::searchComputers
 * @param findMe
 * @return vector<Computer>
 */
vector<Computer> dataLayer::searchComputers(string findMe)
{
    QString qFindMe = QString::fromStdString(findMe);
    QString queryString = "SELECT * FROM Computer WHERE Name LIKE '%";
    queryString.append(qFindMe);
    queryString.append("%' COLLATE NOCASE OR Year LIKE '%");
    queryString.append(qFindMe);
    queryString.append("%' OR Type LIKE '%");
    queryString.append(qFindMe);
    queryString.append("%' COLLATE NOCASE");

    return getComputers(queryString);
}

/**
 * @brief dataLayer::searchPersons
 * @param findMe
 * @return vector<Person>
 */
vector<Person> dataLayer::searchPersons(string findMe)
{
    QString qFindMe = QString::fromStdString(findMe);
    QString queryString = "SELECT * FROM Person WHERE Name LIKE '%";
    queryString.append(qFindMe);
    queryString.append("%' COLLATE NOCASE OR Gender LIKE '%");
    queryString.append(qFindMe);
    queryString.append("%' COLLATE NOCASE OR Nationality LIKE '%");
    queryString.append(qFindMe);
    queryString.append("%' COLLATE NOCASE OR BirthYear LIKE '%");
    queryString.append(qFindMe);
    queryString.append("%' OR DeathYear LIKE '%");
    queryString.append(qFindMe);
    queryString.append("%'");

    return getPersons(queryString);
}

/**
 * @brief dataLayer::searchLinks
 * @param findMe
 * @return vector<vector<int>>
 */
vector<vector<int>> dataLayer::searchLinks(string findMe)
{
    QString qFindMe = QString::fromStdString(findMe);
    QString queryString = "SELECT PersonID, ComputerID FROM Person_Computer AS pc JOIN "
                          "Person AS p ON pc.personID = p.ID JOIN Computer as c ON "
                          "pc.computerID = c.ID WHERE p.Name LIKE '%";
    queryString.append(qFindMe);
    queryString.append("%' COLLATE NOCASE OR c.Name LIKE '%");
    queryString.append(qFindMe);
    queryString.append("%' COLLATE NOCASE");

    return getLinks(queryString);
}

/**
 * @brief dataLayer::updatePerson
 * @param person
 */
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

/**
 * @brief dataLayer::updateComputer
 * @param computer
 */
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
 * @brief dataLayer::updateImage
 * @param table
 * @param id
 * @param path
 */
void dataLayer::updatePersonImage(int id, string path)
{
    QSqlQuery query;
    query.prepare("UPDATE Person_Image SET Image = :path WHERE ID = :id");
    query.bindValue(":path", QString::fromStdString(path));
    query.bindValue(":id", QString::number(id));
    query.exec();
}

void dataLayer::updateComputerImage(int id, string path)
{
    QSqlQuery query;
    query.prepare("UPDATE Computer_Image SET Image = :path WHERE ID = :id");
    query.bindValue(":path", QString::fromStdString(path));
    query.bindValue(":id", QString::number(id));
    query.exec();
}

void dataLayer::deleteImage(string table, int id)
{
    if(table == "person")
    {
        updatePersonImage(id, "");
    }
    else
    {
        updateComputerImage(id, "");
    }
}

bool dataLayer::ifLinked(int personID, int computerID)
{
    QSqlQuery query;
    query.prepare("SELECT EXISTS(SELECT 1 FROM Person_Computer WHERE PersonID = :pID "
                  "AND ComputerID = :cID LIMIT 1)");
    query.bindValue(":pID", personID);
    query.bindValue(":cID", computerID);
    query.exec();

    int result = 0;

    while(query.next())
    {
        result = query.value(0).toInt();
    }

    return result;
}

