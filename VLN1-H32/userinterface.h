class userInterface
{
private:
    serviceLayer service;
    void printMainMenu();// Prints the main menu:
    void printListOptions();
    void printSearchOptions();
    // Print the list to csv file
    // asks in what order it should be in
    // uses printSortOptions()
    // uses sortList() from serviceLayer
    void printList(vector<Person> printme);

// inputs:
    // gets a list of Persons(csv file) from user
    // uses createList() from the serviceLayer
    void readList();
    // gets information to create a new Person
    // uses getInput()
    // uses newPerson() in the serviceLayer
    void readPerson();
    // cout message
    // get input from user
    string getInput(string message);
    // uses printSearchOptions
    // get input from user with getInput()
    // uses searchList() from serviceLayer and printList to print it out
    void search();
    // uses printSortOptions
    // get input from user with getInput()
    // uses sortList from serviceLayer
    void print();
public:
    userInterface();
    // uses printMenu();
    // get input
        // print(), readList(), readPerson()...
        // ... search()
    void run ();
};

#endif
