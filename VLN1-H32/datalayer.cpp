#include "datalayer.h"

dataLayer::dataLayer()
{

}

vector<Person> dataLayer::loadDataP(string fileName)
{
    string line;

    _fileName = fileName;
    data.clear();

    ifstream iDataStream;
    iDataStream.open(fileName);

    if(iDataStream)
    {
        while(getline(iDataStream,line))
        {
            data.push_back(line);
        }

        iDataStream.close();
    }

    for (unsigned int i = 0; i < data.size(); i++)
    {
        string s = data[i];
        vector<string> elems;
        string delimeter = ";";
        size_t pos = 0;
        string token;

        while ((pos = s.find(delimeter)) != string::npos)
        {
            token = s.substr(0, pos);
            elems.push_back(token);
            s.erase(0, pos + delimeter.length());
        }

        string Name, Gender, Nationality, Byear, Dyear;

        Name = elems[0];
        Gender = elems[1];
        Nationality = elems[2];
        Byear = elems[3];

        if(elems.size() == 5)
        {
            Dyear = elems[4];
            Person newPerson = Person(Name, Gender, Nationality, stoi(Byear), stoi(Dyear));
            persons.push_back(newPerson);
        }

        else
        {
            Person newPerson = Person(Name, Gender, Nationality, stoi(Byear));
            persons.push_back(newPerson);
        }
    }

    return persons;
}

vector<string> dataLayer::loadData(string fileName)
{
    string line;

    _fileName = fileName;
    data.clear();

    ifstream iDataStream;
    iDataStream.open(fileName);

    if(iDataStream)
    {
        while(getline(iDataStream,line))
        {
            data.push_back(line);
        }

        iDataStream.close();
    }

    return data;
}

void dataLayer::saveData(vector<Person> persons, string fileName)
{
    string name = "", gender = "", nationality = "", bYear = "", dYear = "", delimiter = ";";

    _fileName = fileName;
    data.clear();

    for (unsigned int i = 0; i < persons.size(); i++)
    {
        name = persons[i].getName() + delimiter;
        gender = persons[i].getGender() + delimiter;
        nationality = persons[i].getNationality() + delimiter;
        bYear = to_string(persons[i].getByear()) + delimiter;

        if(persons[i].getDyear() != 0)
        {
            dYear = to_string(persons[i].getDyear()) + delimiter;
        }

        data.push_back(name + gender + nationality + bYear + dYear);

        name = "";
        gender = "";
        nationality = "";
        bYear = "";
        dYear = "";
    }

    ofstream dataStream;
    dataStream.open(fileName);

    if(dataStream)
    {
        for(unsigned int i = 0; i < data.size(); i++)
        {
            dataStream << data[i] << endl;
        }
    }

    dataStream.close();
}

void dataLayer::updateFile(string name, string gender, string nationality, string byear, string dyear)
{
    string d = ";", data = "";
    data = name + d + gender + d + nationality + d + byear + d + dyear + d;

    ofstream dataStream;
    dataStream.open(_fileName);

    if(dataStream)
    {
        dataStream << data << endl;
    }

    dataStream.close();
}
