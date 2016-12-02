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
    // *** functions pertaining to file manipulation ***
    // getPersons returns the persons vector
    vector<Person> getPersons(){ return _persons; }
    // load from data file
    vector<string> loadData(string fileName);
    // save data to supplied fileName, if fileName == "current" it saves to current filename
    void saveData(string fileName, vector<Person> persons);
    // set persons overwrites the current persons vector
    void setPersons(vector<Person> persons){ _persons = persons; }
    // calls updateData function to save new person and save to vector
    void addPerson(Person person){ updateData(person); }
    // delets person at the supplied index
    void delPerson(int index){  _persons.erase(_persons.begin() + index); }
};
