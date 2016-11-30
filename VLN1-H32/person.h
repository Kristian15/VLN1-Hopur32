#pragma once
#include <string>
#include <iostream>

using namespace std;

class Person
{
private:
    string _name;
    string _gender;
    string _nationality;
    int _byear;
    int _dyear;
    friend ostream& operator << (ostream& lhs, Person& rhs);
    friend bool operator > (Person leftp, Person rightp);

public:
    Person();
    Person(string name, string gender, string nationality, int byear, int dyear);
    Person(string name, string gender, string nationality, int byear);

    string getName(){ return _name; }
    string getGender() { return _gender; }
    string getNationality(){ return _nationality; }
    int getByear(){ return _byear; }
    int getDyear(){ return _dyear; }

    void setName(string name){ _name = name; }
    void setGender(string gender){ _gender = gender; }
    void setNationality(string nationality){ _nationality = nationality; }
    void setByear(int byear){ _byear = byear; }
    void setDyear(int dyear){ _dyear = dyear; }

};
