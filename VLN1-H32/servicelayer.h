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
    bool openDatabase(){ return data.openDatabase(); }
    // calls findPersons() in dataLayer
    // returns a vector with the findings
    vector<Person> searchPersons(string findMe, int by);
    // calls findComputers() in dataLayer
    // returns a vector with the findings
    vector<Computer> searchComputers(string findMe, int by);
    vector<Person> searchPersonYears(int first, int second);
    vector<Computer> searchComputerYears(int first, int second);
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
    // vaidate functions that are used to validate input
    // uses the validate help functions
    // returns true if the input is valid and false otherwise
    bool validateNewPerson(string name, string gender, string nationality, string byear, string dyear);
    bool validateNewComputer(string name, string year, string type, string& built);
    // the delete functions use deleteItem() in dataLayer to delete
    // the idem with ID = id
    // return true if the item was deleted
    bool deletePerson(int id);
    bool deleteComputer(int id);
    // calls makeRelation() in dataLayer with personID and computerID
    // returns true if the connection was a success
    bool link(int personID, int computerID);
    // calls unMakeRelation() in dataLayer with personID and computerID
    // returns true if the linking was a success
    bool unLink(int personID, int computerID);
    // The update functions calls updateTable() in dataLayer with the
    // id of the item the user wants to change,
    // the column the user wants to change and the change the user wants to make
    bool callUpdatePerson(int id, int col, string updateMe);
    bool callUpdateComputer(int id, int col, string updateMe);
    // Gets all linked computers and persons by using getRelation() in dataLayer
    // returns a double vector with the information
    vector<vector<string>> getRelation(string column);
};
