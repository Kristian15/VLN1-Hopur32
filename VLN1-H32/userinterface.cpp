#include "userinterface.h"

//numeration for switch case in main menu
enum inputcases { Display_Scientis = '1', Display_Computer, Add_Scientis, Add_Computer, Delete_Scientist, Delete_Computer, Search_Scientist, Search_Computer, Openfile, Quit = 'q'};

/**
 * @brief userInterface::run
 */
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
    char input;

    do{
        printMainMenu();
        cout << "Input: ";
        cin >> input;
        cout << endl;

        switch (input)
        {
        case Display_Scientis:
            printScientistsFromDisplay();
            break;
        case Display_Computer:
            printComputersFromDisplay();
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
            printScientistFromSearch();
            break;
        case Search_Computer:
            printComputerFromSearch();
            break;
        case Openfile:
            readList();
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

/**
 * @brief userInterface::printMainMenu
 */
void userInterface::printMainMenu()
{
    cout << "Please enter one of the following commands:" << endl;
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << "1 = Display Scientist - Displays Scientists data in the selected order" << endl;
    cout << "2 = Display Computer  - Displays Computer data in the selected order" << endl;
    cout << "3 = Add Scientist     - Adds scientist to your database" << endl;
    cout << "4 = Add Computer      - Adds computer to your database" << endl;
    cout << "5 = Delete Scientist  - Deletes scientist from you database" << endl;
    cout << "6 = Delete Computer   - Deletes computer from you database" << endl;
    cout << "7 = Search Scientist  - Search for a scientist in your database" << endl;
    cout << "8 = Search Computer   - Search for a computer in your database" << endl;
    cout << "9 = Open File         - Adds scientists from a file" << endl;
    cout << "q = quit              - Quit the program" << endl;
}

/**
 * @brief userInterface::printListOptions
 */
void userInterface::printDisplayscientistsOptions()
{
    cout << "Please enter one of the 5 following options to sort by:" << endl;
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << "1 = Name         - Sort the scientists in alphabetic order" << endl;
    cout << "2 = Gender       - Sort the scientists, showing females first" << endl;
    cout << "3 = Nationality  - Sort the scientists by their nationality" << endl;
    cout << "4 = Birthyear    - Sort the scientists by date of birth" << endl;
    cout << "5 = Deathyear    - Sort the scientists by who deceased first" << endl;
    cout << "Input: ";
}

void userInterface::printDisplaycomputerOptions()
{
    cout << "Please enter one of the following options to sort by: " << endl;
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << "1 = Name  - sort the computers by name" << endl;
    cout << "2 = Year  - sort the computer by year designed" << endl;
    cout << "3 = Type  - sort the computer by type" << endl;
    cout << "4 = Built - show computers that were built;" << endl;
}
void userInterface::printSearchscientistsOptions()
{
    cout << "Please enter one of the following options to search by:" << endl;
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << "1 = Name          - Search for scientists with a specific name" << endl;
    cout << "2 = Gender        - Search for scientists with specific gender (male / female)" << endl;
    cout << "3 = Nationality   - Search for scientists with a specific nationality" << endl;
    cout << "4 = Year of birth - Search for scientists with a specific birth year" << endl;
    cout << "5 = Year of death - Search for scientists with a specific death year" << endl;
    cout << "Input: ";
}
void userInterface::printSearchcomputersoptions()
{
    cout << "Please enter one of the following optins to searh by" << endl;
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << "1 = Name    - Search for computers with a specific name" << endl;
    cout << "2 = Year    - Search for computers from a specific year" << endl;
    cout << "3 = Type    - Search for computers of a specific type" << endl;
    cout << "4 = Built   - Search for computers that were built or not (Y / N)" << endl;
}

/**
 * @brief userInterface::printSearchCommands
 * @param input
 */
void userInterface::printSearchscientistsCommands(int input)
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
void userInterface::printSearchcomputersCommands(int input)
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

/**
 * @brief userInterface::printFromDisplay
 */
void userInterface::printScientistsFromDisplay()
{
    printDisplayscientistsOptions();
    int input;
    cin >> input;
    cout << endl;

    while(cin.fail() || (input > 5) || (input < 1))
    {
        cout << "Invalid input, try again:" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> input;
    }

    vector<Person> sorted = service.sortList(input);
    printList(sorted, "Here is your list sorted: " , "Your database is empty! Please add database from \"Open file\" in Main Menu");
    ifYouWantToSave(sorted);
}

void userInterface::printComputersFromDisplay()
{
    printDisplaycomputerOptions();
    int computeroption;
    cin >> computeroption;
    while(cin.fail() || (computeroption > 4) || (computeroption < 1))
    {
        cout << "Invalid input, try again!" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> computeroption;
    }
    cout << "gemmer fall í service til að kalla í";
}

/**
 * @brief userInterface::printFromSearch
 */
void userInterface::printScientistFromSearch()
{
    printSearchscientistsOptions();
    int searchBy;
    string searchFor;
    cin >> searchBy;

    while(cin.fail() || (searchBy > 5) || (searchBy < 1))
    {
        cout << "Invalid input, try again:" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> searchBy;
    }

    printSearchscientistsCommands(searchBy);
    cin >> ws;
    getline(cin, searchFor);
    cout << endl;
    printList(service.searchList(searchFor, searchBy), "Search results: ", "No match!");
}
void userInterface::printComputerFromSearch()
{
    printSearchcomputersoptions();
    int searchBy;
    string searchFor;
    cin >> searchBy;

    while(cin.fail() || (searchBy > 4) || (searchBy < 1))
    {
        cout << "Invalid input, try again:" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> searchBy;
    }

    printSearchcomputersCommands(searchBy);
    cin >> ws;
    getline(cin, searchFor);
    cout << endl;
    //printList(service.searchList(searchFor, searchBy), "Search results: ", "No match!");
}

/**
 * @brief userInterface::printList
 * @param printMe
 * @param inMessage
 * @param outMessage
 */
void userInterface::printList(vector<Person> printMe, string inMessage, string outMessage)
{
    if(!printMe.empty())
    {
        cout << inMessage << endl;

        for(unsigned int i = 0; i < printMe.size(); i++)
        {
            cout << printMe[i] << endl;
        }

        cout << endl;
    }
    else
    {
        cout << outMessage << endl << endl;
    }
}

/**
 * @brief userInterface::readList
 */
void userInterface::readList()
{
    cout << "Enter the name of your file: ";
    string fileName;
    cin >> fileName;

    try
    {
        service.createList(fileName);
    }catch(string fail) { cout << fail << endl; }
}

/**
 * @brief userInterface::readPerson
 */
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
    string name, type, builtstring;
    int year;
    bool built;
    cout << "Name: ";
    cin >> ws;
    getline(cin, name);
    cout << "Year: ";
    cin >> year;
    cout << "Type: ";
    cin >> ws;
    getline(cin, type);
    cout << "Built (Y/N): ";
    cin >> builtstring;
    if(builtstring == "y" || builtstring =="Y")
    {
        built = true;
    }
    else if(builtstring == "n" || builtstring =="N")
    {
        built = false;
    }
    cout << "gemmer service fall til að kalla í";

}

/**
 * @brief userInterface::doYouWantToQuit
 * @return bool
 */
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

/**
 * @brief userInterface::ifYouWantToSave
 * @param saveMe
 */
void userInterface::ifYouWantToSave(vector<Person> saveMe)
{
    cout << "Do you want to save your sorted list? Y/N: ";
    char input;
    cin >> input;

    if ((input == 'y') || (input == 'Y'))
    {
        cout << "Write the name of the file you want to save" << endl;
        string fileName;
        cin >> fileName;
        service.saveData(fileName, saveMe);
    }
}

/**
 * @brief userInterface::deletePerson
 */
void userInterface::deletePerson()
{
    cout << "Delete all scientists by following name" << endl;
    cout << "Input: ";
    string deleteString;
    cin >> ws;
    getline(cin, deleteString);
    service.deletePerson(deleteString);
}

void userInterface::deleteComputer()
{
    cout << "Delete all computers by following name" << endl;
    cout << "Input: ";
    string deletestring;
    cin >> ws;
    getline(cin, deletestring);
    cout << "gemmer fall í service til að kalla í";

}
