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

    string name = "", gender = "", bYear = "", dYear = "", delimiter = ";";
    vector<string> dataStrings;

    for (unsigned int i = 0; i < persons.size(); i++)
    {
        name = persons[i].getName() + delimiter;
        gender = persons[i].getGender() + delimiter;
        bYear = to_string(persons[i].getByear()) + delimiter;

        if(persons[i].getDyear() != 0)
        {
            dYear = to_string(persons[i].getDyear()) + delimiter;
        }

        dataStrings.push_back(name + gender + bYear + dYear);

        name = "";
        gender = "";
        bYear = "";
        dYear = "";
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
