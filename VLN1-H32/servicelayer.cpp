#include "servicelayer.h"

using namespace std;

// **** PRIVATE*****

bool serviceLayer::validateName(string name)
{
    size_t wordLength = name.length();
    unsigned int tmp = 0;

    for (unsigned int i = 0; i < wordLength; i++)
    {
        // if the name does not include a digit it is valid
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
        // spaces and alphas are alowed
        if ((isspace(nationality[i])) || (isalpha(nationality[i])))
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

Person serviceLayer:: getNewPerson(string name, string gender, string nationality, string byear, string dyear)
{
    Person newP;
    int Byear, Dyear;

    // if there is no death year
    if(dyear != "0")
    {
        Byear = stoi(byear);
        Dyear = stoi(dyear);

        if (Byear < Dyear)
        {
            newP = Person(name, gender, nationality, stoi(byear), stoi(dyear));
        }
    }
    else
    {
        newP = Person(name, gender, nationality, stoi(byear));
    }

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
    vector<Person> findings;

    switch (by) {
    case 1:
        findings = data.findPersons("Name", findMe);
        break;
    case 2:
        findings = data.findPersons("Gender", findMe);
        break;
    case 3:
        findings = data.findPersons("Nationality", findMe);
        break;
    case 4:
        findings = data.findPersons("BirthYear", findMe);
        break;
    case 5:
        findings = data.findPersons("DeathYear", findMe);
        break;
    default:
        break;
    }

    return findings;
}

vector<Computer> serviceLayer::searchComputers(string findMe, int by)
{
    vector<Computer> findings;

    switch (by) {
    case 1:
        findings = data.findComputers("Name", findMe);
        break;
    case 2:
        findings = data.findComputers("Year", findMe);
        break;
    case 3:
        findings = data.findComputers("Type", findMe);
        break;
    default:
        break;
    }

    return findings;
}

vector<Person> serviceLayer::sortPersons(int order, int ascOrDesc)
{
    vector<Person> sorted;

    switch (order) {
    case 1:
        sorted = data.getSortedPersons("Name", ascOrDesc);
        break;
    case 2:
        sorted = data.getSortedPersons("Gender", ascOrDesc);
        break;
    case 3:
        sorted = data.getSortedPersons("Nationality", ascOrDesc);
        break;
    case 4:
        sorted = data.getSortedPersons("BirthYear", ascOrDesc);
        break;
    case 5:
        sorted = data.getSortedPersons("DeathYear", ascOrDesc);
        break;
    default:
        break;
    }

    return sorted;
}

vector<Computer> serviceLayer::sortComputers(int order, int ascOrDesc)
{
    vector<Computer> sorted;

    switch (order) {
    case 1:
        sorted = data.getSortedComputers("Name", ascOrDesc);
        break;
    case 2:
        sorted = data.getSortedComputers("Year", ascOrDesc);
        break;
    case 3:
        sorted = data.getSortedComputers("Type", ascOrDesc);
        break;
    default:
        break;
    }

    return sorted;
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
    bool b = false;

    if(validateName(name) && validateGender(gender) && validateNationality(nationality) && validateYear(byear))
    {
        if(dyear != "0")
        {
            if(validateYear(dyear) && dyear > byear)
            {
                b = true;
            }
        }
        else
        {
            b = true;
        }
    }

    return b;
}

bool serviceLayer::validateNewComputer(string name, string year, string type, string& built)
{
  /*  bool theBuilt;
    if(validateBuilt(built, theBuilt))
    {

    }*/
    if(built.size() == 1)
    {
        built = tolower(built[0]);

        if((name != "") && validateYear(year) && (type != ""))
        {
            if((built == "y") || (built == "n"))
            {
                return true;
            }
        }
    }

    return false;
}

/*bool serviceLayer::validateBuilt(string built, bool& theBuilt)
{
    if(built.size() == 1)
    {
        built = tolower(built[0]);

        if(built == "y")
        {
            theBuilt = true;
            return true;
        }
        else if(built == "n")
        {
            theBuilt = false;
            return true;
        }
    }

    return false;
}*/

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

bool serviceLayer::callUpdatePerson(int id, int col, string updateMe)
{
    bool isValid = false;
    string column;
    // *** todo *** beautify
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
            isValid = validateYear(updateMe); column = "bYear";
            break;
        case 5:
            isValid = validateYear(updateMe); column = "dYear";
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

bool serviceLayer::callUpdateComputer(int id, int column, string updateMe)
{
   /* bool isValid = false;
    string column;
    // *** todo *** beautify
    switch(col){
        case 1:
            isValid = (updateMe != ""); column = "Name";
            break;
        case 2:
            isValid = validateYear(updateMe); column = "Gender";
            break;
        case 3:
            isValid = (updateMe != ""); column = "Nationality";
            break;
        case 4:
            isValid = validateYear(updateMe); column = "bYear";
            break;
        default:
            break;
    }

    if(isValid)
    {
        data.updateTable(id, "Person", column, updateMe);
    }

    return isValid;*/
    return false;
}

vector<vector<string>> serviceLayer:: getRelation(string column)
{
    return data.getRelation(column);
}

