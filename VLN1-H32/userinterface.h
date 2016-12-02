#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "servicelayer.h"
#include <iomanip>
#include <windows.h>
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
    void printSearchCommands(int input);
    void vectorFromList();
    void vectorFromSearch();
    void printList(vector<Person> printme);
    // gets a list of Persons(csv file) from user
    // uses createList() from the serviceLayer
    void printSearch(vector<Person> printme);
    void readList();
    // gets information to create a new Person
    // uses getInput()
    // uses newPerson() in the serviceLayer
    void readPerson();
    bool doYouWantToQuit();
    void doYouWantToSave();
    void savefile();
    bool checkIfVectorIsEmpty(const vector<Person> amIEmpty);
    bool doYouWantToContinue();
public:
    void run ();
};


