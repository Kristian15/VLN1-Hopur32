#include "userinterface.h"

userInterface::userInterface() {}

void userInterface::run()
{
    bool quit = false;

    do{
        printMainMenu();
        string input;
        cin >> input;
        if(input == "list")
        {
            vector<Person> sortbyvector;
            makeVectorFromList(sortbyvector);
            printList(sortbyvector);
        }

        if(input == "add")
        {
            readPerson();
        }

        if(input == "search")
        {           
            vector<Person> searchvector;
            makeVectorFromSearch(searchvector);
            printList(searchvector);
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
   }while(!quit);
}

void userInterface::printMainMenu()
{
    cout << "Please enter one of the following commands:" << endl;
    cout << setfill('-') << setw(80) << "-" << endl;
    cout << "list    - This allows you to print onto you screen our scientists in 4 different orders" << endl;
    cout << "add     - This will add a new scientist to our database" << endl;
    cout << "search  - This allows you to search for a scientist in our database" << endl;
    cout << "addlist - This allows you to add scientists from a file" << endl;
    cout << "quit    - This will quit the program" << endl;
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
void userInterface::makeVectorFromList(vector<Person>& inputvector)
{
    bool validinput;
    do
    {
        printListOptions();
        string sortby;
        cin >> sortby;
        if(sortby == "name" ||
           sortby == "gender" ||
           sortby == "birth" ||
           sortby == "death" ||
           sortby == "nationality")
        {
            cout << "Here is your list sorted by " << sortby << ":" << endl;
            inputvector = service.sortList(sortby);
            validinput = true;
        }
        else
        {
            cout << "invalid input!";
            validinput = false;
            cout << endl;
        }
    }while(!validinput);
}

void userInterface::makeVectorFromSearch(vector<Person>& inputvector)
{
    bool validinput;
    do
    {
        printSearchOptions();
        string searchby, searchfor;
        cin >> searchby;
        if(searchby == "name")
        {
            cout << "Enter the name you want to search for: " << endl;
            cin >> ws;
            getline(cin, searchfor);
            inputvector = service.searchList(searchfor, searchby);
            validinput = true;
        }
        else if(searchby == "gender")
        {
            cout << "Enter either \"male\" or \"female\": " << endl;
            cin >> ws;
            getline(cin, searchfor);
            inputvector = service.searchList(searchfor, searchby);
            validinput = true;
        }
        else if(searchby == "nationality")
        {
            cout << "Enter nationality: " << endl;
            cin >> ws;
            getline(cin, searchfor);
            inputvector = service.searchList(searchfor, searchby);
            validinput = true;
        }
        else if(searchby == "birth")
        {
            cout << "Enter the year of birth you want to search for: " << endl;
            cin >> ws;
            getline(cin, searchfor);
            inputvector = service.searchList(searchfor, searchby);
            validinput = true;
        }
        else if(searchby == "death")
        {
            cout << "Enter the year of death you want to search for: " << endl;
            cin >> ws;
            getline(cin, searchfor);
            inputvector = service.searchList(searchfor, searchby);
            validinput = true;
        }
        else
        {
            cout << "invalid input!";
            validinput = false;
            cout << endl;
        }
        }while(!validinput);

}

void userInterface::printList(vector<Person> printme ) const
{
    for(unsigned int i = 0; i < printme.size(); i++)
    {
        cout << printme[i] << endl;
    }
    cout << endl;
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
    cout << "Date of birth: ";
    cin >> byear;
    cout << "Time of death: " << endl;
    cout << "Note: If the person is still alive, please press 0" << endl;
    cin >> dyear;

    if (dyear == "0")
    {
        service.newPerson(name, gender, nationality, byear);
    }
    else
    {
        service.newPerson(name, gender, nationality, byear, dyear);
    }
}

bool userInterface::doYouWantToQuit()
{
    cout << "Are you sure you want to quit? Y/N:" << endl;
    char answer;
    cin >> answer;

    if (answer == 'y' || answer == 'Y')
    {
        return true;
    }
    return false;
}

bool userInterface::doYouWantToSave()
{
    cout << "Do you want to save the current list before quitting ? Y/N" << endl;
    char answer;
    cin >> answer;

    if (answer == 'y' || answer == 'Y')
    {
        return true;
    }
    return false;
}
void userInterface::savefile()
{
    cout << "Write the name of the file you want to save" << endl;
    string fileName;
    cin >> fileName;
    service.saveData(fileName);
}
