#include "userinterface.h"

//numeration for switch case in main menu
enum inputcases { Display_Scientis = '1', Display_Computer, Add_Scientis, Add_Computer, Delete_Scientist, Delete_Computer, Search_Scientist, Search_Computer, Link_Scientist_and_Computer, Quit = 'q'};

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
    cout << "9 = Link              - Link Scientist and Computer" << endl;
    cout << "q = quit              - Quit the program" << endl;
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << "Input: ";
}

/**
 * @brief userInterface::printDisplayscientistsOptions
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
    cout << setfill('-') << setw(80) << "-" << endl;
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
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << "Input: ";
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
    cout << setfill('-') << setw(80) << "-" << endl;
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
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << "Input: ";
}

/**
 * @brief userInterface::printSearchscientistsCommands
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
 * @brief userInterface::printScientistsFromDisplay
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

    vector<Person> sorted = service.sortPersons(input);
    printPersons(sorted, "Here is your list sorted: " , "Your database is empty! Please add database from \"Open file\" in Main Menu");
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
    vector<Computer> sorted = service.sortComputers(computeroption);
    printComputers(sorted, "Here is your list sorted: " , "Your database is empty! Please add database from \"Open file\" in Main Menu");
}

/**
 * @brief userInterface::printScientistFromSearch
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
    printPersons(service.searchPersons(searchFor, searchBy), "Search results: ", "No match!");
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
    printComputers(service.searchComputers(searchFor, searchBy), "Search results: ", "No match!");
}

/**
 * @brief userInterface::printList
 * @param printMe
 * @param inMessage
 * @param outMessage
 */
void userInterface::printPersons(vector<Person> printMe, string inMessage, string outMessage)
{
    const char seperator = ' ';
    const int nameWidth  = 30;
    const int genderWidth = 10;
    const int nationalitWidth = 25;
    const int birthYearWidth = 12;
    const int deathYearWidth = 12;
    if(!printMe.empty())
    {
        cout << inMessage << endl;
        cout << left << setw(nameWidth) << setfill(seperator) << "Name";
        cout << left << setw(genderWidth) << setfill(seperator) << "Gender";
        cout << left << setw(nationalitWidth) << setfill(seperator) << "Nationality";
        cout << left << setw(birthYearWidth) << setfill(seperator) << "Birth Year";
        cout << left << setw(deathYearWidth) << setfill(seperator) << "Death Year" << endl;
        cout << left << setfill('-') << setw(90) << "-" << endl;

        for(unsigned int i = 0; i < printMe.size(); i++)
        {
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
    const int nameWidth  = 30;
    const int yearWidth = 10;
    const int typeWidth = 30;
    const int builtWidth = 10;

    if(!printMe.empty())
    {
        cout << inMessage << endl;
        cout << left << setw(nameWidth) << setfill(seperator) << "Name";
        cout << left << setw(yearWidth) << setfill(seperator) << "Year";
        cout << left << setw(typeWidth) << setfill(seperator) << "Type";
        cout << left << setw(builtWidth) << setfill(seperator) << "Built" << endl;
        cout << left << setfill('-') << setw(90) << "-" << endl;

        for(unsigned int i = 0; i < printMe.size(); i++)
        {
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
/**
 * @brief userInterface::readList
 */
/*void userInterface::readList()
{
    cout << "Enter the name of your file: ";
    string fileName;
    cin >> fileName;

    try
    {
        service.createList(fileName);
    }catch(string fail) { cout << fail << endl; }
}*/

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
    string name, year, type, built;
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
    service.newComputer(name, year, type, built);
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
 * @brief userInterface::deletePerson
 */
void userInterface::deletePerson()
{
    cout << "Delete the persoon with the following name:" << endl;
    cout << "Input: ";
    string deleteString;
    cin >> ws;
    getline(cin, deleteString);
    vector<Person> delperson = service.searchPersons(deleteString, 1);
    if(delperson.size() == 0)
    {
        cout << "No such Person!";
    }
    else if(delperson.size() == 1)
    {

        cout << "Do you want to delete the following person from the database? (Y/N) ";
        cout << delperson[0].getName();
        string answer;
        cin >> answer;
        if(answer == "y" || answer == "Y")
        {
            if(service.deletePerson(delperson[0].getID()))
            {
                cout << "Delete successful!" << endl;
            }
            else
            {
                cout << "Delete unsuccessful!" << endl;
            }
        }
    }
    else
    {
        cout << "which of the following person do you want to delete";
        for(unsigned int i = 0; i < delperson.size(); i++)
        {
            cout << i+1 << delperson[i];
        }
        int input;
        cin >> input;
        input--;
        if(service.deletePerson(delperson[input].getID()))
        {
            cout << "Delete successful!" << endl;
        }
        else
        {
            cout << "Delete unsuccessful!" << endl;
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
    vector<Computer> delcomputer = service.searchComputers(deleteString, 1);
    if(delcomputer.size() == 0)
    {
        cout << "No such Computer!";
    }
    else if(delcomputer.size() == 1)
    {

        cout << "Do you want to delete the following computer from the database? (Y/N) ";
        cout << delcomputer[0].getName();
        string answer;
        cin >> answer;
        if(answer == "y" || answer == "Y")
        {
            Computer computer = delcomputer[0];
            if(service.deleteComputer(computer.getID()))
            {
                cout << "Delete successful!" << endl;
            }
            else
            {
                cout << "Delete unsuccessful!" << endl;
            }
        }
    }
    else
    {
        cout << "which of the following computers do you want to delete" << endl;
        for(unsigned int i = 0; i < delcomputer.size(); i++)
        {
            cout << i+1 << delcomputer[i].getName();
        }
        int input;
        cin >> input;
        input--;
        Computer computer = delcomputer[input];
        if(service.deleteComputer(computer.getID()))
        {
            cout << "Delete successful!" << endl;
        }
        else
        {
            cout << "Delete unsuccessful!" << endl;
        }

    }
}
void userInterface::linkPersonAndComputer()
{
    cout << "Link person with the following name: " << endl;
    cout << "Input: ";
    string personname;
    Person person;
    person.setID(-1);
    Computer computer;
    cin >> ws;
    getline(cin, personname);
    vector<Person> linkperson = service.searchPersons(personname, 1);
    if(linkperson.size() == 0)
    {
        cout << "No such person!" << endl;
    }
    else if(linkperson.size() == 1)
    {

        cout << "Do you want to link the following person? (Y/N) ";
        cout << linkperson[0].getName() << endl;
        string answer;
        cin >> answer;
        if(answer == "y" || answer == "Y")
        {
            person = linkperson[0];
        }
    }
    else
    {
        cout << "which of the following person do you want to link" << endl;
        for(unsigned int i = 0; i < linkperson.size(); i++)
        {
            cout << i+1 << " " << linkperson[i].getName() << endl;

        }
        cout << "Input person number: ";
        int input;
        cin >> input;
        input--;
        person = linkperson[input];
    }
    if(person.getID() != -1)
    {
        cout << "Link computer with the following name: ";
        cout << "Input: ";
        string computername;
        cin >> ws;
        getline(cin, computername);
        vector<Computer> linkcomputer = service.searchComputers(computername, 1);
        if(linkcomputer.size() == 0)
        {
            cout << "No such Computer!" << endl;
        }
        else if(linkcomputer.size() == 1)
        {

            cout << "Do you want to link the following computer? (Y/N) " << endl;
            cout << linkcomputer[0].getName() << endl;
            string answer;
            cin >> answer;
            cout << "Answer: ";
            if(answer == "y" || answer == "Y")
            {
                computer = linkcomputer[0];
            }
        }
        else
        {
            cout << "which of the following computers do you want to link" << endl;
            for(unsigned int i = 0; i < linkcomputer.size(); i++)
            {
                cout << i+1 << " " << linkcomputer[i].getName() << endl;
            }
            cout << "Input computer number: ";
            int input;
            cin >> input;
            input--;
            computer = linkcomputer[input];
        }
        if(service.link(person.getID(), computer.getID()))
        {
            cout << "Link successful!" << endl;
        }
        else
        {
            cout << "Link unsuccessful!" << endl;
        }
    }

}
