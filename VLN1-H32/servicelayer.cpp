#pragma once
#include "servicelayer.h"
#include <string>
#include <algorithm>

using namespace std;
serviceLayer::serviceLayer()
{

}
vector<Person> sortByName()
{
    vector<Person> todo;
    return todo;
}

vector<Person> sortByGender()
{
    vector<Person> todo;
    return todo;
}

vector<Person> sortByByear()
{
    vector<Person> todo;
    return todo;
}

vector<Person> sortByDyear()
{
    vector<Person> todo;
    return todo;
}

vector<Person> sortList(string order)
{
    if(order == "byname")
    {
        return sortByName();
    }
    if(order == "bygender")
    {
        return sortByGender();
    }
    if(order == "bybirth")
    {
        return sortByByear();
    }
    if(order == "bydeath")
    {
        return sortByDyear();
    }
<<<<<<< HEAD
=======

    return false;
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
    // **TODO**
}

// sort the list in dataLayer after order
// return the vector in dataLayer sorted
vector<Person> serviceLayer:: sortList(string order)
{
    // **TODO**
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

    for (int i = 0; i < lines.size(); i++)
    {
      /*  vector<string> elems;
        string Name, Gender, Byear;

        split(elems, lines[i], is_any_of(";"));

        Name = elems[0];
        Gender = elems[1];
        Byear = elems[2];

        if ((validateName(Name)) && (validateGender(Gender)) && (validateYear(Byear)))
        {
            if ((elems.size() == 4))
            {
                if (validateYear(elems[3]))
                    newPerson(Name, Gender, stoi(Byear), stoi(Dyear));
            }

            else
                newPerson(Name, Gender, stoi(Byear));
        }*/
    }
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
>>>>>>> 0bf21261d3d204538f0baf56ed87b7444273e544
}
