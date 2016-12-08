#include "person.h"

using namespace std;

/**
 * @brief Person::Person
 */
Person::Person(){}


Person::Person(int id, string name, string gender, string nationality, int byear, int dyear)
{
    _id = id;
    _name = name;
    _gender = gender;
    _nationality = nationality;
    _byear= byear;
    _dyear  = dyear;
}

/**
 * @brief Person::Person
 * @param name
 * @param gender
 * @param nationality
 * @param byear
 * @param dyear
 */
Person::Person(string name, string gender, string nationality, int byear, int dyear)
{
    _name = name;
    _gender = gender;
    _nationality = nationality;
    _byear= byear;
    _dyear  = dyear;
}

/**
 * @brief Person::Person
 * @param name
 * @param gender
 * @param nationality
 * @param byear
 */
Person::Person(string name, string gender, string nationality, int byear)
{
    _name   = name;
    _gender = gender;
    _nationality = nationality;
    _byear  = byear;
    _dyear  = 0;
}

/**
 * @brief operator <<
 * @param lhs
 * @param rhs
 * @return ostream&
 */
ostream& operator <<(ostream& lhs, Person& rhs)
{

    lhs << "Name:          " << rhs._name << endl;
    lhs << "Gender:        " << rhs._gender << endl;
    lhs << "Nationality:   " << rhs._nationality << endl;;
    lhs << "Year of birth: " << rhs._byear << endl;

    if(rhs.getDyear() > 0)
    {
        lhs << "Year of death: " << rhs._dyear << endl;
    }

    return lhs;
}
