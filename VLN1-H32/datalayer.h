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
    vector<string> data;

public:
    dataLayer();
    // skilar línunum í fileName sem vektor af strengjum
    vector<string> loadData(string fileName); // hlaða inn gögnum inn í forritið við ræsingu
    void saveData(vector<string> personable, string fileName); // vista gögn
};

#endif
