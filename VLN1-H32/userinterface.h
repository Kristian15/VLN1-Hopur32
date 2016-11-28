#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "servicelayer.h"
#include "person.h"

using namespace std;

class userInterface
{
private:
    vector<Person> persons;
    //sort by name, birthyear, deathyear
    string sortOrder;

    //þetta fall sorterar eftir strengnum sortOrder
    // notar sort hjálparföll
    void sortList();
    void sortByName();
    void sortByGender();
    void sortByByear();
    void sortByDyear();

    void findByName(string name);
    void findByGender(string gender);
    void findByByear(int byear);
    void findByDyear(int dyear);

public:
    // setja í constructorinn að defaultið er by name
    userInterface();
    Person readPerson();
    void readList(string fileName);
    void displayPersons();
    // þetta fall breytir bara sortOrder
    // kallar svo á sortList()
    void sort(string sortOrder);
    //find() spyr eftir hverju notandinn vill leita
    // kallar svo á find hjálparföllin
    void find();
};
