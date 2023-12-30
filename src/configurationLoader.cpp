#include <iostream>
#include <fstream>
#include <sstream>
#include "configurationLoader.h"

using namespace std;

// ===== Public functions =====
ConfigurationLoader::ConfigurationLoader(const string& filepath)
{
    ifstream file(filepath);
    string line, arg;

    while(getline(file, line))
    {
        vector<string> lineArgs;
        stringstream lineStream(line);
        while (getline(lineStream, arg, ' ')) 
        {
            lineArgs.push_back(arg);
        }
        processConfigurationLine(lineArgs);
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

// ===== Private functions =====
void ConfigurationLoader::processConfigurationLine(vector<string>& lineArguments)
{
    string argType = lineArguments.front();

    if (argType == "Window")
    {
        setWindowMembers(lineArguments);
    }
    else if (argType == "Font")
    {

    }
    else if (argType == "Rectangle")
    {

    }
    else if (argType == "Circle")
    {

    }
    else
    {
        cout << "Error: Configuration line of type [" << argType << "] is not valid." << endl;
    }
}

void ConfigurationLoader::setWindowMembers(vector<string>& lineArguments)
{
    // Window W H
    m_windowWidth = stoul(lineArguments.at(1));
    m_windowHeight = stoul(lineArguments.at(2));
}
