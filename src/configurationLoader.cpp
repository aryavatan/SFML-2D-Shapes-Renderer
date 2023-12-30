#include <iostream>
#include <fstream>
#include <sstream>
#include "configurationLoader.h"

using namespace std;

// ===== Public functions =====
ConfigurationLoader::ConfigurationLoader(const string& filepath, ShapeManager& shapeManager) : shapeManager{shapeManager}
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
        // TODO: set font
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

    Shape rect;
    rect.name = name;
    rect.sf_shape = std::make_shared<sf::RectangleShape>(sf::Vector2f(width, height));
    rect.sf_shape->setPosition(sf::Vector2f(posX, posY));
    rect.sf_shape->setFillColor(sf::Color(r, g, b));
    rect.velocityX = velocityX;
    rect.velocityY = velocityY;

    shapeManager.shapes.push_back(rect);
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

    Shape circle;
    circle.name = name;
    circle.sf_shape = std::make_shared<sf::CircleShape>(radius);
    circle.sf_shape->setPosition(sf::Vector2f(posX, posY));
    circle.sf_shape->setFillColor(sf::Color(r, g, b));
    circle.velocityX = velocityX;
    circle.velocityY = velocityY;

    shapeManager.shapes.push_back(circle);
}
