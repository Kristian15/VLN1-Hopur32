#ifndef DATALAYER_H
#define DATALAYER_H

#pragma once
#include <fstream>
#include <vector>
#include "person.h"

using namespace std;

class dataLayer
{
private:


public:
    vector<Person> persons;
    dataLayer();
    // skilar línunum í fileName sem vektor af strengjum
    vector<string> loadData(string fileName); // hlaða inn gögnum inn í forritið við ræsingu
    void saveData(); // vista gögn
};

#endif
