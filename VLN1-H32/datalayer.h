#pragma once
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
    void addNewFact(string table, int id, string fact);
    // get functions
    // Executes query using queryString and return the findings
    vector<Person> getPersons(QString queryString);
    vector<Computer> getComputers(QString queryString);
    // Linked computer and scientist are added to the same vector
    // returns a vector of vectors with the ID numbers
    vector<vector<int>> getLinks(QString queryString) ;

    // Delete functions
    // deleteItem uses deleteItemLinks(), deleteItemFacts() and deleteItemImage()
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
    vector<Person> getPersonsByName(string name);
    vector<Computer> getComputersByName(string name);
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
    void updatePersonImage(int id, string path);
    void updateComputerImage(int id, string path);
    // delete image from person_image or computer_images tables
    void deleteImage(string table, int id);
    // returns true if personID and computerID are already linked
    bool ifLinked(int personID, int computerID);
};
