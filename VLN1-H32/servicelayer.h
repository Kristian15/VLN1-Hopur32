#ifndef SERVICELAYER_H
#define SERVICELAYER_H
#pragma once
#include <string>
#include "datalayer.h"
#include "person.h"

using namespace std;

class serviceLayer
{
private:

    //þetta fall sorterar eftir strengnum sortOrder
    // notar sort hjálparföll
    void sortList();
    void sortByName();
    void sortByGender();
    void sortByByear();
    void sortByDyear();

    void findByName(string name);
    void findByGender(string gender);
    void findByByear(int byear);
    void findByDyear(int dyear);

    void newPerson(string name, string gender, int byear, int dyear);
    void newPerson(string name, string gender, int byear);
public:

    serviceLayer();
};
#endif
