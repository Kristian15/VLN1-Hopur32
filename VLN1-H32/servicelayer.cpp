#pragma once
#include "servicelayer.h"
#include <string>
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;
serviceLayer::serviceLayer(){}

// **** PRIVATE*****

// ***** Save data fall *****
void serviceLayer::saveData(string fileName)
{
    data.saveData(persons, fileName);
}

// *****Sort hjálparföll*****
vector<Person> serviceLayer:: sortByName()
{
    Person swap;

    string min, theName;
    size_t tmp;

    for(size_t i = 0; i < (persons.size() - 1); i++)
    {
        min = persons[i].getName();
        tmp = i;

        for(size_t j = (i + 1); j < persons.size(); j++)
        {
            theName = toLower(persons[j].getName());
            if(min > theName)
            {
                min = theName;
                tmp = j;
            }
        }

        swap = persons[i];
        persons[i] = persons[tmp];
        persons[tmp] = swap;
    }

    return persons;
}

vector<Person> serviceLayer:: sortByGender()
{
    Person swap;

    string min, theGender;
    size_t tmp;

    for(size_t i = 0; i < (persons.size() - 1); i++)
    {
        min = persons[i].getGender();
        tmp = i;

        for(size_t j = (i + 1); j < persons.size(); j++)
        {
            theGender = toLower(persons[j].getGender());
            if(min > theGender)
            {
                min = theGender;
                tmp = j;
            }
        }

        swap = persons[i];
        persons[i] = persons[tmp];
        persons[tmp] = swap;
    }

    return persons;
}

vector<Person> serviceLayer:: sortByByear()
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

    stable_sort(persons.begin(), persons.end());

    return persons;
}

vector<Person> serviceLayer:: sortByDyear()
{
    Person swap;

    int theDyear, min;
    size_t tmp;

    for(size_t i = 0; i < (persons.size() - 1); i++)
    {
        min = persons[i].getDyear();
        tmp = i;

        for(size_t j = (i + 1); j < persons.size(); j++)
        {
            theDyear = persons[j].getDyear();
            if(min > theDyear)
            {
                min = theDyear;
                tmp = j;
            }
        }

        swap = persons[i];
        persons[i] = persons[tmp];
        persons[tmp] = swap;
    }

    return persons;
}

// *****Find hjálparföll****
vector<Person> serviceLayer:: findByName(string name)
{
    vector<Person> findings;

    for (unsigned int i = 0; i < persons.size(); i++)
    {
        Person p = persons[i];

        if (name == toLower(p.getName()))
        {
            findings.push_back(p);
        }
    }

    return findings;
}

vector<Person> serviceLayer:: findByGender(string gender)
{
    vector<Person> findings;

    for (unsigned int i = 0; i < persons.size(); i++)
    {
        Person p = persons[i];

        if (gender == toLower(p.getGender()))
        {
            findings.push_back(p);
        }
    }

    return findings;
}

vector<Person> serviceLayer:: findByByear(int byear)
{
    vector<Person> findings;

    for (unsigned int i = 0; i < persons.size(); i++)
    {
        Person p = persons[i];

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

    for (unsigned int i = 0; i < persons.size(); i++)
    {
        Person p = persons[i];

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
    order = toLower(order);
    vector<Person> sorted;

    if (order == "byname")
    {
        sorted = sortByName();
    }
    else if (order == "bygender")
    {
        sorted = sortByGender();
    }
    else if (order == "bybirth")
    {
        sorted = sortByByear();
    }
    else if (order == "bydeath")
    {
        sorted = sortByDyear();
    }

    return sorted;
}

/* ef við viljum að notandi geti raðað listanum áður en hann er prentaður í search()
þetta fall myndi þá raða sortMe eftir order
myndi nota sort hjálparföllin
 vector<Person> sortList(vector<Person> sortMe, string order)
*/

// break up the lines in fileName
// format name:year:byear:dyear
// calls newPerson
void serviceLayer:: createList(string fileName)
{
    vector<string> lines = data.loadData(fileName);

    for (unsigned int i = 0; i < lines.size(); i++)
    {
        string s = lines[i];
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

        Name = elems[0];
        Gender = elems[1];
        Nationality = elems[2];
        Byear = elems[3];

        if(elems.size() == 5)
        {
            Dyear = elems[4];
            newPerson(Name, Gender, Nationality, Byear, Dyear);
        }

        else
        {
            newPerson(Name, Gender, Nationality, Byear);
        }
    }
}

// create a new Person and add it to persons in the dataLayer
void serviceLayer:: newPerson(string name, string gender, string nationality, string byear, string dyear)
{
    if(validateName(name) && validateGender(gender) && validateYear(byear) && validateYear(dyear))
    {
        cout << "her1" << endl;
        Person newP = Person(name, gender, nationality, stoi(byear), stoi(dyear));
        persons.push_back(newP);
    }
}

void serviceLayer:: newPerson(string name, string gender, string nationality, string byear)
{
    if(validateName(name) && validateGender(gender) && validateYear(byear))
    {
        cout << name << endl;
        Person newP = Person(name, gender, nationality, stoi(byear));
        persons.push_back(newP);
    }
}
