#ifndef SERVICELAYER_H
#define SERVICELAYER_H
#pragma once
#include <string>
#include "datalayer.h"
#include "person.h"

using namespace std;
class serviceLayer
{
private:
    dataLayer data;
    //þetta fall sorterar eftir strengnum sortOrder
    // notar sort hjálparföll
    vector<Person> sortByName();
    vector<Person> sortByGender();
    vector<Person> sortByByear();
    vector<Person> sortByDyear();

    vector<Person> findByName(string name);
    vector<Person> findByGender(string gender);
    vector<Person> findByByear(int byear);
    vector<Person> findByDyear(int dyear);

    bool validateName(string name);
    bool validateGender(string gender);
    bool validateByear(string byear);
    bool validateDyear(string dyear);

    string toLower(string s);

    // creates a new person with the information in info
    // format: "name:gender:byear:dyear" or "name:gender:byear"
    // uses newPerson()
    void createPerson(string info);

public:
    serviceLayer();

    // findMe is what you are searching for
    // by is Name, Gender, Birth year or Death year
    // return vector with findings
    // Name to sort by name
    // Gender to sort by gender
    // Birthyear to sort by birthyear
    // Deathyear to sort by deathyear
    vector<Person> searchList(string findMe, string by);
    // sort the list in dataLayer after order
    // return the vector in dataLayer sorted
    vector<Person> sortList(string order);

    /* ef við viljum að notandi geti raðað listanum áður en hann er prentaður í search()
    þetta fall myndi þá raða sortMe eftir order
    myndi nota sort hjálparföllin
     vector<Person> sortList(vector<Person> sortMe, string order)
    */

    // break up the lines in fileName
    // uses createPerson()
    void createList(string fileName);

    // create a new Person and add it to persons in the dataLayer
    void newPerson(string name, string gender, int byear, int dyear);
    void newPerson(string name, string gender, int byear);
};


#endif
