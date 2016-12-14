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
bool serviceLayer::validateNewPerson(string name, string nationality, string byear, string dyear)
{
    bool isValid = false;

    if(validateName(name) && validateNationality(nationality) && validateYear(byear))
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

void serviceLayer::updatePerson(Person person)
{
    data.updatePerson(person);
}

void serviceLayer::updateComputer(Computer computer)
{
    data.updateComputer(computer);
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

vector<Computer> serviceLayer::searchComputers(string input)
{
    return data.searchComputers(input);
}

vector<Person> serviceLayer::searchPersons(string input)
{
    return data.searchPersons(input);
}
