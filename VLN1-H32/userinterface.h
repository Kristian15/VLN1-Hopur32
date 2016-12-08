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
    // Prints options to sort scientists by
    void printDisplayPersonsOptions();
    // Prints options to sort computers by
    void printDisplayComputersOptions();
    // Prints search options for the scientists
    void printSearchPersonsOptions();
    // Prints search options for the computers
    void printSearchComputersOptions();
    // Prints the update scientist options
    void printUpdatePersonOptions();
    // Prints the update computer options
    void printUpdateComputerOptions();
    // Prints search command for the input
    void printSearchPersonsCommands(int input);
    void printSearchComputersCommands(int input);

    // *** PRINT FUNCTIONS ***
    // Called when the user wants to display all scientists
    // Gets the sorted list using sortPersons() in serviceLayer
    // Prints the list using printPersons()
    void printPersonsFromDisplay();
    // Called when the user wants to display all computers
    // Gets the sorted list using sortComputers() in serviceLayer
    // Prints the list using printComputers()
    void printComputersFromDisplay();
    // Prints all links between Scientists and Computers
    // Uses getRelation() in serviceLayer
    void printLinkedComputersAndPersonsFromDisplay();
    // Called when the use wants to search the scientists
    // Uses searchPersons() in serviceLayer to search the database
    // Prints using printPersons()
    void printPersonsFromSearch();
    // Calles when the user wants to search the computer
    // Uses serachComputers() in serviceLayer to search the database
    // Prints using printComputers()
    void printComputerFromSearch();
    // outputs inMessage, prints printMe and outputs outMessage
    void printPersons(vector<Person> printMe, string inMessage, string outMessage);
    // outputs inMessage, prints printMe and outputs outMessage
    void printComputers(vector<Computer> printMe, string inMessage, string outMessage);

    // *** INPUT FUNCTIONS ***
    // gets information to create a new Person
    // validates input with validateNewPerson() in serviceLayer
    // uses newPerson() in serviceLayer
    void readPerson();
    // gets information to create a new Computer
    // validates input with validateNewComputer() in serviceLayer
    // uses newComputer() in serviceLayer
    void readComputer();
    // Asks the user for a integer value
    // If the value is a integer between 1 and max the function returns the integer
    // else it asks the user for another integer
    int getCorrectInt(int max);
    // Used to display delItem and make the user choose which element in delItem he wants to use
    // The function returns that item
    template <typename T>
    T chooseWhich(vector<T> vec, string action, string type);
    Person getRightPerson(string action);
    Computer getRightComputer(string action);

    // *** ELSE ***
    // Used when the user wants to delete a scientist from the database
    // Asks for the name of the scientist the user wants to delete
    // Uses searchPersons() in serviceLayer to find matches
    // Uses chooseWhich() to get the scientist the user wants to delete out of the ones found
    // Uses deletePerson() in serviceLayer to delete the scientist
    void deletePerson();
    // Used when the user wants to delete a computer from the database
    // Works like deletePerson()
    // Uses searchComputers() and deleteComputer() in serviceLayer
    void deleteComputer();
    // Used when the user wants to update information about a scientist in the database
    // Asks for the name of the scientist the user wants to delete
    // Uses searchPersons() in serviceLayer to find matches
    // Uses chooseWhich() to get scientists the user wants to update out of the ones found
    // Uses callUpdatePerson() in serviceLayer to update the scientist
    void updatePerson();
    // Used when the user wants to update information about a computer in the database
    // Works like updatePerson()
    // Uses searchComputers() and callUpdateComputer() in serviceLayer
    void updateComputer();
    // Used when the user wants to link a computer to a scientist
    // Asks for the names of the scientist and computer
    // Uses searchPerons() and searchComputers() in serviceLayer to find matches
    // Uses chooseWhich() to get get the scientist and computer the user wants to use
    // Uses link() in serviceLayer to link the computer and the scientist
    void linkPersonAndComputer();
    void unlinkPersonAndComputer();
    bool doYouWantToQuit();
public:
    void run();
};
