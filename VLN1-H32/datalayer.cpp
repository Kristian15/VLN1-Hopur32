#include "datalayer.h"

// **** Private ****

// appends provided data to the end of the last used filename
// pushes that data into the person vector
void dataLayer::updateData(Person person)
{
    string data = "";
    bool match = false;

    if(_persons.empty())
    {
        _fileName = "backup.txt";
        match = true;
    }

    _persons.push_back(person);
    data = person.getName() + _d + person.getGender() + _d + person.getNationality() + _d + to_string(person.getByear()) + _d;

    if(person.getDyear() != 0)
    {
        data += to_string(person.getDyear()) + _d;
    }

    ofstream dataStream;
    dataStream.open(_fileName, ios::app);

    if(dataStream)
    {
        if(match == false)
        {
            dataStream << endl;
        }
        dataStream << data;
        dataStream.close();
    }
}


// **** Public ****
vector<string> dataLayer::loadData(string fileName)
{
    string line;

    _fileName = fileName;
    _data.clear();
    ifstream iDataStream;
    iDataStream.open(fileName);

    if(iDataStream)
    {
        while(getline(iDataStream,line))
        {
            if(!line.empty())
            {
                _data.push_back(line);
            }
        }

        iDataStream.close();
    }
    else
    {
        throw string("No data file found!");
    }

    return _data;
}

// Function formats data and adds a delimiter,
// then saves data to the provided filename.
void dataLayer::saveData(string fileName)
{
    string name = "", gender = "", nationality = "", bYear = "", dYear = "";

    if (fileName != "current")
    {
        _fileName = fileName;
    }

    for (unsigned int i = 0; i < _persons.size(); i++)
    {
        name = _persons[i].getName() + _d;
        gender = _persons[i].getGender() + _d;
        nationality = _persons[i].getNationality() + _d;
        bYear = to_string(_persons[i].getByear()) + _d;

        if(_persons[i].getDyear() != 0)
        {
            dYear = to_string(_persons[i].getDyear()) + _d;
        }

        _data.push_back(name + gender + nationality + bYear + dYear);

        name = "";
        gender = "";
        nationality = "";
        bYear = "";
        dYear = "";
    }

    ofstream dataStream;
    dataStream.open(fileName, ios::trunc);

    if(dataStream)
    {
        for(unsigned int i = 0; i < _data.size(); i++)
        {
            dataStream << _data[i] << endl;
        }

        dataStream.close();
    }
}
