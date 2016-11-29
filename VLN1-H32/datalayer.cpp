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

void dataLayer::saveData(vector<string> personable, string fileName)
{
    ofstream dataStream;
    dataStream.open(fileName);

    if(dataStream)
    {
        for(int i = 0; i < personable.size(); i++)
        {
            dataStream << personable[i] << endl;
        }
    }
    dataStream.close();
}
