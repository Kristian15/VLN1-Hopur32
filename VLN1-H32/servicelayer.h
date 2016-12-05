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
    // toLower changes all uppercase letters in string s to lowercase letters
  //  string toLower(string s);
    // splitLine takes string s in the format: "name;gender;nationality;birth year;death year;"
    // splits the line where ";" is and adds it to newPersons
    void splitAndAdd(string s, int index);
    // creates a new person and returns it
    Person getNewPerson(string name, string gender, string nationality, string byear, string dyear);

public:
    // searchList() calls the correct find help function with findMe as input
    // returns a vector with the findings
    vector<Person> searchPersons(string findMe, int by);
//    vector<Computer> searchComputers(string finMe, int by);
    // sortList() calls the correct sort help function
    // returns the vector in dataLayer
    vector<Person> sortPersons(int order);
//    vector<Computer> sortComputers(int order);
    // uses loadData in dataLayer and gets a vector of strings from the file back
    // calls splitLine() with a vector of Persons that is called by reference
    // calls setPersons() in dataLayer with the vector
    void createList(string fileName);
    // calls the help function getPerson() that returns a Person
    // calls data.addPerson with that Person
    void newPerson(string name, string gender, string nationality, string byear, string dyear);
    // validate input that are used to create a new Person
    // uses the validate help functions
    // returns true if the input is valid and false otherwise
    bool validateNewPerson(string name, string gender, string nationality, string byear, string dyear);
    // function to call saveData() in dataLayer with these parameters
    void saveData(string fileName, vector<Person> saveMe);
    // calls findAndDelete()
    // calls saveData() in dataLayer with the string 'current' and the persons vector from dataLayer
    void deletePerson(string name);
};
