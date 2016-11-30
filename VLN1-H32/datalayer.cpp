#include "datalayer.h"

dataLayer::dataLayer()
{

}

vector<string> dataLayer::loadData(string fileName)
{
    data.clear();
    string line;

    _fileName = fileName;

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
    data.clear();
    string name = "", gender = "", nationality = "", bYear = "", dYear = "", delimiter = ";";

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
