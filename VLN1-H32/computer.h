#pragma once

#include "person.h"
#include <string>
#include <iostream>

using namespace std;

class Computer
{
private:
    int _id;
    string _name;
    int _year;
    string _type;
    bool _built;
    friend ostream& operator << (ostream& outs, const Computer computer);

public:
    Computer();
    Computer(int id, string name, int year, string type, bool built);
    Computer(string name, int year, string type, bool built);
    int getID() const { return _id; }
    string getName() const { return _name; }
    int getYear() const { return _year; }
    string getType() const { return _type; }
    bool getBuilt() const { return _built; }

    void setID(int id) { _id = id; }
    void setName(string name) { _name = name; }
    void setYear(int year) { _year = year; }
    void setType(string type) { _type = type; }
    void setBuilt(bool built) { _built = built; }
};
