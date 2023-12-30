#include <iostream>
#include <fstream>
#include <sstream>
#include "configurationLoader.h"

using namespace std;

ConfigurationLoader::ConfigurationLoader(const string& filepath)
{
    ifstream file(filepath);
    string line, arg;

    while(getline(file, line))
    {
        stringstream lineStream(line);
        while (getline(lineStream, arg, ' ')) 
        {
            cout << arg << endl;
        }
    }

    file.close();
}

unsigned int ConfigurationLoader::getWindowWidth() 
{
    return m_windowWidth;
}  

unsigned int ConfigurationLoader::getWindowHeight()
{
    return m_windowHeight;
}

void ConfigurationLoader::setWindowMembers()
{

}
