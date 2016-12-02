#include "userinterface.h"

//numeration for switch case in main menu
enum inputcases { List = '1', Add, Search, Openfile, Quit = 'q'};

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
    do{
        printMainMenu();
        char input;
        cout << "Input: ";
        cin >> input;
        cout << endl;

        switch (input)
        {
        case List:
            vectorFromList();
            break;
        case Add:
            readPerson();
            break;
        case Search:
            vectorFromSearch();
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

void userInterface::printMainMenu()
{
    cout << "Please enter one of the following commands:" << endl;
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << "1 = List      - This allows you to print out scientists in 5 different orders" << endl;
    cout << "2 = Add       - This will add a new scientist to your database" << endl;
    cout << "3 = Search    - This allows you to search for a scientist in your database" << endl;
    cout << "4 = Open File - This allows you to add scientists from a file" << endl;
    cout << "q = quit      - This will quit the program" << endl;
}

void userInterface::printListOptions()
{
    cout << "Please enter one of the 5 following options to sort by:" << endl;
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << "1 = Name         - This will sort the scientists in alphabetic order" << endl;
    cout << "2 = Gender       - This will sort the scientists, showing females first" << endl;
    cout << "3 = Nationality  - This will sort the scientists by their nationality" << endl;
    cout << "4 = Birthyear    - This will sort the scientists by date of birth" << endl;
    cout << "5 = Deathyear    - This will sort the scientists by who deceased first" << endl;
    cout << "Input: ";
}

void userInterface::printSearchOptions()
{
    cout << "Please enter one of the following options to search by:" << endl;
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << "1 = Name          - This will list all scientists with a specific name" << endl;
    cout << "2 = Gender        - This will list all scientists with specific gender (male / female)" << endl;
    cout << "3 = Nationality   - This will list all scientists with a specific nationality" << endl;
    cout << "4 = Year of birth - This will list all scientists with a specific birth year" << endl;
    cout << "5 = Year of death - This will list all scientists with a specific death year" << endl;
    cout << "Input: ";
}

void userInterface::printSearchCommands(int input)
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

void userInterface::vectorFromList()
{
    printListOptions();
    int input;
    cin >> input;

    while(cin.fail() || (input > 5) || (input < 1))
    {
        cout << "Invalid input, try again:" << endl;
        cin.clear();
        cin.ignore('\n');
        cin >> input;
    }

    printList(service.sortList(input));
}

void userInterface::vectorFromSearch()
{
    printSearchOptions();
    int searchBy;
    string searchFor;
    cin >> searchBy;

    while(cin.fail() || (searchBy > 5) || (searchBy < 1))
    {
        cout << "Invalid input, try again:" << endl;
        cin.clear();
        cin.ignore('\n');
        cin >> searchBy;
    }

    printSearchCommands(searchBy);
    cin >> ws;
    getline(cin, searchFor);
    cout << endl;
    printSearch(service.searchList(searchFor, searchBy));
}

void userInterface::printList(vector<Person> printme)
{
    if(!checkIfVectorIsEmpty(printme))
    {
        cout << "Here is your list sorted:" << endl;

        for(unsigned int i = 0; i < printme.size(); i++)
        {
            cout << printme[i] << endl;
        }
        cout << endl;
    }
    else
    {
        cout << "Your database is empty! Please add database from \"Open file\" in Main Menu" << endl << endl;
    }
}

void userInterface::printSearch(vector<Person> printme )
{
    if(!checkIfVectorIsEmpty(printme))
    {
        for(unsigned int i = 0; i < printme.size(); i++)
        {
            cout << printme[i] << endl;
        }
        cout << endl;
    }
    else
    {
        cout << "No match!" << endl;
    }
}

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

void userInterface::readPerson()
{
    string name, gender, nationality, byear, dyear;
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
        cout << "Invalid input, try again!" << endl;
        readPerson();
    }
}

bool userInterface::doYouWantToQuit()
{
    cout << "Are you sure you want to quit? Y/N: ";
    char answer;
    cin >> answer;

    if (answer == 'y' || answer == 'Y')
    {
        doYouWantToSave();
        return true;
    }
    return false;
}

void userInterface::doYouWantToSave()
{
    cout << "Do you want to save the current list before quitting ? Y/N: ";
    char answer;
    cin >> answer;

    if (answer == 'y' || answer == 'Y')
    {
        savefile();
    }
}

void userInterface::savefile()
{
    cout << "Write the name of the file you want to save" << endl;
    string fileName;
    cin >> fileName;
    service.saveData(fileName);
}

bool userInterface::checkIfVectorIsEmpty(const vector<Person> amIEmpty)
{
    if(amIEmpty.empty())
    {
       return true;
    }

    return false;
}

bool userInterface::doYouWantToContinue()
{
    bool quit;
    cout << "Do you want to continue? (Y/N) ";
    char answer;
    cin >> answer;

    if(answer == 'N' || answer == 'n')
    {
        quit = true;
    }
    else
    {
        quit = false;

    }
    return quit;

}

