#include "servicelayer.h"

using namespace std;

// **** PRIVATE*****

/**
 * @brief serviceLayer::sortByName
 * @param sortMe
 */
void serviceLayer::sortByName(vector<Person>& sortMe)
{
    Person swap;
    string min, theName;
    size_t tmp;

    size_t theSize = sortMe.size();

    for(size_t i = 0; i < (theSize - 1); i++)
    {
        min = toLower(sortMe[i].getName());
        tmp = i;

        for(size_t j = (i + 1); j < theSize; j++)
        {
            theName = toLower(sortMe[j].getName());

            if(min > theName)
            {
                min = theName;
                tmp = j;
            }
        }

        swap = sortMe[i];
        sortMe[i] = sortMe[tmp];
        sortMe[tmp] = swap;
    }
}

/**
 * @brief serviceLayer::sortByGender
 * @param sortMe
 */
void serviceLayer::sortByGender(vector<Person>& sortMe)
{
    Person swap;
    string min, theGender;
    size_t tmp;

    size_t theSize = sortMe.size();

    for(size_t i = 0; i < (theSize - 1); i++)
    {
        min = toLower(sortMe[i].getGender());
        tmp = i;

        for(size_t j = (i + 1); j < theSize; j++)
        {
            theGender = toLower(sortMe[j].getGender());

            if(min > theGender)
            {
                min = theGender;
                tmp = j;
            }
        }

        swap = sortMe[i];
        sortMe[i] = sortMe[tmp];
        sortMe[tmp] = swap;
    }
}

/**
 * @brief serviceLayer::sortByNationality
 * @param sortMe
 */
void serviceLayer::sortByNationality(vector<Person>& sortMe)
{
    Person swap;
    string min, theNationality;
    size_t tmp;

    size_t theSize = sortMe.size();

    for(size_t i = 0; i < (theSize - 1); i++)
    {
        min = toLower(sortMe[i].getNationality());
        tmp = i;

        for(size_t j = (i + 1); j < theSize; j++)
        {
            theNationality = toLower(sortMe[j].getNationality());
            if(min > theNationality)
            {
                min = theNationality;
                tmp = j;
            }
        }

        swap = sortMe[i];
        sortMe[i] = sortMe[tmp];
        sortMe[tmp] = swap;
    }
}

/**
 * @brief serviceLayer::sortByByear
 * @param sortMe
 */
void serviceLayer::sortByByear(vector<Person>& sortMe)
{
    Person swap;
    int min, theByear;
    size_t tmp;

    size_t theSize = sortMe.size();

    for(size_t i = 0; i < (theSize - 1); i++)
    {
        min = sortMe[i].getByear();
        tmp = i;

        for(size_t j = (i + 1); j < theSize; j++)
        {
            theByear = sortMe[j].getByear();

            if(min > theByear)
            {
                min = theByear;
                tmp = j;
            }
        }

        swap = sortMe[i];
        sortMe[i] = sortMe[tmp];
        sortMe[tmp] = swap;
    }
}

/**
 * @brief serviceLayer::sortByDyear
 * @param sortMe
 */
void serviceLayer::sortByDyear(vector<Person>& sortMe)
{
    Person swap;
    int min, theDyear;
    size_t tmp;

    // if _dyear in Person is 0 it is put last
    int noDeathYear = 5000;

    size_t theSize = sortMe.size();

    for(size_t i = 0; i < (theSize - 1); i++)
    {
        min = sortMe[i].getDyear();

        if(min == 0)
        {
            min = noDeathYear;
        }

        tmp = i;

        for(size_t j = (i + 1); j < theSize; j++)
        {
            theDyear = sortMe[j].getDyear();

            if(theDyear == 0)
            {
                theDyear = noDeathYear;
            }

            if(min > theDyear)
            {
                min = theDyear;
                tmp = j;
            }
        }

        swap = sortMe[i];
        sortMe[i] = sortMe[tmp];
        sortMe[tmp] = swap;
    }
}

/**
 * @brief serviceLayer::findByName
 * @param name
 * @return vector<Person>
 */
vector<Person> serviceLayer::findByName(string name)
{
    vector<Person> findings, theList;
    Person p;
    string searchMe;
    size_t found;

    theList = data.getPersons();

    for (unsigned int i = 0; i < theList.size(); i++)
    {
        p = theList[i];
        searchMe = toLower(p.getName());
        found = searchMe.find(toLower(name));

        if (found != string::npos)
        {
            findings.push_back(p);
        }
    }

    return findings;
}

/**
 * @brief serviceLayer::findByGender
 * @param gender
 * @return vector<Person>
 */
vector<Person> serviceLayer::findByGender(string gender)
{
    vector<Person> findings, theList;
    Person p;

    theList = data.getPersons();

    for (unsigned int i = 0; i < theList.size(); i++)
    {
        p = theList[i];

        if (gender == p.getGender())
        {
            findings.push_back(p);
        }
    }

    return findings;
}

/**
 * @brief serviceLayer::findByNationality
 * @param nationality
 * @return vector<Person>
 */
vector<Person> serviceLayer::findByNationality(string nationality)
{
    vector<Person> findings, theList;
    Person p;
    string searchMe;
    size_t found;

    theList = data.getPersons();

    for (unsigned int i = 0; i < theList.size(); i++)
    {
        p = theList[i];
        searchMe = toLower(p.getNationality());
        found = searchMe.find(toLower(nationality));

        if (found != string::npos)
        {
            findings.push_back(p);
        }
    }

    return findings;
}

/**
 * @brief serviceLayer::findByByear
 * @param byear
 * @return vector<Person>
 */
vector<Person> serviceLayer::findByByear(int byear)
{
    vector<Person> findings, theList;
    Person p;

    theList = data.getPersons();

    for (unsigned int i = 0; i < theList.size(); i++)
    {
        p = theList[i];

        if (byear == p.getByear())
        {
            findings.push_back(p);
        }
    }

    return findings;
}

/**
 * @brief serviceLayer::findByDyear
 * @param dyear
 * @return vector<Person>
 */
vector<Person> serviceLayer::findByDyear(int dyear)
{
    vector<Person> findings;
    Person p;

    vector<Person> theList = data.getPersons();

    for (unsigned int i = 0; i < theList.size(); i++)
    {
        p = theList[i];

        if (dyear == p.getDyear())
        {
            findings.push_back(p);
        }
    }

    return findings;
}

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
    gender = toLower(gender);

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
string serviceLayer::toLower(string s)
{
   string stringLower = s;

   for (unsigned int i = 0; i < s.length(); i++)
   {
       stringLower[i] = tolower(s[i]);
   }

   return stringLower;
}

/**
 * @brief serviceLayer::splitLine
 * @param s
 * @param newPersons
 * @param index
 */
void serviceLayer::splitLine(string s, vector<Person>& newPersons, int index)
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
            Person p = getNewPerson(Name, Gender, Nationality, Byear, Dyear);
            newPersons.push_back(p);
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

/**
 * @brief serviceLayer::findAndDelete
 * @param name
 */
void serviceLayer::findAndDelete(string name)
{
    vector<Person> theList;
    Person p;

    name = toLower(name);

    theList = data.getPersons();

    for (unsigned int i = 0; i < theList.size(); i++)
    {
        p = theList[i];

        if (toLower(p.getName()) == name)
        {
           data.delPerson(i);
        }
    }
}

//*****PUBLIC*****

/**
 * @brief serviceLayer::searchList
 * @param findMe
 * @param by
 * @return vector<Person>
 */
vector<Person> serviceLayer::searchList(string findMe, int by)
{
    vector<Person> findings;

    switch (by) {
    case 1:
        findings = findByName(findMe);
        break;
    case 2:
        findings = findByGender(findMe);
        break;
    case 3:
        findings = findByNationality(findMe);
        break;
    case 4:
        findings = findByByear(stoi(findMe));
        break;
    case 5:
        break;
        findings = findByDyear(stoi(findMe));
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
vector<Person> serviceLayer::sortList(int order)
{
    vector<Person> sortMe = data.getPersons();

    if (!sortMe.empty())
    {
        sortMe = data.getPersons();

        switch (order) {
        case 1:
            sortByName(sortMe);
            break;
        case 2:
            sortByGender(sortMe);
            break;
        case 3:
            sortByNationality(sortMe);
            break;
        case 4:
            sortByByear(sortMe);
            break;
        case 5:
        {
            sortByDyear(sortMe);
            break;
        }
        default:
            break;
        }
    }

    return sortMe;
}

/**
 * @brief serviceLayer::createList
 * @param fileName
 */
void serviceLayer::createList(string fileName)
{
    vector<string> lines = data.loadData(fileName);
    vector<Person> newPersons;

    for (unsigned int i = 0; i < lines.size(); i++)
    {
        splitLine(lines[i], newPersons, (i + 1));
    }
    data.setPersons(newPersons);
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
void serviceLayer::deletePerson(string name)
{
    findAndDelete(name);
    saveData("current", data.getPersons());
}
