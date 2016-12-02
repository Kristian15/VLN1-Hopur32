#include "servicelayer.h"
// *** TAKA IOSTREAM ÚT***
#include <iostream>

using namespace std;

// **** PRIVATE*****

// Sort help functions:
void serviceLayer::sortByName()
{
    Person swap;
    string min, theName;
    size_t tmp;

    vector<Person> sortMe = data.getPersons();
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

    data.setPersons(sortMe);
}

void serviceLayer::sortByGender()
{
    Person swap;
    string min, theGender;
    size_t tmp;

    vector<Person> sortMe = data.getPersons();
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

    data.setPersons(sortMe);
}

void serviceLayer::sortByNationality()
{
    Person swap;
    string min, theNationality;
    size_t tmp;

    vector<Person> sortMe = data.getPersons();
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

    data.setPersons(sortMe);
}

void serviceLayer::sortByByear()
{
    Person swap;
    int min, theByear;
    size_t tmp;

    vector<Person> sortMe = data.getPersons();
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

    data.setPersons(sortMe);
}

void serviceLayer::sortByDyear()
{
    Person swap;
    int min, theDyear;
    size_t tmp;

    vector<Person> sortMe = data.getPersons();
    size_t theSize = sortMe.size();

    for(size_t i = 0; i < (theSize - 1); i++)
    {
        min = sortMe[i].getDyear();
        tmp = i;

        for(size_t j = (i + 1); j < theSize; j++)
        {
            theDyear = sortMe[j].getDyear();

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

    data.setPersons(sortMe);
}

// Find help functions:
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

// Validate help functions:
bool serviceLayer::validateName(string name)
{
    size_t wordLength = name.length();
    unsigned int tmp = 0;

    for (unsigned int i = 0; i < wordLength; i++)
    {
        if ((isspace(name[i])) || (isalpha(name[i])))
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

bool serviceLayer::validateGender(string gender)
{
    gender = toLower(gender);

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
    int currYear = 1900 + ltm->tm_year;

    if (tmp == wordLength)
    {
        if ((stoi(year) < currYear) && (wordLength == 4))
        {
            return true;
        }
    }
    return false;
}

// Change uppercase letters in s to lowercase
string serviceLayer::toLower(string s)
{
   string stringLower = s;

   for (unsigned int i = 0; i < s.length(); i++)
   {
       stringLower[i] = tolower(s[i]);
   }

   return stringLower;
}

// Splits string s on ";"
// Calls newPerson() with the splitted string s as input
void serviceLayer::splitLine(string s)
{
    vector<string> elems;
    string delimeter = ";";
    size_t pos = 0;
    string token;
    string error;

    while ((pos = s.find(delimeter)) != string::npos)
    {
        token = s.substr(0, pos);
        elems.push_back(token);
        s.erase(0, pos + delimeter.length());
    }

    string Name, Gender, Nationality, Byear, Dyear;

    if(elems.size() < 4 || elems.size() > 5)
    {
       error = "Database format error, valid data is loaded";
       throw string(error);
    }
    else
    {
        Name = elems[0];
        Gender = elems[1];
        Nationality = elems[2];
        Byear = elems[3];

        if(elems.size() < 5)
        {
            elems.push_back("0");
        }

        Dyear = elems[4];

        if (validateNewPerson(Name, Gender, Nationality, Byear, Dyear))
        {
            newPerson(Name, Gender, Nationality, Byear, Dyear);
        }
    }
}

//*****PUBLIC*****

// search the vector persons in dataLayer for findMe by by
// returns a vector with the findings
vector<Person> serviceLayer::searchList(string findMe, int by)
{
    vector<Person> findings;

    switch (by) {
    case '1':
        findings = findByName(findMe);
        break;
    case '2':
        findings = findByGender(findMe);
        break;
    case '3':
        findings = findByNationality(findMe);
        break;
    case '4':
        findings = findByByear(stoi(findMe));
        break;
    case '5':
        break;
        findings = findByDyear(stoi(findMe));
    default:
        break;
    }
    return findings;
}

// sort the list in dataLayer after order
// return the vector in dataLayer sorted
vector<Person> serviceLayer::sortList(int order)
{
    vector<Person> sortMe = data.getPersons();

    if (!sortMe.empty())
    {
        sortMe = data.getPersons();

        switch (order) {
        case 1:
            sortByName();
            break;
        case 2:
            sortByGender();
            break;
        case 3:
            sortByNationality();
            break;
        case 4:
            sortByByear();
            break;
        case 5:
            break;
            sortByDyear();
        default:
            break;
        }
    }
    return sortMe;
}

// calls loadData() in dataLayer en gets a vector of strings from the file back
// calls splitLine() for every line from the file
void serviceLayer::createList(string fileName)
{
    vector<string> lines = data.loadData(fileName);

    for (unsigned int i = 0; i < lines.size(); i++)
    {
        splitLine(lines[i]);
    }
}

// create a new Person and add it to persons in the dataLayer
// uses addPerson() in dataLayer
void serviceLayer::newPerson(string name, string gender, string nationality, string byear, string dyear)
{
    Person newP;
    int Byear, Dyear;

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

    data.addPerson(newP);
}

// validates inputs
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

// saveData from fileName
// uses saveData() in dataLayer
void serviceLayer::saveData(string fileName)
{
    data.saveData(fileName);
}
