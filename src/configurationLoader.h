#include <SFML/Graphics.hpp>
#include "shapeManager.h"

class ConfigurationLoader 
{
    public:
        ConfigurationLoader(const std::string& filepath, ShapeManager& shapeManager);

        unsigned int getWindowWidth();
        unsigned int getWindowHeight();

    private:
        unsigned int m_windowWidth = 100u;
        unsigned int m_windowHeight = 100u;
        unsigned int m_fontSize = 14u;
        sf::Font m_font;
        sf::Color m_fontColor;
        ShapeManager& m_shapeManager;

        void processConfigurationLine(std::vector<std::string>& lineArguments);
        void setWindowMembers(std::vector<std::string>& lineArguments);
        void setFontMembers(std::vector<std::string>& lineArguments);
        void createRectangleShape(std::vector<std::string>& lineArguments);
        void createCircleShape(std::vector<std::string>& lineArguments);
};