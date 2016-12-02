#pragma once
#include <fstream>
#include <vector>
#include <string>
#include "person.h"

using namespace std;

class dataLayer
{
private:
    void updateData(Person person);

    vector<Person> _persons;
    vector<string> _data;
    string _fileName;

    // delimiter to format data to text file
    const string _d = ";";

public:
    // functions pertaining to changes in the database vector
    // set persons overwrites the current persons vector
    vector<Person> getPersons(){ return _persons; }
    void setPersons(vector<Person> persons){ _persons = persons; }
    void addPerson(Person person){ updateData(person); }

    // functions pertaining to file manipulation
    vector<string> loadData(string fileName);
    void saveData(string fileName, vector<Person> persons);
    void delPerson(int index){  _persons.erase(_persons.begin() + index); }
};
