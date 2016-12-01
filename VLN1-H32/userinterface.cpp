#include "userinterface.h"

void userInterface::run()
{
    bool quit = false;

    do{
        printMainMenu();
        char input;
        cin >> input;

        switch (input)
        {
        case '1': // list
            makeVectorFromList();
            break;
        case '2': // add
            readPerson();
            break;
        case '3': // search
            makeVectorFromSearch();
            break;
        case '4': // open file
            readList();
            break;
        case 'q': // quit
            quit = doYouWantToQuit();
            break;
        default:
            cout << endl << "Invalid Input!" << endl << endl;
            break;
        }
        /*bool validinput = validateInputInRun(input);
        if(input == "list")
        {
            vector<Person> sortByVector;
            makeVectorFromList(sortByVector);
            printList(sortByVector);
        }
        if(input == "add")
        {
            readPerson();
        }

        if(input == "search")
        {           

            vector<Person> searchVector;
            makeVectorFromSearch(searchVector);            
            printSearch(searchVector);
        }

        if(input == "addlist")
        {
             readList();
        }
        if(input == "quit")
        {
            if (doYouWantToQuit())
            {
                if (doYouWantToSave())
                {
                    savefile();
                }
                quit = true;
            } 
        }
        if(validinput)
        {
            if(input == "search" || input == "list")
            {
                quit = DoYouWantToContinue();
            }
        }*/
   }while(!quit);
}

void userInterface::printMainMenu()
{
    cout << "Please enter one of the following commands:" << endl;
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << "1 = List      - This allows you to print onto you screen our scientists in 4 different orders" << endl;
    cout << "2 = Add       - This will add a new scientist to our database" << endl;
    cout << "3 = Search    - This allows you to search for a scientist in our database" << endl;
    cout << "4 = Open File - This allows you to add scientists from a file" << endl;
    cout << "q = quit      - This will quit the program" << endl;
}

bool userInterface::validateInputInRun(string input)
{
    if(input == "list" || input == "add" || input == "search" || input == "addlist" || input == "quit")
    {
        return true;
    }
    else
    {
        cout << "Invalid input!" << endl;
        return false;
    }
}
void userInterface::printListOptions()
{
    cout << "Please enter one of the 5 following options to sort by:" << endl;
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << "name   - This will sort the scientists in alphabetic order" << endl;
    cout << "gender - This will sort the scientists, showing females first" << endl;
    cout << "nationality - This will sort the scientists by their nationality" << endl;
    cout << "birth  - This will sort the scientists by date of birth" << endl;
    cout << "death  - This will sort the scientists by who deceased first" << endl;
}

void userInterface::printSearchOptions()
{
    cout << "Please enter one of the following options to search for:" << endl;
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << "name   - This will list all scientists with a specific name" << endl;
    cout << "gender - This will list all scientists with a specific gender (male / female)" << endl;
    cout << "nationality - This will list all scientists by their nationality" << endl;
    cout << "birth  - This will list all scientists with a specific birth year" << endl;
    cout << "death  - This will list all scientists with a specific death year" << endl;
}
void userInterface::makeVectorFromList()
{
    printListOptions();
    string sortby;
    cin >> sortby;
    // **** todo switch case ****

    printList(service.sortList(sortby));
}

void userInterface::makeVectorFromSearch()
{

    //printSearch(searchVector);
    bool validinput;
    string searchby, searchfor;

    // **** todo switch case ****
    do
    {
        printSearchOptions();
        cin >> searchby;

        if(searchby == "name")
        {
            cout << "Enter the name you want to search for: " << endl;
            validinput = true;
        }
        else if(searchby == "gender")
        {
            cout << "Enter either \"male\" or \"female\": " << endl;
            validinput = true;
        }
        else if(searchby == "nationality")
        {
            cout << "Enter nationality: " << endl;
            validinput = true;
        }
        else if(searchby == "birth")
        {
            cout << "Enter the year of birth you want to search for: " << endl;
            validinput = true;
        }
        else if(searchby == "death")
        {
            cout << "Enter the year of death you want to search for: " << endl;
            validinput = true;
        }
        else
        {
            cout << "invalid input!";
            validinput = false;
            cout << endl;
        }
    }while(!validinput);

    cin >> ws;
    getline(cin, searchfor);
    printList(service.searchList(searchfor, searchby));
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
        cout << "Your database is empty!" << endl;
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
    string filename;
    cin >> filename;
    service.createList(filename);
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
    cout << "Are you sure you want to quit? Y/N:" << endl;
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
    cout << "Do you want to save the current list before quitting ? Y/N" << endl;
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
bool userInterface::DoYouWantToContinue()
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

