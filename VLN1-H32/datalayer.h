#pragma once
#include <fstream>
#include <vector>
#include <string>
#include "person.h"

using namespace std;

class dataLayer
{
private:
    vector<Person> _persons;
    vector<string> data;
    string _fileName;

public:
    dataLayer();

    // functions pertaining to changes in the database vector
    // set persons overwrites the current persons vector
    vector<Person> getPersons(){ return _persons; }
    void setPersons(vector<Person> persons){ _persons = persons; }
    void addPerson(Person person){ _persons.push_back(person); }

    // functions pertaining to file manipulation
    //
    void loadDataP(string fileName);
    vector<string> loadData(string fileName);
    void saveData(string fileName);
    void updateData(string name, string gender, string nationality, string byear, string dyear);
};
