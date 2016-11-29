#pragma once
#include "servicelayer.h"
#include <string>

using namespace std;
serviceLayer::serviceLayer()
{

}
vector<Person> sortByName()
{
    vector<Person> todo;
    return todo;
}

vector<Person> sortByGender()
{
    vector<Person> todo;
    return todo;
}

vector<Person> sortByByear()
{
    vector<Person> todo;
    return todo;
}

vector<Person> sortByDyear()
{
    vector<Person> todo;
    return todo;
}

vector<Person> sortList(string order)
{
    if(order == "byname")
    {
        return sortByName();
    }
    if(order == "bygender")
    {
        return sortByGender();
    }
    if(order == "bybirth")
    {
        return sortByByear();
    }
    if(order == "bydeath")
    {
        return sortByDyear();
    }
}
