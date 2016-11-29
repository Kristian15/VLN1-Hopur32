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
            //service.sortList(sortby);
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
            string searchfor;
            cin >> searchfor;

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

    //Person newperson(name, gender, byear, dyear);
    //return newperson; //eftir að útfæra rétt, þarf að henda í add fall í servicelayer sem addar í vectorinn í datalayer....
}

