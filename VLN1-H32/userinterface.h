#ifndef USERINTERFACE_H
#define USERINTERFACE_H

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

    //sort by name, gender, birthyear or deathyear
    string sortOrder;
    // les lista af Person og setur í persons í gegnum readPerson í servicelayer
    void readList(string fileName);

public:
    userInterface();
    void run();
    //les inn nýja person frá notenda
    Person readPerson();
    //prentar út allar persons í vectornum persons í datalayer
    void displayPersons();
    /*
    // setja í constructorinn að defaultið er by name
    userInterface(string fileName);
    // þetta fall breytir bara sortOrder
    // kallar svo á sortList()
    void sort(string sortOrder);
    //find() spyr eftir hverju notandinn vill leita
    // kallar svo á find hjálparföllin
    void find();
    */
};

#endif
