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
    bool validateNationality(string nationality);
    bool validateYear(string year);
    // Creates a new person and returns it
    Person getNewPerson(string name, string gender, string nationality, string byear, string dyear);
    // Creates a new computer and returns it
    Computer getNewComputer(string name, string year, string type, string built);

public:
    bool validateNewPerson(string name, string nationality, string byear, string dyear);
    bool validateNewComputer(string year);
    // Calls getNewPerson()
    void newPerson(string name, string gender, string nationality, string byear, string dyear);
    // Calls getNewComputer()
    void newComputer(string name, string year, string type, string built);

    // Functions used to call functions from dataLayer
    void openDatabase(){ data.openDatabase(); }
    void closeDatabase() { data.closeDatabase(); }
    void addLink(int personID, int computerID) { data.addLink(personID, computerID); }
    void addImage(string table, int id) { data.addImage(table, id); }
    void addFact(string table, int id, string fact) { data.addFact(table, id, fact); }
    void updatePerson(Person person) { data.updatePerson(person); }
    void updateComputer(Computer computer) { data.updateComputer(computer); }
    void updatePersonImage(int id, string path) { data.updatePersonImage(id, path); }
    void updateComputerImage(int id, string path) { data.updateComputerImage(id, path); }
    Person getPersonByID(int id){ return data.getPersonByID(id); }
    Computer getComputerByID(int id){ return data.getComputerByID(id); }
    vector<Person> getAllPersons() { return data.getAllPersons(); }
    vector<Computer> getAllComputers() { return data.getAllComputers(); }
    vector<vector<int>> getAllLinks() { return data.getAllLinks(); }
    vector<string> getFacts(string table, int id) { return data.getFacts(table, id); }
    string getImage(string table, int id) { return data.getImage(table, id); }
    void deletePerson(int id) { data.deletePerson(id); }
    void deleteComputer(int id) {data.deleteComputer(id); }
    void deleteLink(int personID, int computerID) { data.deleteLink(personID, computerID); }
    void deleteFact(string table, int id, string fact) { data.deleteFact(table, id, fact); }
    void deleteImage(string table, int id) { data.deleteImage(table, id); }
    vector<Computer> searchComputers(string findMe) { return data.searchComputers(findMe); }
    vector<Person> searchPersons(string findMe) { return data.searchPersons(findMe); }
    vector<vector<int>> searchLinks(string findMe) { return data.searchLinks(findMe); }
    bool ifLinked(int personID, int computerID) { return data.ifLinked(personID, computerID); }
};
