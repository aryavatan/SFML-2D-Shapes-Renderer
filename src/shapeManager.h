#ifndef SHAPEMANAGER_H
#define SHAPEMANAGER_H

#include <SFML/Graphics.hpp>
#include <memory>

class Shape 
{
    public:
        std::shared_ptr<sf::Shape> sf_shape;
        std::shared_ptr<sf::Text> sf_text;
        float velocityX, velocityY;
};

class ShapeManager
{
    public:
        std::vector<Shape> shapes;

        void tick(sf::Window& window);
        void createRectangle(std::string& name, sf::Vector2f& position, sf::Color& color, float velocityX, float velocityY, float width, float height);
        void createCircle(std::string& name, sf::Vector2f& position, sf::Color& color, float velocityX, float velocityY, float radius);
        void setFontSettings(sf::Font& font, sf::Color& color, unsigned int fontSize);

    private:
        unsigned int m_fontSize = 14u;
        sf::Font m_font;
        sf::Color m_fontColor;

        void collisionCheck(Shape& shape, sf::Vector2u& windowSize);
        void updatePosition(Shape& shape);
        void initializeShape(Shape& shape, std::string& name, sf::Vector2f& position, sf::Color& color, float velocityX, float velocityY);
};

#endif