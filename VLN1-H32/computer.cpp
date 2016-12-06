#include "computer.h"

Computer::Computer()
{

}

Computer::Computer(string name, int year, string type, bool built)
{
    _name = name;
    _year = year;
    _type = type;
    _built = built;
}
ostream& operator << (ostream& outs, const Computer computer)
{
    outs << "Name:          " << computer._name << endl;
    outs << "Year designed: " << computer._year << endl;
    outs << "Type:          " << computer._type << endl;
    outs << "Type:          ";
    if(computer.getBuilt())
    {
        outs << "Yes " << endl;
    }
    else
    {
        outs << "No " << endl;
    }

    return outs;
}
