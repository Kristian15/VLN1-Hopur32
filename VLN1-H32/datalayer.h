#pragma once
#include <fstream>
#include <vector>
#include <string>
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
    void saveData(vector<Person> persons, string fileName); // vista gögn
};
