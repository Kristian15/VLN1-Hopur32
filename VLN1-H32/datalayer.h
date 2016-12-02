#pragma once
#include <fstream>
#include <vector>
#include <string>
#include "person.h"

using namespace std;

class dataLayer
{
private:
    // update function that appends new input to the last used document
    void updateData(Person person);

    vector<Person> _persons;
    vector<string> _data;
    string _fileName;
    const string _d = ";"; // database delimiter

public:
    // functions pertaining to file manipulation
    // set persons overwrites the current persons vector
    vector<Person> getPersons(){ return _persons; }
    vector<string> loadData(string fileName);
    void saveData(string fileName, vector<Person> persons);
    void setPersons(vector<Person> persons){ _persons = persons; }
    void addPerson(Person person){ updateData(person); }
    void delPerson(int index){  _persons.erase(_persons.begin() + index); }
};
