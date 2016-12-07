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
        // if the name does not include a digit it is valid
        if ((!isdigit(name[i])))
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
 * @brief serviceLayer::toLower
 * @param s
 * @return bool
 */
/*string serviceLayer::toLower(string s)
{
   string stringLower = s;

   for (unsigned int i = 0; i < s.length(); i++)
   {
       stringLower[i] = tolower(s[i]);
   }

   return stringLower;
}*/

/**
 * @brief serviceLayer::splitLine
 * @param s
 * @param newPersons
 * @param index
 */
/*void serviceLayer::splitAndAdd(string s, int index)
{
    // the function splits the string s and uses to create a new Person
    vector<string> elems;
    string delimeter = data.getDelimeter();
    size_t pos = 0;
    string token;
    string error = "Database format error, invalid data in line " + to_string(index);

    while ((pos = s.find(delimeter)) != string::npos)
    {
        token = s.substr(0, pos);
        elems.push_back(token);
        s.erase(0, pos + delimeter.length());
    }

    string ID, Name, Gender, Nationality, Byear, Dyear;

    // throw exception if the string did not have the right amount of ';'
    if((elems.size() < 5) || (elems.size() > 6))
    {
       throw string(error);
    }
    else
    {
        ID = elems[0];
        Name = elems[1];
        Gender = elems[2];
        Nationality = elems[3];
        Byear = elems[4];

        // if a death year was not included
        if(elems.size() < 6)
        {
            elems.push_back("0");
        }

        Dyear = elems[5];

        // throws exception if the variables are not valid
        if (validateNewPerson(Name, Gender, Nationality, Byear, Dyear))
        {
            data.addPerson(getNewPerson(Name, Gender, Nationality, Byear, Dyear));
        }
        else
        {
            throw string(error);
        }
    }
}*/

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

//*****PUBLIC*****

/**
 * @brief serviceLayer::searchList
 * @param findMe
 * @param by
 * @return vector<Person>
 */
vector<Person> serviceLayer::searchPersons(string findMe, int by)
{
   // string fromTable = "Persons";
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
  //  const string fromTable = "Computers";
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

/**
 * @brief serviceLayer::sortList
 * @param order
 * @return vector<Person>
 */
vector<Person> serviceLayer::sortPersons(int order)
{
    vector<Person> sorted;

    switch (order) {
    case 1:
        sorted = data.getSortedPersons("Name");
        break;
    case 2:
        sorted = data.getSortedPersons("Gender");
        break;
    case 3:
        sorted = data.getSortedPersons("Nationality");
        break;
    case 4:
        sorted = data.getSortedPersons("BirthYear");
        break;
    case 5:
        sorted = data.getSortedPersons("DeathYear");
        break;
    default:
        break;
    }

    return sorted;
}

vector<Computer> serviceLayer::sortComputers(int order)
{
    vector<Computer> sorted;

    switch (order) {
    case 1:
        sorted = data.getSortedComputers("Name");
        break;
    case 2:
        sorted = data.getSortedComputers("Year");
        break;
    case 3:
        sorted = data.getSortedComputers("Type");
        break;
    default:
        break;
    }

    return sorted;
}

/**
 * @brief serviceLayer::createList
 * @param fileName
 */
/*void serviceLayer::createList(string fileName)
{
    vector<string> lines = data.loadData(fileName);

    for (unsigned int i = 0; i < lines.size(); i++)
    {
        splitAndAdd(lines[i], (i + 1));
    }
}*/

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

void serviceLayer::newComputer(string name, string year, string type, string built)
{
    bool builtBool = false;

    if((built == "y"))
    {
        builtBool = true;
    }

    Computer computer;
    computer.setName(name);
    computer.setYear(stoi(year));
    computer.setType(type);
    computer.setBuilt(builtBool);

    data.addComputer(computer);
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
    bool b = false;

    if(validateName(name) && validateGender(gender) && validateNationality(nationality) && validateYear(byear))
    {
        if(dyear != "0")
        {
            if(validateYear(dyear))
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

/**
 * @brief serviceLayer::deletePerson
 * @param name
 */
bool serviceLayer::deletePerson(int id)
{
    return data.deletePerson(id);
}

bool serviceLayer::deleteComputer(int id)
{
   return data.deleteComputer(id);
}

bool serviceLayer::link(int personID, int computerID)
{
    return data.makeRelation(personID, computerID);
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
        data.updateTable(id, "Persons", column, updateMe);
        return isValid;
    }
    return isValid;
}

bool serviceLayer::callUpdateComputer(int id, int column, string updateMe)
{ // **** TODO validation for computers ****
  return false;
}
