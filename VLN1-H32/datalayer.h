#pragma once
#include <fstream>
#include <QFileInfo>
#include <vector>
#include <string>
#include <QtSql>
#include "person.h"
#include "computer.h"

using namespace std;

class dataLayer
{
private:
    const QString DB_DRIVER_TYPE = "QSQLITE";
    const QString DB_NAME = "skil2.sqlite";
    QSqlDatabase db;

    // Adds a new Person to the database
    void addNewPerson(Person addMe);
    // Adds a new Computer to the database
    void addNewComputer(Computer addMe);
    // Creates a relation between the Person with personID and the Computer with computerID
    void createRelation(int personID, int computerID);
    void createPersonFact(int personID, string fact);
    void createComputerFact(int computerID, string fact);
    // Executes query using queryString and returns a vector of Persons
    vector<Person> getPersons(QString queryString);
    // Executes query using queryString and returns a vector of Computers
    vector<Computer> getComputers(QString queryString);
    // Delete the row from table where ID = id
    void deleteRow(string table, int id);
    // Delete the row from the relation table with personID and computerID
    void deleteRelation(int personID, int computerID);
    void deleteFact(QString queryString);

public:
    // Constructor
    dataLayer();
    // Destructor
    ~dataLayer();
    // Checks if the database exists or not and opens it if does exists
    bool openDatabase();

    void closeDatabase();
    // Uses addNewPerson()
    void addPerson(Person person);
    // Uses addNewComputer()
    void addComputer(Computer computer);
    // Gets all scientists from the database sorted after column and ascDesc
    // Returns a vector of Persons with the sorted list
    // Uses getPersons()
    Person getPersonByID(int id);
    Computer getCompByID(int id);

    vector<Person> getPers();
    vector<Computer> getComps();

    vector<Person> getSortedPersons(string column, int ascDesc);
    // Gets all computers from the database sorted after column and ascDesc
    // Returns a vector of Computer with the sorted list
    // Uses getComputers()
    vector<Computer> getSortedComputers(string column, int ascDesc);
    // Return all related persons/computers
    // Returns a double vector where first element in every row is the name of the scientist/computer
    // the following elements are the scientists/computers that are linked to it
    vector<vector<int>> getRelation();
    // Return related persons/computers from the item with ID = id
    vector<string> searchRelation(int id, string table);

    void updatePerson(Person person);
    void updateComputer(Computer computer);
    // Uses deleteRow() to delete
    void deleteItem(string table, int id);
    // Creates a relation between a computer and a scientist
    // Uses createRelation()
    void makeRelation(int personID, int computerID);
    // Removes a relation between a computer and a scientist
    // Uses deleteRelation()
    void unMakeRelation(int personID, int computerID);
    void createFact(string table, int id, string fact);
    void deleteFact(string table, int id, string fact);
    vector<string> getFacts(string table, int id);
    vector<Computer> searchComputers(string findMe);
    vector<Person> searchPersons(string findMe);
    void updateImage(string table, int id, string path);
    void deleteImage(string table, int id);
    void addNewImage(string table, int id);
};
