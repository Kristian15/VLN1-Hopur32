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
            printListOptions();
            string sortby;
            cin >> sortby;
            vector<Person> sortbyvector;
            sortbyvector = service.sortList(sortby);
            printList(sortbyvector);
        }

        if(input == "add")
        {
            readPerson();
        }

        if(input == "search")
        {
            printSearchOptions();

            string searchby, searchfor;
            cin >> searchby;
            cout << "Enter what you want to search for: " << endl;
            cin >> searchfor;

            vector<Person> searchvector;
            searchvector = service.searchList(searchby, searchfor);
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
                    cout << "Write the name of the file you want to save in" << endl;
                    string fileName;
                    cin >> fileName;
                    service.saveData(fileName);
                }
                quit = true;
            } 
        }
   }while(!quit);
}

void userInterface::printMainMenu()
{
    cout << "Please enter one of the following commands:" << endl;
    cout << "===========================================" << endl;
    cout << "list    - This allows you to print onto you screen our scientists in 4 different orders" << endl;
    cout << "add     - This will add a new scientist to our database" << endl;
    cout << "search  - This allows you to search for a scientist in our database" << endl;
    cout << "addlist - This allows you to add scientists from a file" << endl;
    cout << "quit    - This will quit the program" << endl;
}

void userInterface::printListOptions()
{
    cout << "Please enter one of the 4 following options to sort by:" << endl;
    cout << "=======================================================" << endl;
    cout << "byname   - This will sort the scientists in alphabetic order" << endl;
    cout << "bygender - This will sort the scientists, showing females first" << endl;
    cout << "bybirth  - This will sort the scientists by date of birth" << endl;
    cout << "bydeath  - This will sort the scientists by who deceased first" << endl;
}

void userInterface::printSearchOptions()
{
    cout << "Please enter one of the following options to search by:" << endl;
    cout << "=======================================================" << endl;
    cout << "name   - This will sort the scientists in alphabetic order" << endl;
    cout << "gender - This will sort the scientists, showing females first" << endl;
    cout << "birth  - This will sort the scientists by date of birth" << endl;
    cout << "death  - This will sort the scientists by who deceased first" << endl;
}

void userInterface::printList(vector<Person> printme)
{
    for(unsigned int i = 0; i < printme.size(); i++)
    {
        cout << printme[i].getName() << endl;
        cout << printme[i].getGender() << endl;
        cout << printme[i].getByear() << endl;
        cout << printme[i].getDyear() << endl;
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
    string name, gender;
    int byear, dyear;

    cout << "Name: ";
    cin >> name;
    cout << "Gender: ";
    cin >> gender;
    cout << "Date of birth: ";
    cin >> byear;
    cout << "Time of death: ";
    cin >> dyear;

    service.newPerson(name, gender, byear, dyear);
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
