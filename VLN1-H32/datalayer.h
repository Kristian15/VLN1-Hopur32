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

    vector<Person> getPersons(){ return _persons; }
    void setPersons(vector<Person> persons){ _persons = persons; }
    void addPerson(Person person){ _persons.push_back(person); }

    // skilar línunum í fileName sem vektor af strengjum
    vector<Person> loadDataP(string fileName);
    vector<string> loadData(string fileName); // hlaða inn gögnum inn í forritið við ræsingu
    void saveData(vector<Person> persons, string fileName); // vista gögn
    void updateFile(string name, string gender, string nationality, string byear, string dyear); // update dataFile
};
