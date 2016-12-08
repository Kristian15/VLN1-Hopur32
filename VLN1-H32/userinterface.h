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
    // Used to make the user choose the correct element in vector vec to use
    // Returns that element
    template <typename T>
    T chooseWhich(vector<T> vec, string action, string type);
    // Gets a name of a Person from the user
    // Uses searchPersons() in serviceLayer to search for the name
    // Uses chooseWhich() to get the correct Person from the vector searchPersons() returns
    // If the Persons ID is -1 vec was empty or the user did not choose a element from vec
    Person getRightPerson(string action);
    // Works like getRightPerson()
    // Uses searchComputers() , returns a Computer
    Computer getRightComputer(string action);

    // *** ELSE ***
    // tests if database exists
    bool openDatabase(){ return service.openDatabase(); }
    // Used when the user wants to delete a scientist from the database
    // Uses getRightPerson() to get the Person the user wants to delete
    // Deletes the Person using deletePerson() in serviceLayer
    void deletePerson();
    // Used when the user wants to delete a computer from the database
    // Uses getRightComputer() to get the Computer the user wants to delete
    // Deletes the Computer using deleteComputer() in serviceLayer
    void deleteComputer();
    // Used when the user wants to update information about a scientist in the database
    // Uses getRightPerson() to get the Person the user wants to delete
    // Uses callUpdatePerson() in serviceLayer to update the scientist
    void updatePerson();
    // Used when the user wants to update information about a computer in the database
    // Uses getRightComputer() to get the Computer the user wants to delete
    // Uses callUpdateComputer() in serviceLayer to update the computer
    void updateComputer();
    // Used when the user wants to link a computer to a scientist
    // Uses getRightPerson() and getRightComputer() to get the Person and the Computer
    // that the user wants to link
    // Uses link() in serviceLayer to link the computer and the scientist
    void linkPersonAndComputer();
    // Used when the user wants to unlink a computer and a scientist
    // Uses getRightPerson() and getRightComputer() to get the Person and the Computer
    // that the user wants to unlink
    // Uses link() in serviceLayer to unlink the computer and the scientist
    void unlinkPersonAndComputer();
    // Used if the user wants to quit the program
    bool doYouWantToQuit();
public:
    // To run the program
    void run();
};
