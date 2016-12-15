#pragma once
#include <fstream>
#include <QFileInfo>
#include <vector>
#include <string>
#include <QtSql>
#include "person.h"
#include "computer.h"

using namespace std;

class dataLayer
{
private:
    QSqlDatabase db;
    const QString DB_DRIVER_TYPE = "QSQLITE";
    const QString DB_NAME = "skil2.sqlite";

    // Add functions
    void addNewPerson(Person addMe);
    void addNewComputer(Computer addMe);
    void addNewLink(int personID, int computerID);
    void addNewFact(string table, int ID, string fact);
    void addNewImage(string table, int id);
    // get functions
    // Executes query using queryString and return the findings
    vector<Person> getPersons(QString queryString);
    vector<Computer> getComputers(QString queryString);
    vector<vector<int>> getLinks(QString queryString) ;

    // Delete functions
    void deleteItem(string table, int id);
    void deleteRelation(int personID, int computerID);
    void deleteFactPriv(string table, int id, string fact);
    // Delete help functions for deleteItem
    // Deletes all information about the item with ID = id from
    // Links, Facts and Image tables
    void deleteItemLinks(QString qTable, int id);
    void deleteItemFacts(QString qTable, int id);
    void deleteItemImage(QString qTable, int id);

public:
    // Constructor
    dataLayer(){}
    // Destructor
    ~dataLayer() { db.close(); }
    // open / close database
    void openDatabase();
    void closeDatabase();

    // functions to call private functions
    void addPerson(Person person) { addNewPerson(person); }
    void addComputer(Computer computer) {addNewComputer(computer); }
    void addImage(string table, int id) { addNewImage(table, id); }
    void addLink(int personID, int computerID) { addNewLink(personID, computerID); }
    void addFact(string table, int id, string fact) { addNewFact(table, id, fact); }
    void deletePerson(int id) { deleteItem("Person", id); }
    void deleteComputer(int id) { deleteItem("Computer", id); }
    void deleteLink(int personID, int computerID) { deleteRelation(personID, computerID); }
    void deleteFact(string table, int id, string fact) {deleteFactPriv(table, id, fact); }
    // functions to fill in to the tables in UI
    vector<Person> getAllPersons();
    vector<Computer> getAllComputers();
    vector<vector<int>> getAllLinks();
    // get Person with ID = id
    Person getPersonByID(int id);
    // get Computer with ID = id
    Computer getComputerByID(int id);
    // get all facts about item from table with ID = id
    vector<string> getFacts(string table, int id);
    // get image of item from table with ID = id
    string getImage(string table, int id);
    // search functions for filters in tables in UI
    vector<Computer> searchComputers(string findMe);
    vector<Person> searchPersons(string findMe);
    vector<vector<int>> searchLinks(string findMe);
    // update functions
    void updatePerson(Person person);
    void updateComputer(Computer computer);
    void updateImage(string table, int id, string path);
    void deleteImage(string table, int id) { updateImage(table, id, ""); }
};
