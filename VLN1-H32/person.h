#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person
{
private:
    string name;
    string gender;
    int age;
    int byear;
    int dyear;
public:
    Person();
    Person(string name, string gender, int age, int byear);
    Person(string name, string gender, int age, int byear, int dyear);
    string getName();
    string getGender();
    int getAge();
    int getByear();
    int getDyear();
    void setName(string name);
    void setGender(string gender);
    void setAge(int age);
    void setByear(int byear);
    void setDyear(int dyear);
};

#endif // PERSON_H
