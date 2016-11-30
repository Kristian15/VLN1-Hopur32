#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "servicelayer.h"
#include <iomanip>
using namespace std;

class userInterface
{
private:
    serviceLayer service;
    // Prints the main menu:
    void printMainMenu();
    // Prints options to sort by
    void printListOptions();
    // Prints search options
    void printSearchOptions();
    void makeVectorFromList(vector<Person>&);
    void makeVectorFromSearch(vector<Person>&);
    void printList(vector<Person> printme) const;
    // gets a list of Persons(csv file) from user
    // uses createList() from the serviceLayer
    void readList();
    // gets information to create a new Person
    // uses getInput()
    // uses newPerson() in the serviceLayer
    void readPerson();
    bool doYouWantToQuit();
    bool doYouWantToSave();
    void savefile();
    bool checkIfVectorIsEmpty(const vector<Person>);
    bool DoYouWantToContinue();

public:
    userInterface();
    void run ();
};


