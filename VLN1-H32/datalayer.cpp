#include "datalayer.h"

dataLayer::dataLayer()
{

}

vector<string> dataLayer::loadData(string fileName)
{
    string line;
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

    string line = "", delimiter = ";";
    vector<string> dataStrings;

    for (unsigned int i = 0; i < persons.size(); i++)
    {
        line = persons[i].getName();
        line += delimiter;
        line += persons[i].getGender();
        line += delimiter;
        line += to_string(persons[i].getByear());
        line += delimiter;
        line += to_string(persons[i].getDyear());
        line += delimiter;

        dataStrings.push_back(line);

        line = "";
    }

    ofstream dataStream;
    dataStream.open(fileName);

    if(dataStream)
    {
        for(unsigned int i = 0; i < dataStrings.size(); i++)
        {
            dataStream << dataStrings[i] << endl;
        }
    }
    dataStream.close();
}
