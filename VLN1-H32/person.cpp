#pragma once
#include "person.h"

using namespace std;

Person::Person(){}

Person::Person(string name, string gender, int byear, int dyear)
{
    _name = name;
    _gender = gender;
    _byear= byear;
    _dyear  = dyear;

}

Person::Person(string name, string gender, int byear)
{
    _name   = name;
    _gender = gender;
    _byear  = byear;
    _dyear  = 0;
}

string Person:: getName()
{
    return _name;
}

string Person:: getGender()
{
    return _gender;
}

int Person::getByear()
{
    return _byear;
}

int Person:: getDyear()
{
    return _dyear;
}

void Person:: setName(string name)
{
    _name = name;
}

void Person:: setGender(string gender)
{
    _gender = gender;
}

void Person:: setByear(int byear)
{
    _byear = byear;
}

void Person:: setDyear(int dyear)
{
    _dyear = dyear;
}

ostream& operator <<(ostream& lhs, Person& rhs)
{
    lhs << "Name:          " << rhs.getName() << endl;
    lhs << "Gender:        " << rhs.getGender() << endl;
    lhs << "Year of birth: " << rhs.getByear() << endl;

    if(rhs.getDyear() > 0)
    {
        lhs << "Year of death: " << rhs.getDyear() << endl;
    }

    return lhs;
}

bool operator < (Person p1, Person p2)
{
    string name1 = p1.getName();
    string name2 = p2.getName();

    int lengtha = name1.length();
    int lengthb = name2.length();

    for(int i = 0; i < lengtha; i++)
    {
        name1[i] = tolower(name1[i]);
    }

    for(int i = 0; i < lengthb; i++)
    {
        name2[i] = tolower(name2[i]);
    }

    if(name1 < name2)
    {
        return true;
    }

    return false;
}
