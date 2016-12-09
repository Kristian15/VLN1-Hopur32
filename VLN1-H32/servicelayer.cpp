#include "servicelayer.h"

using namespace std;

// **** PRIVATE*****

bool serviceLayer::validateName(string name)
{
    size_t wordLength = name.length();
    unsigned int tmp = 0;

    for (unsigned int i = 0; i < wordLength; i++)
    {
        if (!isdigit(name[i]) && (name != ""))
        {
            tmp ++;
        }
    }

    if ((tmp == wordLength) && (name != ""))
    {
        return true;
    }

    return false;
}

bool serviceLayer::validateGender(string gender)
{
    if ((gender == "male") || (gender == "female"))
    {
        return true;
    }

    return false;
}

bool serviceLayer::validateNationality(string nationality)
{
    size_t wordLength = nationality.length();
    unsigned int tmp = 0;

    for (unsigned int i = 0; i < wordLength; i++)
    {
        char c = nationality[i];

        if ((isspace(c)) || (isalpha(c)))
        {
            tmp ++;
        }
    }

    if (tmp == wordLength)
    {
        return true;
    }

    return false;
}

bool serviceLayer::validateYear(string year)
{
    size_t wordLength = year.length();
    unsigned int tmp = 0;

    for (unsigned int i = 0; i < wordLength; i++)
    {
        if (isdigit(year[i]))
        {
            tmp++;
        }
    }

    time_t now = time(0);
    tm *ltm = localtime(&now);
    int currYear = 1900 + ltm->tm_year; // find current year

    if (tmp == wordLength)
    {
        if ((stoi(year) <= currYear) && (wordLength == 4))
        {
            return true;
        }
    }
    return false;
}

bool serviceLayer::validateBuilt(string& built)
{
    if(built.size() == 1) // check if built is only one character
    {
        built = tolower(built[0]);

        if((built == "y") || (built == "n"))
        {
            return true;
        }
    }

    return false;
}

Person serviceLayer:: getNewPerson(string name, string gender, string nationality, string byear, string dyear)
{
    Person newP;
    int Byear = stoi(byear);
    int Dyear = 0;

    // if there is a death year
    if(dyear != "0")
    {
        Dyear = stoi(dyear);   
    }

    newP = Person(name, gender, nationality, Byear, Dyear);

    return newP;
}

Computer serviceLayer:: getNewComputer(string name, string year, string type, string built)
{
    bool builtBool = false;

    if((built == "y"))
    {
       builtBool = true;
    }

    return Computer(name, stoi(year), type, builtBool);
}

//*****PUBLIC*****

vector<Person> serviceLayer::searchPersons(string findMe, int by)
{
    string col = "Name"; // case 1

    switch (by) {
    case 2:
        col = "Gender";
        break;
    case 3:
        col = "Nationality";
        break;
    default:
        break;
    }

    return data.findPersons(col, findMe);
}

vector<Computer> serviceLayer::searchComputers(string findMe, int by)
{
    string col = "Name"; // case 1

    switch (by) { // case 2 is handled by searchComputerYears()
    case 3:
        col = "Type";
        break;
    case 4:
        col = "Built";
    default:
        break;
    }

    return data.findComputers(col, findMe);
}

vector<Person> serviceLayer::searchPersonYears(int first, int second, int by)
{
    string col = "BirthYear";

    if(by == 5)
    {
        col = "DeathYear";
    }

    return data.searchPersonYears(col, first, second);
}

vector<Computer> serviceLayer::searchComputerYears(int first, int second)
{
    return data.searchComputerYears(first, second);
}

vector<Person> serviceLayer::sortPersons(int order, int ascOrDesc)
{
    string col = "Name"; // case 1

    switch (order) {
    case 2:
        col = "Gender";
        break;
    case 3:
        col = "Nationality";
        break;
    case 4:
        col = "BirthYear";
        break;
    case 5:
        col = "DeathYear";
        break;
    default:
        break;
    }

    return data.getSortedPersons(col, ascOrDesc);
}

vector<Computer> serviceLayer::sortComputers(int order, int ascOrDesc)
{
    string col = "Name"; // case 1

    switch (order) {
    case 2:
        col = "Year";
        break;
    case 3:
        col = "Type";
        break;
    case 4:
        col = "Built";
    default:
        break;
    }

    return data.getSortedComputers(col, ascOrDesc);
}

void serviceLayer::newPerson(string name, string gender, string nationality, string byear, string dyear)
{
    data.addPerson(getNewPerson(name, gender, nationality, byear, dyear));
}

void serviceLayer::newComputer(string name, string year, string type, string built)
{
    data.addComputer(getNewComputer(name, year, type, built));
}

bool serviceLayer::validateNewPerson(string name, string gender, string nationality, string byear, string dyear)
{
    bool isValid = false;

    if(validateName(name) && validateGender(gender) && validateNationality(nationality) && validateYear(byear))
    {
        if(dyear != "0")
        {
            if(validateYear(dyear) && (dyear > byear))
            {
                isValid = true;
            }
        }
        else
        {
            isValid = true;
        }
    }

    return isValid;
}

bool serviceLayer::validateNewComputer(string name, string year, string type, string& built)
{
    if((name != "") && validateYear(year) && (type != "") && validateBuilt(built))
    {
            return true;
    }

    return false;
}

bool serviceLayer::deletePerson(int id)
{
    return data.deleteItem("Person", id);
}

bool serviceLayer::deleteComputer(int id)
{
   return data.deleteItem("Computer", id);
}

bool serviceLayer::link(int personID, int computerID)
{
    return data.makeRelation(personID, computerID);
}

bool serviceLayer::unLink(int personID, int computerID)
{
    return data.unMakeRelation(personID, computerID);
}

bool serviceLayer::updatePerson(int id, int col, string updateMe)
{
    bool isValid = false;
    string column;

    switch(col){
        case 1:
            isValid = validateName(updateMe); column = "Name";
            break;
        case 2:
            isValid = validateGender(updateMe); column = "Gender";
            break;
        case 3:
            isValid = validateNationality(updateMe); column = "Nationality";
            break;
        case 4:
            isValid = validateYear(updateMe); column = "BirthYear";
            break;
        case 5:
            isValid = validateYear(updateMe); column = "DeathYear";
            break;
        default:
            break;
    }

    if(isValid)
    {
        data.updateTable(id, "Person", column, updateMe);
    }

    return isValid;
}

bool serviceLayer::updateComputer(int id, int col, string updateMe)
{
    bool isValid = false;
    string column;

    switch(col){
        case 1:
            isValid = (updateMe != ""); column = "Name";
            break;
        case 2:
            isValid = validateYear(updateMe); column = "Year";
            break;
        case 3:
            isValid = (updateMe != ""); column = "Type";
            break;
        case 4:
            isValid = validateBuilt(updateMe); column = "Built";
            break;
        default:
            break;
    }

    if(isValid)
    {
        data.updateTable(id, "Computer", column, updateMe);
    }

    return isValid;
}

vector<vector<string>> serviceLayer:: getRelation(string column)
{
    return data.getRelation(column);
}

