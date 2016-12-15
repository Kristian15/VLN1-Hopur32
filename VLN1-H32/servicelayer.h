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
    Computer getComputerByID(int id){ return data.getComputerByID(id); }
    //*********!!!!!!!!!!
    vector<Person> getAllPersons() { return data.getAllPersons(); }
    //*****************!!!!!!!!!!!!!!!!!!1
    vector<Computer> getAllComputers() { return data.getAllComputers(); }
    //************!!!!!!!!!!!!
    vector<vector<int>> getAllLinks() { return data.getAllLinks(); }
    //*********!!!!!!!!!
    void openDatabase(){ data.openDatabase(); }
    //*************!!!!!!!
    void closeDatabase() { data.closeDatabase(); }
    void newPerson(string name, string gender, string nationality, string byear, string dyear);
    // Calls the help function getComputer() that returns a Computer
    void newComputer(string name, string year, string type, string built);

    bool validateNewPerson(string name, string nationality, string byear, string dyear);
    bool validateNewComputer(string name, string year, string type);
    void deletePerson(int id) { data.deletePerson(id); }
    void deleteComputer(int id) {data.deleteComputer(id); }
    void link(int personID, int computerID) { data.addLink(personID, computerID); }
    void unLink(int personID, int computerID) { data.deleteLink(personID, computerID); }
    void updatePerson(Person person) { data.updatePerson(person); }
    void updateComputer(Computer computer) { data.updateComputer(computer); }

    vector<Computer> searchComputers(string findMe) { return data.searchComputers(findMe); }
    vector<Person> searchPersons(string findMe) { return data.searchPersons(findMe); }
    vector<string> getFacts(string table, int id) { return data.getFacts(table, id); }
    void addFact(string table, int id, string fact) { data.addFact(table, id, fact); }
    void deleteFact(string table, int id, string fact) { data.deleteFact(table, id, fact); }
    void updateImage(string table, int id, string path) { data.updateImage(table, id, path); }
    void deleteImage(string table, int id) { data.deleteImage(table, id); }
    void addImage(string table, int id) { data.addImage(table, id); }
    string getImage(string table, int id) { return data.getImage(table, id); }
    vector<vector<int>> searchLinks(string findMe) { return data.searchLinks(findMe); }

};


