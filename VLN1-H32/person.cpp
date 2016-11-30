#include "person.h"

using namespace std;

Person::Person(){}

Person::Person(string name, string gender, string nationality, int byear, int dyear)
{
    _name = name;
    _gender = gender;
    _nationality = nationality;
    _byear= byear;
    _dyear  = dyear;
}

Person::Person(string name, string gender, string nationality, int byear)
{
    _name   = name;
    _gender = gender;
    _nationality = nationality;
    _byear  = byear;
    _dyear  = 0;
}

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

bool operator < (const Person& leftp, const Person& rightp)
{
    return(leftp._byear < rightp._byear);
}
