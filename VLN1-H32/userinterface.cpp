#include "userinterface.h"

//numeration for switch case in main menu
enum inputcases { Display_Scientis = 1, Display_Computer, Display_Linked_Computers_and_Scientists, Add_Scientis, Add_Computer, Delete_Scientist, Delete_Computer, Search_Scientist, Search_Computer, Update_Scientist, Update_Computer, Link_Scientist_and_Computer, Unlink_Scientist_and_Computer, Quit};

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
        input = getCorrectInt(14);
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
        case Update_Scientist:
            updatePerson();
            break;
        case Update_Computer:
            updateComputer();
            break;
        case Link_Scientist_and_Computer:
            linkPersonAndComputer();
            break;
        case Unlink_Scientist_and_Computer:
            unlinkPersonAndComputer();
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
    cout << "3 = Display linked C&S  - Displays linked Computers and Scientists in the selected order" << endl;
    cout << "4 = Add Scientist       - Adds scientist to your database" << endl;
    cout << "5 = Add Computer        - Adds computer to your database" << endl;
    cout << "6 = Delete Scientist    - Deletes scientist from you database" << endl;
    cout << "7 = Delete Computer     - Deletes computer from you database" << endl;
    cout << "8 = Search Scientist    - Search for a scientist in your database" << endl;
    cout << "9 = Search Computer     - Search for a computer in your database" << endl;
    cout << "10 = Update Scientist   - Update scientist in your database" << endl;
    cout << "11 = Update Computer    - Update computer in your database" << endl;
    cout << "12 = Link               - Link Scientist and Computer" << endl;
    cout << "13 = Unlink             - Unlink Scientist and Computer" << endl;
    cout << "14 = quit               - Quit the program" << endl;
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

void userInterface::printUpdatePersonOptions()
{
    cout << "Please enter what you want to change:" << endl;
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << "1 = Name          - Update the Name of the scientist" << endl;
    cout << "2 = Gender        - Update the Gender of the scientist" << endl;
    cout << "3 = Nationality   - Update the Nationality of the scientist" << endl;
    cout << "4 = Year of birth - Update the Year of birth of the scientist" << endl;
    cout << "5 = Year of death - Update the Year of Death of the scientist" << endl;
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << "Input: ";
}

void userInterface::printUpdateComputerOptions()
{
    cout << "Please enter what you want to change:" << endl;
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << "1 = Name           - Update the Name of the computer" << endl;
    cout << "2 = Year           - Update the Year the computer was designed" << endl;
    cout << "3 = Type           - Update the Type of the computer" << endl;
    cout << "4 = Built          - Update ..?" << endl;
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << "Input: ";
}

void userInterface::printSearchComputersOptions()
{
    cout << "Please enter one of the following optins to search by" << endl;
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
    else if((input == 4) || (input == 5))
    {
        cout << "Do you want to search for one year or a range of year? (1/2): " << endl;
        cout << "Year of birth: ";
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
        cout << "Do you want to search for one year or a range of years? (1/2) " << endl;
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
    int inputNameOrComputer = getCorrectInt(2);
    vector<vector<string>> printMe;

    if(inputNameOrComputer == 1)
    {
       printMe = service.getRelation("Person");
       for(unsigned int i = 0; i < printMe.size(); i++)
       {
           cout << printMe[i][0] << " ";
           cout << "is linked to the following computer(s)";
           for(unsigned int k = 1; k < printMe[i].size(); k++)
           {
               cout << ": " << printMe[i][k] << " ";
           }
           cout <<endl;
       }
       cout << endl;
       cout << left << setfill('-') << setw(80) << "-" << endl;
       cout << endl;
    }
    else
    {
       printMe = service.getRelation("Computer");

       for(unsigned int i = 0; i < printMe.size(); i++)
       {
           cout << printMe[i][0] << " ";
           cout << "is linked to the following scientist(s)";
           for(unsigned int k = 1; k < printMe[i].size(); k++)
           {
               cout << ": " << printMe[i][k] << " ";
           }
           cout << endl;
       }
       cout << endl;
       cout << left << setfill('-') << setw(80) << "-" << endl;
       cout << endl;
    }

}

void userInterface::printPersonsFromSearch()
{
    vector<Person> printMe;
    printSearchPersonsOptions();
    int searchBy = getCorrectInt(5);

    if((searchBy == 4) || (searchBy ==5))
    {
        int first;
        int second = 0;
        int oneOrRange = getCorrectInt(2);

        if(oneOrRange == 1)
        {
            cout << "Enter the year you want to search for: " << endl;
            cout << "Year: ";
            cin >> first;
        }

        else
        {
            cout << "Enter the first year: " << endl;
            cout << "Year: " ;
            cin >> first;
            cout << "Enter the second year: " << endl;
            cout << "Year: " ;
            cin >> second;
        }

        printMe = service.searchPersonYears(first, second);
    }
    else
    {
        string searchFor;
        printSearchPersonsCommands(searchBy);
        cin >> ws;
        getline(cin, searchFor);
        cout << endl;
        printMe = service.searchPersons(searchFor, searchBy);
    }

    printPersons(printMe, "Search results: ", "No match!");
}

void userInterface::printComputerFromSearch()
{
    vector<Computer> printMe;
    printSearchComputersOptions();
    int searchBy = getCorrectInt(4);

    if(searchBy == 2)
    {
        int first;
        int second = 0;
        int oneOrRange = getCorrectInt(2);

        if(oneOrRange == 1)
        {
            cout << "Enter the year you want to search for: " << endl;
            cout << "Year: " ;
            cin >> first;
        }
        else
        {
            cout << "Enter the first year: " << endl;
            cout << "Year: " ;
            cin >> first;
            cout << "Enter the second year: " << endl;
            cout << "Year: " ;
            cin >> second;
        }

        printMe = service.searchComputerYears(first, second);
    }
    else
    {
        string searchFor;
        printSearchComputersCommands(searchBy);
        cin >> ws;
        getline(cin, searchFor);
        cout << endl;
        printMe = service.searchComputers(searchFor, searchBy);
    }

    printComputers(printMe, "Search results: ", "No match!");
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
            cout << left << setw(indexWidth) << setfill(seperator) << i+1;
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
            cout << left << setw(indexWidth) << setfill(seperator) << i+1;
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
        cin >> input;

        if((input == "c") || (input == "C")){}
        else
        {
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
        cin >> input;

        if((input == "c") || (input == "C")){}
        else
        {
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
T userInterface::chooseWhich(vector<T> vec, string action, string type)
{
    T item;
    item.setID(-1);
    size_t vecSize = vec.size();

    if(vecSize == 0)
    {
        cout << "No such " << type << "!" << endl;;
    }
    else if(vecSize == 1)
    {
        T theItem = vec[0];
        cout << "Do you want to " << action << " the following " << type << " from the database? (Y/N): " ;
        cout << theItem.getName() << ": ";
        string answer;
        cin >> answer;

        if(answer == "y" || answer == "Y")
        {
            item = theItem;
        }
    }
    else
    {
        cout << "Which of the following " << type << "s do you want to " << action << "?" << endl;

        for(unsigned int i = 0; i < vecSize; i++)
        {
            cout << i+1 <<": " << vec[i].getName() << endl;
        }

        cout << vecSize+1 <<": " << "Cancel" << endl;

        int vecSizeInt = static_cast<int>(vecSize + 1);
        int input = getCorrectInt(vecSizeInt);

        if(input < vecSizeInt)
        {
            input--;
            item = vec[input];
        }
    }

    return item;
}

Person userInterface::getRightPerson(string action)
{
    cout << action << " the scientist" << " with the following name" << endl;
    cout << "Input: ";
    string input;
    cin >> ws;
    getline(cin, input);
    vector<Person> vec = service.searchPersons(input, 1);
    return chooseWhich(vec, action, "scientist");
}

Computer userInterface::getRightComputer(string action)
{
    cout << action << " the computer" << " with the following name" << endl;
    cout << "Input: ";
    string input;
    cin >> ws;
    getline(cin, input);
    vector<Computer> vec = service.searchComputers(input, 1);
    return chooseWhich(vec, action, "computer");
}

void userInterface::deletePerson()
{
    Person person = getRightPerson("delete");
    int personID = person.getID();

    if(personID != -1)
    {
        if(service.deletePerson(personID))
        {
            cout << "Delete successful!" << endl;
        }
    }
}

void userInterface::deleteComputer()
{
    Computer computer = getRightComputer("delete");
    int computerID = computer.getID();

    if(computerID != -1)
    {
        if(service.deleteComputer(computerID))
        {
            cout << "Delete successful!" << endl;
        }
    }
}

void userInterface::updatePerson()
{    
    Person person = getRightPerson("Update");
    int personID = person.getID();

    if(personID != -1)
    {
        printUpdatePersonOptions();
        int input = getCorrectInt(5);

        cout << "Input the change: " ;
        cin >> ws;
        string changeString;
        getline(cin, changeString);

        if(service.callUpdatePerson(personID, input, changeString))
        {
            cout << "Update successful!" << endl;
        }
    }
}

void userInterface::updateComputer()
{
    Computer computer = getRightComputer("Update");
    int computerID = computer.getID();

    if(computerID != -1)
    {
        printUpdateComputerOptions();
        int input = getCorrectInt(4);

        cout << "Input the change: " ;
        cin >> ws;
        string changeString;
        getline(cin, changeString);

        if(service.callUpdateComputer(computerID, input, changeString))
        {
            cout << "Update successful!" << endl;
        }
    }
}

void userInterface::linkPersonAndComputer()
{    
    Person person = getRightPerson("Link");

    if(person.getID() != -1)
    {
        Computer computer = getRightComputer("Link");

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
    Person person = getRightPerson("Unlink");

    if(person.getID() != -1)
    {
        Computer computer = getRightComputer("Unlink");

        if(computer.getID() != -1)
        {
            if(service.unLink(person.getID(), computer.getID()))
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
