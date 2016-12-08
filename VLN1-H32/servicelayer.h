#pragma once

#include <string>
#include <ctime>
#include "datalayer.h"
#include "person.h"

using namespace std;

class serviceLayer
{
private:
    dataLayer data;
    // validate functions, called by validateNewPerson():
    // return true if the inputs are valid and false otherwise
    bool validateName(string name);
    bool validateGender(string gender);
    bool validateNationality(string nationality);
    bool validateYear(string year);
    bool validateBuilt(string& built);
    // creates a new person and returns it
    Person getNewPerson(string name, string gender, string nationality, string byear, string dyear);
    // creates a new computer and returns it
    Computer getNewComputer(string name, string year, string type, string built);

public:
    // calls findPersons() in dataLayer
    // returns a vector with the findings
    vector<Person> searchPersons(string findMe, int by);
    // calls findComputers() in dataLayer
    // returns a vector with the findings
    vector<Computer> searchComputers(string findMe, int by);
    // calls getSortedPersons() in dataLayer
    // returns a vector with the sorted scientists
    vector<Person> sortPersons(int order, int ascOrDesc);
    // calls getSortedComputers() in dataLayer
    // returns a vector with the sorted computers
    vector<Computer> sortComputers(int order, int ascOrDesc);
    // calls the help function getPerson() that returns a Person
    void newPerson(string name, string gender, string nationality, string byear, string dyear);
    // calls the help function getComputer() that returns a Computer
    void newComputer(string name, string year, string type, string built);
    // validate input that are used to create a new Person
    // uses the validate help functions
    // returns true if the input is valid and false otherwise
    bool validateNewPerson(string name, string gender, string nationality, string byear, string dyear);
    bool validateNewComputer(string name, string year, string type, string& built);
    // calls findAndDelete()
    // calls saveData() in dataLayer with the string 'current' and the persons vector from dataLayer
    bool deletePerson(int id);
    bool deleteComputer(int id);
    bool link(int personID, int computerID);
    bool unLink(int personID, int computerID);
    bool callUpdatePerson(int id, int col, string updateMe);
    bool callUpdateComputer(int id, int col, string updateMe);
    vector<vector<string>> getRelation(string column);
};
