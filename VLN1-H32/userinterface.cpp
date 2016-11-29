#include "userinterface.h"

userInterface::userInterface()
{

}
void userInterface::run()
{
    bool quit = true;
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
            string searchby;
            cin >> searchby;
            cout << "Enter what you want to search for: " << endl;
            string searchfor;
            cin >> searchfor;
            vector<Person> searchvector;
            searchvector = service.searchList(searchby, searchfor);
            printList(searchvector);
        }
   }while(!quit);
}
void userInterface::printMainMenu()
{
    cout << "Please enter one of the following commands:" << endl;
    cout << "list - This allows you to print our scientist in 4 different orders" << endl;
    cout << "add - This will add a new scientist to our database" << endl;
    cout << "search - This allows you to search for a scientist in our database" << endl;
    cout << "quit - This will quit the program" << endl;
}
void userInterface::printListOptions()
{
    cout << "Please enter one of the 4 following options to sort by:" << endl;
    cout << "byname - This will sort the scientists in alphabetic order" << endl;
    cout << "bygender - This will sort the scientists, showing females first" << endl;
    cout << "bybirth - This will sort the scientists by date of birth" << endl;
    cout << "bydeath - This will sort the scientists by who deceased first" << endl;
}
void userInterface::printSearchOptions()
{
    cout << "Please enter one of the following options to search by:" << endl;
    cout << "name - This will sort the scientists in alphabetic order" << endl;
    cout << "gender - This will sort the scientists, showing females first" << endl;
    cout << "birth - This will sort the scientists by date of birth" << endl;
    cout << "death - This will sort the scientists by who deceased first" << endl;
}

void userInterface::readPerson()
{
    string name;
    string gender;
    int byear;
    int dyear;
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
