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
    //sort by name, birthyear, deathyear
    string sortOrder;
    // les lista af Person og setur í persons
    void readList(string fileName);

public:
    // setja í constructorinn að defaultið er by name
    userInterface();
    userInterface(string fileName);

    Person readPerson();
    void displayPersons();
    // þetta fall breytir bara sortOrder
    // kallar svo á sortList()
    void sort(string sortOrder);
    //find() spyr eftir hverju notandinn vill leita
    // kallar svo á find hjálparföllin
    void find();
};
