#include <iostream>
#include <fstream>
#include <sstream>
#include "configurationLoader.h"

using namespace std;

// ===== Public functions =====
ConfigurationLoader::ConfigurationLoader(const string& filepath, ShapeManager& shapeManager) : m_shapeManager{shapeManager}
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
        setFontMembers(lineArguments);
    }
    else if (argType == "Rectangle")
    {
        createRectangleShape(lineArguments);
    }
    else if (argType == "Circle")
    {
        createCircleShape(lineArguments);
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

void ConfigurationLoader::setFontMembers(vector<string>& lineArguments)
{
    // Font F S R G B
    sf::Font font;
    font.loadFromFile("../../fonts/" + lineArguments.at(1));

    unsigned int fontSize = stoi(lineArguments.at(2));

    unsigned int r = stoul(lineArguments.at(3));
    unsigned int g = stoul(lineArguments.at(4));
    unsigned int b = stoul(lineArguments.at(5));
    sf::Color color(r, g, b);

    m_shapeManager.setFontSettings(font, color, fontSize);
}

void ConfigurationLoader::createRectangleShape(std::vector<std::string>& lineArguments)
{
    // Rectangle N X Y SX SY R G B W H
    string name = lineArguments.at(1);
    float posX = stof(lineArguments.at(2));
    float posY = stof(lineArguments.at(3));
    float velocityX = stof(lineArguments.at(4));
    float velocityY = stof(lineArguments.at(5));
    int r = stoi(lineArguments.at(6));
    int g = stoi(lineArguments.at(7));
    int b = stoi(lineArguments.at(8));
    float width = stof(lineArguments.at(9));
    float height = stof(lineArguments.at(10));

    sf::Vector2f pos(posX, posY);
    sf::Color color(r, g, b);
    m_shapeManager.createRectangle(name, pos, color, velocityX, velocityY, width, height);
}

void ConfigurationLoader::createCircleShape(std::vector<std::string>& lineArguments)
{
    // Circle N X Y SX SY R G B R
    string name = lineArguments.at(1);
    float posX = stof(lineArguments.at(2));
    float posY = stof(lineArguments.at(3));
    float velocityX = stof(lineArguments.at(4));
    float velocityY = stof(lineArguments.at(5));
    int r = stoi(lineArguments.at(6));
    int g = stoi(lineArguments.at(7));
    int b = stoi(lineArguments.at(8));
    float radius = stof(lineArguments.at(9));

    sf::Vector2f pos(posX, posY);
    sf::Color color(r, g, b);
    m_shapeManager.createCircle(name, pos, color, velocityX, velocityY, radius);
}
