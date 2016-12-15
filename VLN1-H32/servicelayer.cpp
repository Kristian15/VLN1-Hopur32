#include "servicelayer.h"
#include <iostream>

using namespace std;

// **** PRIVATE*****

bool serviceLayer::validateName(string name)
{
    size_t wordLength = name.length();
    unsigned int tmp = 0;

    for (unsigned int i = 0; i < wordLength; i++)
    {
        if (!isdigit(name[i]) && (name != ""))
        {
            tmp ++;
        }
    }

    if ((tmp == wordLength) && (name != ""))
    {
        return true;
    }

    return false;
}

bool serviceLayer::validateGender(string gender)
{
    if ((gender == "male") || (gender == "female"))
    {
        return true;
    }

    return false;
}

bool serviceLayer::validateNationality(string nationality)
{
    size_t wordLength = nationality.length();
    unsigned int tmp = 0;

    for (unsigned int i = 0; i < wordLength; i++)
    {
        char c = nationality[i];

        if ((isspace(c)) || (isalpha(c)))
        {
            tmp ++;
        }
    }

    if (tmp == wordLength)
    {
        return true;
    }

    return false;
}

bool serviceLayer::validateYear(string year)
{
    size_t wordLength = year.length();
    unsigned int tmp = 0;

    for (unsigned int i = 0; i < wordLength; i++)
    {
        if (isdigit(year[i]))
        {
            tmp++;
        }
    }

    time_t now = time(0);
    tm *ltm = localtime(&now);
    int currYear = 1900 + ltm->tm_year; // find current year

    if (tmp == wordLength)
    {
        if ((stoi(year) <= currYear) && (wordLength == 4))
        {
            return true;
        }
    }
    return false;
}

Person serviceLayer:: getNewPerson(string name, string gender, string nationality, string byear, string dyear)
{
    Person newP;
    int Byear = stoi(byear);
    int Dyear = 0;

    // if there is a death year
    if(dyear != "0")
    {
        Dyear = stoi(dyear);   
    }

    newP = Person(name, gender, nationality, Byear, Dyear);

    return newP;
}

Computer serviceLayer:: getNewComputer(string name, string year, string type, string built)
{
    bool builtBool = false;

    if((built == "y"))
    {
       builtBool = true;
    }

    return Computer(name, stoi(year), type, builtBool);
}

//*****PUBLIC*****

void serviceLayer::newPerson(string name, string gender, string nationality, string byear, string dyear)
{
    data.addPerson(getNewPerson(name, gender, nationality, byear, dyear));
}

void serviceLayer::newComputer(string name, string year, string type, string built)
{
    data.addComputer(getNewComputer(name, year, type, built));
}

bool serviceLayer::validateNewPerson(string name, string nationality, string byear, string dyear)
{
    bool isValid = false;

    if(validateName(name) && validateNationality(nationality) && validateYear(byear))
    {
        if(dyear != "0")
        {
            if(validateYear(dyear) && (dyear > byear))
            {
                isValid = true;
            }
        }
        else
        {
            isValid = true;
        }
    }

    return isValid;
}

bool serviceLayer::validateNewComputer(string name, string year, string type)
{
    if((name != "") && validateYear(year) && (type != ""))
    {
            return true;
    }

    return false;
}
