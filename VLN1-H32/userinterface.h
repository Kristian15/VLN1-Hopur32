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
    // *** PRINT INSTRUCTIONS FUNCTIONS ***
    // Prints the main menu
    void printMainMenu();
    // Prints options to sort by
    void printDisplayPersonsOptions();
    void printDisplayComputersOptions();
    // Prints search options
    void printSearchPersonsOptions();
    void printSearchComputersOptions();
    // Prints search command for the input
    void printSearchPersonsCommands(int input);
    void printSearchComputersCommands(int input);

    // *** PRINT FUNCTIONS ***
    // calls printListOptions and calls sortList() from serviceLayer
    // calls printList() with the sorted list and calls ifYouWantToSave()
    void printPersonsFromDisplay();
    void printComputersFromDisplay();
    // calls printSearchOptions() and printSearchCommands()
    // calls searchList() from serviceLayer
    // calls printList() with the search matches
    void printPersonsFromSearch();
    void printComputerFromSearch();
    // outputs inMessage, prints printMe and outputs outMessage
    void printPersons(vector<Person> printMe, string inMessage, string outMessage);
    void printComputers(vector<Computer> printMe, string inMessage, string outMessage);

    // *** INPUT FUNCTIONS ***
    // gets information to create a new Person
    // validates input with validateNewPerson() from serviceLayer
    // uses newPerson() from serviceLayer
    void readPerson();
    void readComputer();
    int getCorrectInt(int max);

    // *** ELSE ***
    void deletePerson();
    void deleteComputer();
    void linkPersonAndComputer();
    bool doYouWantToQuit();
    template <typename T>
    T chooseWhich(vector<T> delItem, string s1, string s2, string s3);
public:
    void run();
};
