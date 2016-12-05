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

    if (tmp == wordLength)
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
void serviceLayer::splitAndAdd(string s, int index)
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

    string Name, Gender, Nationality, Byear, Dyear;

    // throw exception if the string did not have the right amount of ';'
    if((elems.size() < 4) || (elems.size() > 5))
    {
       throw string(error);
    }
    else
    {
        Name = elems[0];
        Gender = elems[1];
        Nationality = elems[2];
        Byear = elems[3];

        // if a death year was not included
        if(elems.size() < 5)
        {
            elems.push_back("0");
        }

        Dyear = elems[4];

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
}

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
/*vector<Person> serviceLayer::searchPersons(string findMe, int by)
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
        break;
        findings = data.findPersons("DeathYear", findMe);
    default:
        break;
    }

    return findings;
}*/

/*vector<Computer> serviceLayer::searchComputers(string findMe, int by)
{
    vector<Person> findings;

    switch (by) {
    case 1:
        findings = data.findComputer("Name", findMe);
        break;
    case 2:
        findings = data.findComputer("Year", findMe);
        break;
    case 3:
        findings = data.findComputer("Type", findMe);
        break;
  //  case 4:
   //     findings = data.findComputer("BirthYear", findMe);
      //  break;
    default:
        break;
    }

    return findings;
}*/

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
    {
        sorted = data.getSortedPersons("DeathYear");
        break;
    }
    default:
        break;
    }

    return sorted;
}

/*vector<Person> serviceLayer::sortComputers(int order)
{
    vector<Person> sorted;

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
   // case 4:
   //     sorted = data.getSortedComputers("Built");
    //    break;
    default:
        break;
    }

    return sorted;
}*/

/**
 * @brief serviceLayer::createList
 * @param fileName
 */
void serviceLayer::createList(string fileName)
{
    vector<string> lines = data.loadData(fileName);

    for (unsigned int i = 0; i < lines.size(); i++)
    {
        splitAndAdd(lines[i], (i + 1));
    }
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

/**
 * @brief serviceLayer::saveData
 * @param fileName
 * @param saveMe
 */
void serviceLayer::saveData(string fileName, vector<Person> saveMe)
{
    data.saveData(fileName, saveMe);
}

/**
 * @brief serviceLayer::deletePerson
 * @param name
 */
/*void serviceLayer::deletePerson(string name)
{
    data.findAndDelete(name);
}*/
