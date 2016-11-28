#include "userinterface.h"

userInterface::userInterface()
{

}
void userInterface::run()
{
    cout << "Please enter one of the following commands" << endl;
    cout << "add - This will add a new scientist to our database" << endl;
    cout << "list - This will print on your screen all the scientist in our database" << endl;
    cout << "byname - This will sort the scientists in alphabetic order" << endl;
    cout << "bygender - This will sort the scientists, showing females first" << endl;
    cout << "bybirth - This will sort the scientists by date of birth" << endl;
    cout << "bydeath - This will sort the scientists by who deceased first" << endl;
    cout << "search - This allows you to search for a scientist in our database" << endl;
}
Person userInterface::readPerson()
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

    Person newperson(name, gender, byear, dyear);
    return newperson; //eftir að útfæra rétt, þarf að henda í add fall í servicelayer sem addar í vectorinn í datalayer....
}

