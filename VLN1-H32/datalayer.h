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

    // add functions
    void addNewPerson(Person addMe);
    void addNewComputer(Computer addMe);
    void createRelation(int personID, int computerID);

    // read functions
    vector<Person> getPersons(QString queryString);
    vector<Computer> getComputers(QString queryString);
    vector<string> findRelation(QString queryString, int id);

    // delete functions
    void deleteRelation(int personID, int computerID);
    void deleteRow(string table, int id);

    // update function
    void updateItem(int id, string table, string column, string updateME);

public:
    dataLayer();
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

    bool deleteItem(string table, int id);
    // creates a relation between a comptuer and a scientist
    bool makeRelation(int personID, int computerID);
    bool unMakeRelation(int personID, int computerID);
    void addPerson(Person person);
    void addComputer(Computer computer);
};
