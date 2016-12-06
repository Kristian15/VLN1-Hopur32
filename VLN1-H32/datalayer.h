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

    void addNewPerson(Person addMe);
    void addNewComputer(Computer addMe);
public:
    dataLayer();
    ~dataLayer();
    vector<Person> getSortedPersons(string column);
    vector<Computer> getSortedComputers(string column);
    template <typename T>
    vector<T> find(string table, string column, string findMe);
   // vector<Person> findPersons(string column, string findMe);
  //  vector<Computer> findComputers(string column, string findMe);
    void updateTable(int id, string table, string column, string updateMe);
    // delete person that matches provided string
    bool deletePerson(int id);
    // delete computer that matches provided string
    bool deleteComputer(int id);
    // creates a relation between a comptuer and a scientist
    bool makeRelation(int personID, int computerID);
   // string getDelimeter(){ return _d; }
    // returns a vector with the lines in fileName
   // vector<string> loadData(string fileName);
    // overwrites the current persons vector
    //void setPersons(vector<Person> persons){ _persons = persons; }
    // calls updateData function to save new person and save to vector
    void addPerson(Person person){ addNewPerson(person); }
    void addComputer(Computer computer) { addNewComputer(computer); }
    // deletes person at the supplied index
    //void delPerson(int index){  _persons.erase(_persons.begin() + index); }
    template <typename T>
    vector<T> setter(QString queryString, string table);
};
