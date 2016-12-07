#pragma once
#include <fstream>
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

    // functions that add, remove or change values in database are private
    void addNewPerson(Person addMe);
    void addNewComputer(Computer addMe);
    void deleteRow(string table, int id);
    void updateItem(int id, string table, string column, string updateME);
    void createRelation(int personID, int computerID);
    void deleteRelation(int personID, int computerID);
public:
    dataLayer();
    ~dataLayer();
    vector<Person> getSortedPersons(string column, int ascDesc);
    vector<Computer> getSortedComputers(string column, int ascDesc);
    vector<Person> findPersons(string column, string findMe);
    vector<Computer> findComputers(string column, string findMe);
    void updateTable(int id, string table, string column, string updateMe);
    // return all related persons/computers by the provided id
    vector<Person> relatedPersons(int ascDesc);
    vector<vector <string> > relatedComputers(int ascDesc);

    bool deleteItem(string table, int id);
    // delete person that matches provided string
    bool deletePerson(int id);
    // delete computer that matches provided string
    bool deleteComputer(int id);
    // creates a relation between a comptuer and a scientist
    bool makeRelation(int personID, int computerID);
    bool dataLayer::unMakeRelation(int personID, int computerID);
    void addPerson(Person person);
    void addComputer(Computer computer);
};
