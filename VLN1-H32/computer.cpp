#include "computer.h"

Computer::Computer()
{

}

Computer::Computer(int id, string name, int year, string type, bool built)
{
    _id = id;
    _name = name;
    _year = year;
    _type = type;
    _built = built;
}
