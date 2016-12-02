#pragma once

#include "servicelayer.h"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class userInterface
{
private:
    serviceLayer service;

    // Prints the main menu
    void printMainMenu();
    // Prints options to sort by
    void printListOptions();
    // Prints search options
    void printSearchOptions();
    // Prints search command for the input
    void printSearchCommands(int input);
    // calls printListOptions and calls sortList() from serviceLayer
    // calls printList() with the sorted list and calls ifYouWantToSave()
    void printFromDisplay();
    // calls printSearchOptions() and printSearchCommands()
    // calls searchList() from serviceLayer
    // calls printList() with the search matches
    void printFromSearch();
    // outputs inMessage, prints printMe and outputs outMessage
    void printList(vector<Person> printMe, string inMessage, string outMessage);
    // gets a fileName from user and calls createList() in serviceLayer
    void readList();
    // gets information to create a new Person
    // validates input with validateNewPerson() from serviceLayer
    // uses newPerson() from serviceLayer
    void readPerson();
    bool doYouWantToQuit();
    // called by printFromDisplay()
    void ifYouWantToSave(vector<Person> saveMe);
    void deletePerson();
public:
    void run();
};
