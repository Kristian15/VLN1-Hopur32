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
    if(rhs.getDyear() != NULL)
    {
        lhs << "Year of death  " << rhs.getDyear() << endl;
    }

    return lhs;
}
