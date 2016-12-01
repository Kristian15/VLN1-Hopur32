#pragma once

#include <string>
#include <iostream>
#include <ctime>
#include <algorithm>
#include "datalayer.h"
#include "person.h"


using namespace std;
class serviceLayer
{
private:
    dataLayer data;

    // sort functions:
    void sortByName();
    void sortByGender();
    void sortByNationality();
    void sortByByear();
    void sortByDyear();

    // find functions:
    vector<Person> findByName(string name);
    vector<Person> findByGender(string gender);
    vector<Person> findByNationality(string nationality);
    vector<Person> findByByear(int byear);
    vector<Person> findByDyear(int dyear);

    // validate functions:
    bool validateName(string name);
    bool validateGender(string gender);
    bool validateYear(string year);

    // toLower changes all uppercase letters in string s to lowercase letters
    string toLower(string s);
   // void splitLine(string s);

public:
    serviceLayer();

    // findMe is what you are searching for
    // by is where you are searchin for it (Name, Gender, Nationality, Birth year or Death year)
    // return vector with matches
    // ***LAGA***
    // Name to sort by name
    // Gender to sort by gender
    // Birthyear to sort by birthyear
    // Deathyear to sort by deathyear
    vector<Person> searchList(string findMe, string by);
    // sort the list in dataLayer after order
    // return the vector in dataLayer sorted
    // ***LAGA***
    vector<Person> sortList(string order);
    // break up the lines in fileName
    // uses loadData in dataLayer
    // splits the string up in name, gender, ...
    // uses createPerson()
    void createList(string fileName);

    // create a new Person and add it to persons in the dataLayer
    void newPerson(string name, string gender, string nationality, string byear, string dyear);
    void newPerson(string name, string gender, string nationality, string byear);

    // function to format a string vector to save to file
    void saveData(string fileName);
};
