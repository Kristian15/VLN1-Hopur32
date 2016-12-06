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


    vector<Person> _persons; // the database
    string _fileName; // current fileName
    const string _d = ";"; // database delimiter
    // appends person to the last used document
    void addNewPerson(Person person);
    void addNewComputer(Computer computer);
public:
    dataLayer();
    ~dataLayer();
    vector<Person> getPersons(){ return _persons; }

    vector<Person> getSortedPersons(string order);
    vector<Person> findPersons(string column, string findMe);
    vector<Computer> getSortedComputers(string order);
    vector<Computer> findComputers(string column, string findMe);

    void updateTable(int id, string table, string column, string updateMe);

    // delete person that matches provided string
    bool deletePerson(int deleteMe);
    // delete computer that matches provided string
    bool deleteComputer(int deleteMe);
    // creates a relation between a comptuer and a scientist
    bool makeRelation(int scientist, int computer);

    string getDelimeter(){ return _d; }
    // returns a vector with the lines in fileName
    vector<string> loadData(string fileName);
    // overwrites the current persons vector
    void setPersons(vector<Person> persons){ _persons = persons; }
    // calls updateData function to save new person and save to vector
    void addPerson(Person person){ addNewPerson(person); }
    void addComputer(Computer computer) { addNewComputer(computer); }
    // deletes person at the supplied index
    void delPerson(int index){  _persons.erase(_persons.begin() + index); }
};
