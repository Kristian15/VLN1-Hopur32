#ifndef PERSON_H
#define PERSON_H
#pragma once
#include <string>

using namespace std;

class Person
{
private:
    string _name;
    string _gender;
    int _byear;
    int _dyear;
    friend ostream& operator <<(ostream& lhs, Person& rhs);

public:
    Person();
    Person(string name, string gender, int byear, int dyear);
    Person(string name, string gender, int byear);

    string getName();
    string getGender();
    int getByear();
    int getDyear();

    void setName(string name);
    void setGender(string gender);
    void setByear(int byear);
    void setDyear(int dyear);

};

#endif // PERSON_H
