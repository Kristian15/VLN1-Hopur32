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
    lhs << "Name:          " << rhs.getName() << endl;
    lhs << "Gender:        " << rhs.getGender() << endl;
    lhs << "Nationality:   " << rhs.getNationality();
    lhs << "Year of birth: " << rhs.getByear() << endl;

    if(rhs.getDyear() > 0)
    {
        lhs << "Year of death: " << rhs.getDyear() << endl;
    }

    return lhs;
}

bool operator > (Person leftp, Person rightp)
{
    if(leftp.getByear() > rightp.getDyear())
        return true;
     else
        return false;
}
