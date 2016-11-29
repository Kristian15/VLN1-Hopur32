#pragma once
#include "servicelayer.h"
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;
serviceLayer::serviceLayer()
{

}
// **** PRIVATE*****

// ***** Save data fall *****
void serviceLayer::saveData()
{
    string line = "";
    for(int i; i < data.persons.size(); i++)
    {
        line = data.persons[i].getName();
        line += ";";
        line += data.persons[i].getGender();
        line += ";";
        line += data.persons[i].getByear();
        line += ";";
        line += data.persons[i].getDyear();

    }
}

// *****Sort hjálparföll*****
vector<Person> serviceLayer:: sortByName()
{
    // **TODO**
}

vector<Person> serviceLayer:: sortByGender()
{
    // **TODO**
}

vector<Person> serviceLayer:: sortByByear()
{
    // **TODO***
}

vector<Person> serviceLayer:: sortByDyear()
{
    // **TODO**
}

// *****Find hjálparföll****
vector<Person> serviceLayer:: findByName(string name)
{
<<<<<<< HEAD
<<<<<<< HEAD
    vector<Person> none;
    if(order == "byname")
    {
        return sortByName();
    }
    if(order == "bygender")
=======
    // **TODO**
=======
    vector<Person> theList = data.persons;
    vector<Person> findings;


    for (unsigned int i=0; i < theList.size(); i++)
    {
        Person p = theList[i];

        if (name == p.getName())
            findings.push_back(p);
    }

    return findings;
>>>>>>> a97b6cdc7e71f778dd11d01978f65d7d67e05301
}

vector<Person> serviceLayer:: findByGender(string gender)
{
    vector<Person> theList = data.persons;
    vector<Person> findings;


    for (unsigned int i=0; i < theList.size(); i++)
    {
        Person p = theList[i];

        if (gender == p.getGender())
            findings.push_back(p);
    }

    return findings;
}

vector<Person> serviceLayer:: findByByear(int byear)
{
    vector<Person> theList = data.persons;
    vector<Person> findings;


    for (unsigned int i=0; i < theList.size(); i++)
    {
        Person p = theList[i];

        if (byear == p.getByear())
            findings.push_back(p);
    }

    return findings;
}

vector<Person> serviceLayer:: findByDyear(int dyear)
{
    vector<Person> theList = data.persons;
    vector<Person> findings;


    for (unsigned int i=0; i < theList.size(); i++)
    {
        Person p = theList[i];

        if (dyear == p.getDyear())
            findings.push_back(p);
    }

    return findings;
}

// *** Validate föll*****
bool serviceLayer:: validateName(string name)
{
    int wordLength = name.length();
    int tmp = 0;

    for (int i = 0; i < wordLength; i++)
>>>>>>> 1b46f6273e93fa3e1bf63bd0b36454cfc5d07f1a
    {
        if ((isspace(name[i])) || (isalpha(name[i])))
            tmp ++;
    }

    if (tmp == wordLength)
        return true;

    return false;
}

bool serviceLayer:: validateGender(string gender)
{
    gender = toLower(gender);

    if ((gender == "male") || (gender == "female"))
        return true;

    return false;
}

bool serviceLayer:: validateYear(string year)
{
    int wordLength = year.length();
    int tmp = 0;

    for (int i = 0; i < wordLength; i++)
    {
        if (isdigit(year[i]))
            tmp++;
    }

    if (tmp == wordLength)
    {
        if ((stoi(year) < 2016) && (wordLength == 4))
            return true;
    }

    else return none;
}

string serviceLayer:: toLower(string s)
{
   string stringLower = s;

   for (int i = 0; i < s.length(); i++)
       stringLower[i] = tolower(s[i]);

   return stringLower;
}
/*
// creates a new person with the information in info
// format: "name:gender:byear:dyear" or "name:gender:byear"
// uses newPerson()
void serviceLayer:: createPerson(string info)
{
    // **TODO**
}
*/

//*****PUBLIC*****

vector<Person> serviceLayer:: searchList(string findMe, string by)
{
    vector<Person> findings;

    if (by == "name")
        findings = findByName(findMe);
    else if (by == "gender")
        findings = findByGender(findMe);
    else if (by == "birth")
        findings = findByByear(stoi(findMe));
    else if (by == "death")
        findings = findByDyear(stoi(findMe));
    else
        cout << "Invalid input" << endl;

    return findings;
}



// sort the list in dataLayer after order
// return the vector in dataLayer sorted
vector<Person> serviceLayer:: sortList(string order)
{
    vector<Person> sorted;

    if (order == "byname")
        sorted = sortByName();
    else if (order == "bygender")
        sorted = sortByGender();
    else if (order == "bybirth")
        sorted = sortByByear();
    else if (order == "bydeath")
        sorted = sortByDyear();
    else
        cout << "Invalid input" << endl;

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
    /*vector<string> lines = data.loadData(fileName);

    for (int i = 0; i < lines.size(); i++)
    {
        string s = lines[i];
        vector<string> elems;
        string delimeter = ";";
        int pos = 0;
        string token;

        while ((pos = s.find(delimeter)) != s.size())
        {
            token = s.substr(0, pos);
            elems.push_back(token);
            s.erase(0, pos + delimeter.length());
        }

        string Name, Gender, Byear, Dyear;

        Name = elems[0];
        Gender = elems[1];
        Byear = elems[2];

        //
        if ((validateName(Name)) && (validateGender(Gender)) && (validateYear(Byear)))
        {
            if ((elems.size() == 4))
            {
                Dyear = elems[3];

                if (validateYear(Dyear))
                    newPerson(Name, Gender, stoi(Byear), stoi(Dyear));
            }

            else
                newPerson(Name, Gender, stoi(Byear));
        }
    }*/
}

// create a new Person and add it to persons in the dataLayer
void serviceLayer:: newPerson(string name, string gender, int byear, int dyear)
{
    Person newP = Person(name, gender, byear, dyear);
    data.persons.push_back(newP);
}

void serviceLayer:: newPerson(string name, string gender, int byear)
{
    Person newP = Person(name, gender, byear);
    data.persons.push_back(newP);
<<<<<<< HEAD

=======
>>>>>>> 1b46f6273e93fa3e1bf63bd0b36454cfc5d07f1a
}
