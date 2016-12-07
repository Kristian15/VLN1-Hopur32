#include "userinterface.h"

//numeration for switch case in main menu
enum inputcases { Display_Scientis = 1, Display_Computer, Display_Linked_Computers_and_Scientists, Add_Scientis, Add_Computer, Delete_Scientist, Delete_Computer, Search_Scientist, Search_Computer, Link_Scientist_and_Computer, Quit};

void userInterface::run()
{

    cout << " ______    ____   __    ______   __    _   _______   __    ______   _______    ______           " << endl;
    cout << "/  ____|  /  __/ |  |  |  ____| |  \\  | | |__   __| |  |  /  ____| |__   __|  /  ____|         " << endl;
    cout << "\\  `--.  | |     |  |  | |_     |   \\ | |    | |    |  |  \\  `--.     | |     \\  `--.       " << endl;
    cout << " `---. \\ | |     |  |  |  _|    | |\\ \\| |    | |    |  |   `---. \\    | |      `---. \\     " << endl;
    cout << "/\\___/ / | \\___  |  |  | |____  | | \\   |    | |    |  |  /\\___/ /    | |     /\\___/ /     " << endl;
    cout << "\\_____/   \\____/ |__|  |______| |_|  \\__|    |_|    |__|  \\_____/     |_|     \\_____/      " << endl;
    cout << endl;

    bool quit = false;
    int input = 0;
    do{
        printMainMenu();
        input = getCorrectInt(11);
        switch (input)
        {
        case Display_Scientis:
            printPersonsFromDisplay();
            break;
        case Display_Computer:
            printComputersFromDisplay();
            break;
        case Display_Linked_Computers_and_Scientists:
            printLinkedComputersAndPersonsFromDisplay();
            break;
        case Add_Scientis:
            readPerson();
            break;
        case Add_Computer:
            readComputer();
            break;
        case Delete_Scientist:
            deletePerson();
            break;
        case Delete_Computer:
            deleteComputer();
            break;
        case Search_Scientist:
            printPersonsFromSearch();
            break;
        case Search_Computer:
            printComputerFromSearch();
            break;
        case Link_Scientist_and_Computer:
            linkPersonAndComputer();
            break;
        case Quit:
            quit = doYouWantToQuit();
            break;
        default:
            cout << endl << "Invalid Input!" << endl;
            break;
        }
   }while(!quit);
}

// *** PRIVATE ***
void userInterface::printMainMenu()
{
    cout << "Please enter one of the following commands:" << endl;
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << "1 = Display Scientist   - Displays Scientists data in the selected order" << endl;
    cout << "2 = Display Computer    - Displays Computer data in the selected order" << endl;
    cout << "3 = Display linked C&S  - Displays linked Computers and Scientists in the selected order;" << endl;
    cout << "4 = Add Scientist       - Adds scientist to your database" << endl;
    cout << "5 = Add Computer        - Adds computer to your database" << endl;
    cout << "6 = Delete Scientist    - Deletes scientist from you database" << endl;
    cout << "7 = Delete Computer     - Deletes computer from you database" << endl;
    cout << "8 = Search Scientist    - Search for a scientist in your database" << endl;
    cout << "9 = Search Computer     - Search for a computer in your database" << endl;
    cout << "10 = Link               - Link Scientist and Computer" << endl;
    cout << "11 = quit               - Quit the program" << endl;
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << "Input: ";
}

void userInterface::printDisplayPersonsOptions()
{
    cout << "Please enter one of the 5 following options to sort by:" << endl;
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << "1 = Name         - Sort the scientists in alphabetic order" << endl;
    cout << "2 = Gender       - Sort the scientists, showing females first" << endl;
    cout << "3 = Nationality  - Sort the scientists by their nationality" << endl;
    cout << "4 = Birthyear    - Sort the scientists by date of birth" << endl;
    cout << "5 = Deathyear    - Sort the scientists by who deceased first" << endl;
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << "Input: ";
}

void userInterface::printDisplayComputersOptions()
{
    cout << "Please enter one of the following options to sort by: " << endl;
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << "1 = Name  - sort the computers by name" << endl;
    cout << "2 = Year  - sort the computer by year designed" << endl;
    cout << "3 = Type  - sort the computer by type" << endl;
    cout << "4 = Built - show computers that were built;" << endl;
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << "Input: ";
}

void userInterface::printSearchPersonsOptions()
{
    cout << "Please enter one of the following options to search by:" << endl;
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << "1 = Name          - Search for scientists with a specific name" << endl;
    cout << "2 = Gender        - Search for scientists with specific gender (male / female)" << endl;
    cout << "3 = Nationality   - Search for scientists with a specific nationality" << endl;
    cout << "4 = Year of birth - Search for scientists with a specific birth year" << endl;
    cout << "5 = Year of death - Search for scientists with a specific death year" << endl;
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << "Input: ";
}

void userInterface::printSearchComputersOptions()
{
    cout << "Please enter one of the following optins to searh by" << endl;
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << "1 = Name    - Search for computers with a specific name" << endl;
    cout << "2 = Year    - Search for computers from a specific year" << endl;
    cout << "3 = Type    - Search for computers of a specific type" << endl;
    cout << "4 = Built   - Search for computers that were built or not (Y / N)" << endl;
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << "Input: ";
}

void userInterface::printSearchPersonsCommands(int input)
{
    if(input == 1)
    {
        cout << "Enter the name you want to search for: " << endl;
        cout << "Name: ";
    }
    else if(input == 2)
    {
        cout << "Enter either \"male\" or \"female\": " << endl;
        cout << "Gender: ";
    }
    else if(input == 3)
    {
        cout << "Enter nationality: " << endl;
        cout << "Nationality: ";
    }
    else if(input == 4)
    {
        cout << "Enter the year of birth you want to search for: " << endl;
        cout << "Year of birth: ";
    }
    else if(input == 5)
    {
        cout << "Enter the year of death you want to search for: " << endl;
        cout << "Year of death: ";
    }
}

void userInterface::printSearchComputersCommands(int input)
{
    if(input == 1)
    {
        cout << "Enter the name you want to search for: " << endl;
        cout << "Name: ";
    }
    else if(input == 2)
    {
        cout << "Enter from what year the computer is you want to search for: " << endl;
        cout << "Year: ";
    }
    else if(input == 3)
    {
        cout << "Enter the type of computer you want to search for: " << endl;
        cout << "Type: ";
    }
    else if(input == 4)
    {
        cout << "Enter if the computer was built or not " << endl;
        cout << "Y/N: ";
    }
}

void userInterface::printPersonsFromDisplay()
{
    printDisplayPersonsOptions();
    int input = getCorrectInt(5);
    cout << "Do you want the list in ascending or descending order (1/2) ?" << endl;
    int ascDesc = getCorrectInt(2);
    vector<Person> sorted = service.sortPersons(input, ascDesc);
    printPersons(sorted, "Here is your list sorted: " , "Your database is empty! Please add database from \"Open file\" in Main Menu");
}

void userInterface::printComputersFromDisplay()
{
    printDisplayComputersOptions();
    int input = getCorrectInt(4);
    cout << "Do you want the list in ascending or descending order (1/2) ?" << endl;
    int ascDesc = getCorrectInt(2);
    vector<Computer> sorted = service.sortComputers(input, ascDesc);
    printComputers(sorted, "Here is your list sorted: " , "Your database is empty! Please add database from \"Open file\" in Main Menu");
}
void userInterface::printLinkedComputersAndPersonsFromDisplay()
{
    cout << "Do you want to the list by name of Scientists or by name of computers? (1/2)" << endl;
    cout << "Input: ";
    int inputnameorcomputer = getCorrectInt(2);
    cout << "Do you want the list in ascending or descending order (1/2) ?" << endl;
    cout << "Input: ";
    int inputascordesc = getCorrectInt(2);
    if(inputnameorcomputer == 1)
    {
        cout << "ble";
    }
    else
    {
        cout << "blu";
    }

}

void userInterface::printPersonsFromSearch()
{
    printSearchPersonsOptions();
    int searchBy = getCorrectInt(5);
    string searchFor;
    printSearchPersonsCommands(searchBy);
    cin >> ws;
    getline(cin, searchFor);
    cout << endl;
    printPersons(service.searchPersons(searchFor, searchBy), "Search results: ", "No match!");
}

void userInterface::printComputerFromSearch()
{
    printSearchComputersOptions();
    int searchBy = getCorrectInt(4);
    string searchFor;
    printSearchComputersCommands(searchBy);
    cin >> ws;
    getline(cin, searchFor);
    cout << endl;
    printComputers(service.searchComputers(searchFor, searchBy), "Search results: ", "No match!");
}

void userInterface::printPersons(vector<Person> printMe, string inMessage, string outMessage)
{
    const char seperator = ' ';
    const int indexWidth = 6;
    const int nameWidth  = 30;
    const int genderWidth = 10;
    const int nationalitWidth = 25;
    const int birthYearWidth = 12;
    const int deathYearWidth = 12;

    if(!printMe.empty())
    {
        cout << inMessage << endl;
        cout << left << setw(indexWidth) << setfill(seperator) << "Index";
        cout << left << setw(nameWidth) << setfill(seperator) << "Name";
        cout << left << setw(genderWidth) << setfill(seperator) << "Gender";
        cout << left << setw(nationalitWidth) << setfill(seperator) << "Nationality";
        cout << left << setw(birthYearWidth) << setfill(seperator) << "Birth Year";
        cout << left << setw(deathYearWidth) << setfill(seperator) << "Death Year" << endl;
        cout << left << setfill('-') << setw(90) << "-" << endl;

        for(unsigned int i = 0; i < printMe.size(); i++)
        {
            cout << left << setw(indexWidth) << setfill(seperator) << i;
            cout << left << setw(nameWidth) << setfill(seperator) << printMe[i].getName();
            cout << left << setw(genderWidth) << setfill(seperator) << printMe[i].getGender();
            cout << left << setw(nationalitWidth) << setfill(seperator) << printMe[i].getNationality();
            cout << left << setw(birthYearWidth) << setfill(seperator) << printMe[i].getByear();
            if(printMe[i].getDyear() != 0)
            {
                cout << left << setw(deathYearWidth) << setfill(seperator) << printMe[i].getDyear() << endl;
            }
            else
            {
                cout << left << setw(birthYearWidth) << setfill(seperator) << "-" << endl;
            }

        }
        cout << endl;
    }
    else
    {
        cout << outMessage << endl << endl;
    }
}

void userInterface::printComputers(vector<Computer> printMe, string inMessage, string outMessage)
{
    const char seperator = ' ';
    const int indexWidth = 6;
    const int nameWidth  = 30;
    const int yearWidth = 10;
    const int typeWidth = 35;
    const int builtWidth = 10;

    if(!printMe.empty())
    {
        cout << inMessage << endl;
        cout << left << setw(indexWidth) << setfill(seperator) << "Index";
        cout << left << setw(nameWidth) << setfill(seperator) << "Name";
        cout << left << setw(yearWidth) << setfill(seperator) << "Year";
        cout << left << setw(typeWidth) << setfill(seperator) << "Type";
        cout << left << setw(builtWidth) << setfill(seperator) << "Built" << endl;
        cout << left << setfill('-') << setw(90) << "-" << endl;

        for(unsigned int i = 0; i < printMe.size(); i++)
        {
            cout << left << setw(indexWidth) << setfill(seperator) << i;
            cout << left << setw(nameWidth) << setfill(seperator) << printMe[i].getName();
            cout << left << setw(yearWidth) << setfill(seperator) << printMe[i].getYear();
            cout << left << setw(typeWidth) << setfill(seperator) << printMe[i].getType();
            if(printMe[i].getBuilt())
            {
                cout << left << setw(builtWidth) << setfill(seperator) << "Yes" << endl;
            }
            else
            {
                cout << left << setw(builtWidth) << setfill(seperator) << "No" << endl;
            }
        }

        cout << endl;
    }
    else
    {
        cout << outMessage << endl << endl;
    }
}

void userInterface::readPerson()
{
    string name, gender, nationality, byear, dyear, input;
    cout << "Name: ";
    cin >> ws;
    getline(cin, name);
    cout << "Gender: ";
    cin >> gender;
    cout << "Nationality: ";
    cin >> ws;
    getline(cin, nationality);
    cout << "Year of birth: ";
    cin >> byear;
    cout << "Note: If the person is still alive, please press 0" << endl;
    cout << "Year of death: ";
    cin >> dyear;
    cout << endl;

    if(service.validateNewPerson(name, gender, nationality, byear, dyear))
    {
        service.newPerson(name, gender, nationality, byear, dyear);
    }
    else
    {
        cout << "Invalid input!" << endl;
        cout << "input 'c' to cancel or any character to continue: ";

        if((input != "c") && (input != "C"))
        {
            cin >> input;
            readPerson();
        }
    }
}

void userInterface::readComputer()
{
    string name, year, type, built, input;
    cout << "Name: ";
    cin >> ws;
    getline(cin, name);
    cout << "Year: ";
    cin >> year;
    cout << "Type: ";
    cin >> ws;
    getline(cin, type);
    cout << "Built (Y/N): ";
    cin >> built;

    if(service.validateNewComputer(name, year, type, built))
    {
        service.newComputer(name, year, type, built);
    }
    else
    {
        cout << "Invalid input!" << endl;
        cout << "input 'c' to cancel or any character to continue: ";

        if((input != "c") && (input != "C"))
        {
            cin >> input;
            readComputer();
        }
    }
}

int userInterface::getCorrectInt(int max)
{
    int input;
    cin >> input;

    while(cin.fail() || (input > max) || (input < 1))
    {
        cout << "Invalid input, try again!" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> input;
    }

    return input;
}

template <typename T>
T userInterface::chooseWhich(vector<T> delItem, string s1, string s2, string s3)
{
    T item;
    item.setID(-1);
    size_t itemSize = delItem.size();

    if(itemSize == 0)
    {
        cout << s1;
    }
    else if(itemSize == 1)
    {
        T theItem = delItem[0];
        cout << s2;
        cout << theItem.getName();
        string answer;
        cin >> answer;

        if(answer == "y" || answer == "Y")
        {
            item = theItem;
        }
    }
    else
    {
        cout << s3 << endl;

        for(unsigned int i = 0; i < itemSize; i++)
        {
            cout << i+1 << delItem[i].getName() << endl;;
        }

        int input = getCorrectInt(static_cast<int>(itemSize));
        input--;
        item = delItem[input];
    }

    return item;
}

void userInterface::deletePerson()
{
    cout << "Delete the person with the following name:" << endl;
    cout << "Input: ";
    string deleteString;
    cin >> ws;
    getline(cin, deleteString);
    vector<Person> delPerson = service.searchPersons(deleteString, 1);
    Person person = chooseWhich(delPerson,"No such Person!",
                          "Do you want to delete the following person from the database? (Y/N) ",
                          "which of the following persons do you want to delete");
    int personID = person.getID();

    if(personID != -1)
    {
        if(service.deletePerson(personID))
        {
            cout << "********" << endl;
        }
    }
}

void userInterface::deleteComputer()
{
    cout << "Delete the computer with the following name:" << endl;
    cout << "Input: ";
    string deleteString;
    cin >> ws;
    getline(cin, deleteString);
    vector<Computer> delComputer = service.searchComputers(deleteString, 1);
    Computer computer = chooseWhich(delComputer, "No such Computer!",
                              "Do you want to delete the following computer from the database? (Y/N) ",
                              "which of the following computers do you want to delete");
    int computerID = computer.getID();

    if(computerID != -1)
    {
        if(service.deleteComputer(computerID))
        {
            cout << "******" << endl;
        }
    }
}

void userInterface::linkPersonAndComputer()
{
    cout << "Link person with the following name: " << endl;
    cout << "Input: ";
    string personName, computerName;
    cin >> ws;
    getline(cin, personName);
    vector<Person> linkPerson = service.searchPersons(personName, 1);
    Person person = chooseWhich(linkPerson, "No such person!",
                                "Do you want to link the following person? (Y/N) ",
                                "Which of the following persons do you want to link");

    if(person.getID() != -1)
    {
        cout << "Link computer with the following name: " << endl;
        cout << "Input: ";
        cin >> ws;
        getline(cin, computerName);
        vector<Computer> linkComputer = service.searchComputers(computerName, 1);
        Computer computer = chooseWhich(linkComputer, "No such Computer!",
                                       "Do you want to link the following computer? (Y/N) ",
                                       "Which of the following computers do you want to link");

        if(computer.getID() != -1)
        {
            if(service.link(person.getID(), computer.getID()))
            {
                cout << "Link successful!" << endl;
            }
        }
    }
}
void userInterface::unlinkPersonAndComputer()
{
    cout << "Unlink person with the following name: " << endl;
    cout << "Input: ";
    string personName, computerName;
    cin >> ws;
    getline(cin, personName);
    vector<Person> linkPerson = service.searchPersons(personName, 1);
    Person person = chooseWhich(linkPerson, "No such person!",
                                "Do you want to unlink the following person? (Y/N) ",
                                "Which of the following persons do you want to unlink");

    if(person.getID() != -1)
    {
        cout << "Unink computer with the following name: " << endl;
        cout << "Input: ";
        cin >> ws;
        getline(cin, computerName);
        vector<Computer> linkComputer = service.searchComputers(computerName, 1);
        Computer computer = chooseWhich(linkComputer, "No such Computer!",
                                       "Do you want to unlink the following computer? (Y/N) ",
                                       "Which of the following computers do you want to unlink");

        if(computer.getID() != -1)
        {
            if(service.link(person.getID(), computer.getID()))
            {
                cout << "Unlink successful!" << endl;
            }
        }
    }
}

bool userInterface::doYouWantToQuit()
{
    cout << "Are you sure you want to quit? Y/N: ";
    char input;
    cin >> input;

    if ((input == 'y') || (input == 'Y'))
    {
        cout << " _______    _____     _____    _____    ______   __    __  ______   _            " << endl;
        cout << "/  _____|  / ___ \\   / ___ \\  |  __ \\  |  __  \\  \\ \\  / / |  ____| | |     " << endl;
        cout << "| /   __  | /   \\ | | /   \\ | | |  \\ | | |__| /   \\ \\/ /  | |_     | |      " << endl;
        cout << "| |  |_ | | |   | | | |   | | | |  | | |  __  \\    \\  /   |  _|    |_|         " << endl;
        cout << "| \\___/ | | \\___/ | | \\___/ | | |__/ | | |__|  |   / /    | |____   _         " << endl;
        cout << "\\______/   \\_____/   \\_____/  |_____/  |______/   /_/     |______| |_|        " << endl;
        return true;
    }

    return false;
}
