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
    vector<Person> persons;

public:
    dataLayer();
};

#endif
