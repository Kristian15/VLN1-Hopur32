#include "servicelayer.h"

using namespace std;

// **** PRIVATE*****

/**
 * @brief serviceLayer::validateName
 * @param name
 * @return bool
 */
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

/**
 * @brief serviceLayer::validateGender
 * @param gender
 * @return bool
 */
bool serviceLayer::validateGender(string gender)
{
    if ((gender == "male") || (gender == "female"))
    {
        return true;
    }

    return false;
}

/**
 * @brief serviceLayer::validateNationality
 * @param nationality
 * @return bool
 */
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

/**
 * @brief serviceLayer::validateYear
 * @param year
 * @return bool
 */
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

/**
 * @brief serviceLayer::validateBuilt
 * @param built
 * @return bool
 */

/**
 * @brief serviceLayer::getNewPerson
 * @param name
 * @param gender
 * @param nationality
 * @param byear
 * @param dyear
 * @return Person
 */
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

/**
 * @brief serviceLayer::getNewComputer
 * @param name
 * @param year
 * @param type
 * @param built
 * @return Computer
 */
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

/**
 * @brief serviceLayer::searchPersons
 * @param findMe
 * @param by
 * @return vector<Person>
 */
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

/**
 * @brief serviceLayer::searchComputers
 * @param findMe
 * @param by
 * @return vector<Computer>
 */
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

/**
 * @brief serviceLayer::searchPersonYears
 * @param first
 * @param second
 * @param by
 * @return vector<Person>
 */
vector<Person> serviceLayer::searchPersonYears(string first, string second, int by)
{
    vector<Person> vec;

    if(validateYear(first) && validateYear(second))
    {
        string col = "BirthYear";

        if(by == 5)
        {
            col = "DeathYear";
        }

        vec = data.searchPersonYears(col, stoi(first), stoi(second));
    }

    return vec;
}

/**
 * @brief serviceLayer::searchComputerYears
 * @param first
 * @param second
 * @return vector<Computer>
 */
vector<Computer> serviceLayer::searchComputerYears(string first, string second)
{
    vector<Computer> vec;

    if(validateYear(first) && validateYear(second))
    {
        vec = data.searchComputerYears(stoi(first), stoi(second));
    }

    return vec;
}

/**
 * @brief serviceLayer::sortPersons
 * @param order
 * @param ascOrDesc
 * @return vector<Person>
 */
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

/**
 * @brief serviceLayer::sortComputers
 * @param order
 * @param ascOrDesc
 * @return vector<Computer>
 */
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

/**
 * @brief serviceLayer::newPerson
 * @param name
 * @param gender
 * @param nationality
 * @param byear
 * @param dyear
 */
void serviceLayer::newPerson(string name, string gender, string nationality, string byear, string dyear)
{
    data.addPerson(getNewPerson(name, gender, nationality, byear, dyear));
}

/**
 * @brief serviceLayer::newComputer
 * @param name
 * @param year
 * @param type
 * @param built
 */
void serviceLayer::newComputer(string name, string year, string type, string built)
{
    data.addComputer(getNewComputer(name, year, type, built));
}

/**
 * @brief serviceLayer::validateNewPerson
 * @param name
 * @param gender
 * @param nationality
 * @param byear
 * @param dyear
 * @return bool
 */
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

/**
 * @brief serviceLayer::validateNewComputer
 * @param name
 * @param year
 * @param type
 * @param built
 * @return bool
 */
bool serviceLayer::validateNewComputer(string name, string year, string type)
{
    if((name != "") && validateYear(year) && (type != ""))
    {
            return true;
    }

    return false;
}

/**
 * @brief serviceLayer::deletePerson
 * @param id
 */
void serviceLayer::deletePerson(int id)
{
    data.deleteItem("Person", id);
}

/**
 * @brief serviceLayer::deleteComputer
 * @param id
 */
void serviceLayer::deleteComputer(int id)
{
   data.deleteItem("Computer", id);
}

/**
 * @brief serviceLayer::link
 * @param personID
 * @param computerID
 */
void serviceLayer::link(int personID, int computerID)
{
    data.makeRelation(personID, computerID);
}

/**
 * @brief serviceLayer::unLink
 * @param personID
 * @param computerID
 */
void serviceLayer::unLink(int personID, int computerID)
{
    data.unMakeRelation(personID, computerID);
}

/**
 * @brief serviceLayer::updatePerson
 * @param id
 * @param col
 * @param updateMe
 * @return bool
 */
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
            isValid = (validateYear(updateMe) || updateMe == "0"); column = "DeathYear";
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

/**
 * @brief serviceLayer::updateComputer
 * @param id
 * @param col
 * @param updateMe
 * @return bool
 */
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
        default:
            break;
    }

    if(isValid)
    {
        data.updateTable(id, "Computer", column, updateMe);
    }

    return isValid;
}

/**
 * @brief serviceLayer::getRelation
 * @param column
 * @return vector<vector<string>>
 */
vector<vector<string>> serviceLayer::getRelation(string column)
{
    return data.getRelation(column);
}

/**
 * @brief serviceLayer::getOneRelation
 * @param id
 * @param table
 * @return vector<string>
 */
vector<string> serviceLayer::getOneRelation(int id, string table)
{
    return data.searchRelation(id, table);
}
