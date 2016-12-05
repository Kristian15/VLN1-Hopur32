#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <QtSql>
#include "person.h"

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
    void updateData(Person person);
public:
    dataLayer();
    ~dataLayer();
    vector<Person> getPersons(){ return _persons; }
    string getDelimeter(){ return _d; }
    // returns a vector with the lines in fileName
    vector<string> loadData(string fileName);
    // save data to supplied fileName, if fileName == "current" it saves to current filename
    void saveData(string fileName, vector<Person> persons);
    // overwrites the current persons vector
    void setPersons(vector<Person> persons){ _persons = persons; }
    // calls updateData function to save new person and save to vector
    void addPerson(Person person){ updateData(person); }
    // deletes person at the supplied index
    void delPerson(int index){  _persons.erase(_persons.begin() + index); }
};
