#pragma once
#include "person.h"
using namespace std;
Person::Person()
{

}
Person::Person(string name, string gender, int byear, int dyear)
{
    name   = _name;
    gender = _gender;
    byear  = _byear;
    dyear  = _dyear;

}
Person::Person(string name, string gender, int byear)
{
    name   = _name;
    gender = _gender;
    byear  = _byear;
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
