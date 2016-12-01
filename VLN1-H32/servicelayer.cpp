#include "servicelayer.h"

using namespace std;
serviceLayer::serviceLayer(){}

// **** PRIVATE*****

// ***** Save data fall *****
void serviceLayer::saveData(string fileName)
{
    data.saveData(fileName);
}

// *****Sort hjálparföll*****
void serviceLayer:: sortByName()
{
    Person swap;

    string min, theName;
    size_t tmp;

    vector<Person> sortMe = data.getPersons();

    unsigned int theSize = sortMe.size();


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

void serviceLayer:: sortByGender()
{
    Person swap;

    string min, theGender;
    size_t tmp;

    vector<Person> sortMe = data.getPersons();

    unsigned int theSize = sortMe.size();


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

void serviceLayer:: sortByNationality()
{
    Person swap;

    string min, theNationality;
    size_t tmp;

    vector<Person> sortMe = data.getPersons();

    unsigned int theSize = sortMe.size();


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

void serviceLayer:: sortByByear()
{
   /* Person swap;

    int theByear, min;
    size_t tmp;

    for(size_t i = 0; i < (persons.size() - 1); i++)
    {
        min = persons[i].getByear();
        tmp = i;

        for(size_t j = (i + 1); j < persons.size(); j++)
        {
            theByear = persons[j].getByear();
            if(min > theByear)
            {
                min = theByear;
                tmp = j;
            }
        }

        swap = persons[i];
        persons[i] = persons[tmp];
        persons[tmp] = swap;
    }*/

    vector<Person> sortMe = data.getPersons();
    stable_sort(sortMe.begin(), sortMe.end());
    data.setPersons(sortMe);
}

void serviceLayer:: sortByDyear()
{
    Person swap;

    int min, theDyear;
    size_t tmp;

    vector<Person> sortMe = data.getPersons();

    unsigned int theSize = sortMe.size();

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

// *****Find hjálparföll****
vector<Person> serviceLayer:: findByName(string name)
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

vector<Person> serviceLayer:: findByGender(string gender)
{
    vector<Person> findings;
    Person p;
    vector<Person> theList = data.getPersons();

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

vector<Person> serviceLayer:: findByNationality(string nationality)
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

vector<Person> serviceLayer:: findByByear(int byear)
{
    vector<Person> findings;
    Person p;
    vector<Person> theList = data.getPersons();

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

vector<Person> serviceLayer:: findByDyear(int dyear)
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

// *** Validate föll*****
bool serviceLayer:: validateName(string name)
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

bool serviceLayer:: validateGender(string gender)
{
    gender = toLower(gender);

    if ((gender == "male") || (gender == "female"))
    {
        return true;
    }

    return false;
}

bool serviceLayer:: validateNationality(string nationality)
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

bool serviceLayer:: validateYear(string year)
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

string serviceLayer:: toLower(string s)
{
   string stringLower = s;

   for (unsigned int i = 0; i < s.length(); i++)
   {
       stringLower[i] = tolower(s[i]);
   }

   return stringLower;
}

void serviceLayer:: splitLine(string s)
{
    vector<string> elems;
    string delimeter = ";";
    size_t pos = 0;
    string token;

    while ((pos = s.find(delimeter)) != string::npos)
    {
        token = s.substr(0, pos);
        elems.push_back(token);
        s.erase(0, pos + delimeter.length());
    }

    string Name, Gender, Nationality, Byear, Dyear;

    if(elems.size() < 4)
    {
       cout << "eroror" << endl;
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

vector<Person> serviceLayer:: searchList(string findMe, string by)
{
    vector<Person> findings;

    by = toLower(by);

    if (by == "name")
    {
        findings = findByName(findMe);
    }
    else if (by == "gender")
    {
        findings = findByGender(findMe);
    }
    else if (by == "nationality")
    {
        findings = findByNationality(findMe);
    }
    else if (by == "birth")
    {
        findings = findByByear(stoi(findMe));
    }
    else if (by == "death")
    {
        findings = findByDyear(stoi(findMe));
    }

    return findings;
}



// sort the list in dataLayer after order
// return the vector in dataLayer sorted
vector<Person> serviceLayer:: sortList(string order)
{
    vector<Person> sortMe = data.getPersons();

    if (!sortMe.empty())
    {
        if (order == "name")
        {
            sortByName();
        }
        else if (order == "gender")
        {
            sortByGender();
        }
        else if (order == "nationality")
        {
            sortByNationality();
        }
        else if (order == "birth")
        {
            sortByByear();
        }
        else if (order == "death")
        {
            sortByDyear();
        }

        sortMe = data.getPersons();
    }

    return sortMe;
}

// break up the lines in fileName
// format name:year:byear:dyear
// calls newPerson
void serviceLayer:: createList(string fileName)
{
    vector<string> lines = data.loadData(fileName);

    for (unsigned int i = 0; i < lines.size(); i++)
    {
        splitLine(lines[i]);
    }
}

// create a new Person and add it to persons in the dataLayer
void serviceLayer:: newPerson(string name, string gender, string nationality, string byear, string dyear)
{
    Person newP;

    if(dyear != "0")
    {
        newP = Person(name, gender, nationality, stoi(byear), stoi(dyear));
    }

    else
    {
        newP = Person(name, gender, nationality, stoi(byear));
    }

    data.addPerson(newP);
    sortByByear();
}

/*bool serviceLayer:: newPerson(string name, string gender, string nationality, string byear)
{
    if(validateName(name) && validateGender(gender) && validateNationality(nationality) && validateYear(byear))
    {
        Person newP = Person(name, gender, nationality, stoi(byear));
        sortByByear();
        data.addPerson(newP);
        return true;
    }

    return false;
}*/

bool serviceLayer:: validateNewPerson(string name, string gender, string nationality, string byear, string dyear)
{
    if(validateName(name) && validateGender(gender) && validateNationality(nationality) && validateYear(byear) && validateYear(dyear))
    {
        return true;
    }

    else return false;
}

