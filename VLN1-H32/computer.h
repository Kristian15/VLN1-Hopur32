#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>

using namespace std;

class Computer
{
private:
    int _id;
    string _name;
    int _year;
    string _type;
    bool _built;
  //  friend ostream& operator << (ostream& outs, const Computer computer);

public:
    Computer();
    Computer(int id, string name, int year, string type, bool built);
    int getID() { return _id; }
    string getName() { return _name; }
    int getYear() { return _year; }
    string getType() { return _type; }
    bool getBuilt() { return _built; }

    void setId(int id) { _id = id; }
    void setName(string name) { _name = name; }
    void setYear(int year) { _year = year; }
    void setType(string type) { _type = type; }
    void setBuilt(bool built) { _built = built; }
};

#endif // COMPUTER_H
