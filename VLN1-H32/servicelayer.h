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
    // Validate functions, called by validateNewPerson():
    // Return true if the inputs are valid and false otherwise
    bool validateName(string name);
    bool validateGender(string gender);
    bool validateNationality(string nationality);
    bool validateYear(string year);
    bool validateBuilt(string& built);
    // Creates a new person and returns it
    Person getNewPerson(string name, string gender, string nationality, string byear, string dyear);
    // Creates a new computer and returns it
    Computer getNewComputer(string name, string year, string type, string built);

public:
    Person getPersonByID(int id){ return data.getPersonByID(id); }
    Computer getCompByID(int id){ return data.getCompByID(id); }
    vector<Person> getPersons() { return data.getPers(); }
    vector<Computer> getComputers() { return data.getComps(); }
    bool openDatabase(){ return data.openDatabase(); }
    void closeDatabase() { data.closeDatabase(); }
    // Calls getSortedPersons() in dataLayer
    // Returns a vector with the sorted scientists
    vector<Person> sortPersons(int order, int ascOrDesc);
    // Calls getSortedComputers() in dataLayer
    // Returns a vector with the sorted computers
    vector<Computer> sortComputers(int order, int ascOrDesc);
    // Calls the help function getPerson() that returns a Person
    void newPerson(string name, string gender, string nationality, string byear, string dyear);
    // Calls the help function getComputer() that returns a Computer
    void newComputer(string name, string year, string type, string built);
    // Vaidate functions that are used to validate input
    // Uses the validate help functions
    // Returns true if the input is valid and false otherwise
    bool validateNewPerson(string name, string nationality, string byear, string dyear);
    bool validateNewComputer(string name, string year, string type);
    // The delete functions use deleteItem() in dataLayer to delete
    // the idem with ID = id
    void deletePerson(int id);
    void deleteComputer(int id);
    // Calls makeRelation() in dataLayer with personID and computerID
    void link(int personID, int computerID);
    // Calls unMakeRelation() in dataLayer with personID and computerID
    void unLink(int personID, int computerID);
    // The update functions calls updateTable() in dataLayer with the
    // id of the item the user wants to change,
    // the column the user wants to change and the change the user wants to make
    // returns true if updateMe is a valid input
    void updatePerson(Person person);
    void updateComputer(Computer computer);
    // Gets all linked computers and persons by using getRelation() in dataLayer
    // Returns a double vector with the information
    vector<vector<string>> getRelation();
    // Gets all links to the item with ID = id from table
    // Uses searchRelation() in dataLayer
    vector<string> getOneRelation(int id, string table);
    vector<Computer> searchComputers(string input);
    vector<Person> searchPersons(string input);
    vector<string> getFacts(string table, int id);
    void createFact(string table, int id, string fact);

};
