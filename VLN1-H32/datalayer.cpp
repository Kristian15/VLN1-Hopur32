#include "datalayer.h"

dataLayer::dataLayer()
{

}

vector<string> dataLayer::loadData(string fileName){ vector<string> todo; return todo; }
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
