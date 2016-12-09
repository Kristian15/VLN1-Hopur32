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
    // Adds a new Person to the database
    void addNewComputer(Computer addMe);
    // Creates a relation between the Person with personID and the Computer with computerID
    void createRelation(int personID, int computerID);
    // Executes query using queryString and returns a vector of Persons
    vector<Person> getPersons(QString queryString);
    // Executes query using queryString and returns a vector of Persons
    vector<Computer> getComputers(QString queryString);

    vector<string> findRelation(QString queryString, int id);
    // Delete the row from table where ID = id
    void deleteRow(string table, int id);
    // Delete the row from the relation table with personID and computerID
    void deleteRelation(int personID, int computerID);
    // Updates the column with ID = id from table to updateME
    void updateItem(int id, string table, string column, string updateME);

public:
    // Constructor
    dataLayer();
    // Destructor
    ~dataLayer();

    bool openDatabase();
    vector<Person> getSortedPersons(string column, int ascDesc);
    vector<Computer> getSortedComputers(string column, int ascDesc);
    vector<Person> findPersons(string column, string findMe);
    vector<Person> searchPersonYears(string column, int from, int to);
    vector<Computer> searchComputerYears(int from, int to);
    vector<Computer> findComputers(string column, string findMe);

    void updateTable(int id, string table, string column, string updateMe);
    // return all related persons/computers
    vector<vector<string>> getRelation(string column);
    // return all related persons/computers
    vector<string> searchRelation(int id, string table);

    void deleteItem(string table, int id);
    // creates a relation between a comptuer and a scientist
    void makeRelation(int personID, int computerID);
    void unMakeRelation(int personID, int computerID);
    void addPerson(Person person);
    void addComputer(Computer computer);
};
