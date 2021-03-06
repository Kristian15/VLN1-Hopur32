#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Person
{
private:
    int _id;
    string _name;
    string _gender;
    string _nationality;
    int _byear;
    int _dyear;
    friend ostream& operator << (ostream& lhs, Person& rhs);

public:
    Person();
    Person(int id, string name, string gender, string nationality, int byear, int dyear);
    Person(string name, string gender, string nationality, int byear, int dyear);

    int getID() { return _id; }
    string getName(){ return _name; }
    string getGender() { return _gender; }
    string getNationality(){ return _nationality; }
    int getByear(){ return _byear; }
    int getDyear(){ return _dyear; }

    void setID(int id) { _id = id; }
    void setName(string name){ _name = name; }
    void setGender(string gender){ _gender = gender; }
    void setNationality(string nationality){ _nationality = nationality; }
    void setByear(int byear){ _byear = byear; }
    void setDyear(int dyear){ _dyear = dyear; }
};
