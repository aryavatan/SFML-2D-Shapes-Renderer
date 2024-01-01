#include "shapeManager.h"

void ShapeManager::tick(sf::Window& window)
{
    sf::Vector2u windowSize = window.getSize();
    for(Shape& shape : shapes)
    {
        collisionCheck(shape, windowSize);
        updatePosition(shape);
    }
}

void ShapeManager::collisionCheck(Shape& shape, sf::Vector2u& windowSize)
{
    sf::FloatRect collisionRect = shape.sf_shape->getGlobalBounds();
    sf::Vector2f collisionPosition = collisionRect.getPosition();

    if (collisionPosition.x + shape.velocityX < 0)
    {
        shape.velocityX *= -1.f;
    }
    else if (collisionPosition.x + collisionRect.width + shape.velocityX > windowSize.x)
    {
        shape.velocityX *= -1.f;
    }

    if (collisionPosition.y + shape.velocityY < 0)
    {
        shape.velocityY *= -1.f;
    }
    else if (collisionPosition.y + collisionRect.height + shape.velocityY > windowSize.y)
    {
        shape.velocityY *= -1.f;
    }
}

void ShapeManager::updatePosition(Shape& shape)
{
    // Shape
    sf::Vector2f position = shape.sf_shape->getPosition();
    position.x += shape.velocityX;
    position.y += shape.velocityY;
    shape.sf_shape->setPosition(position);

    // Text
    position = shape.sf_text->getPosition();
    position.x += shape.velocityX;
    position.y += shape.velocityY;
    shape.sf_text->setPosition(position);
}

void ShapeManager::setFontSettings(sf::Font& font, sf::Color& color, unsigned int fontSize)
{
    m_font = font;
    m_fontColor = color;
    m_fontSize = fontSize;
}

void ShapeManager::createRectangle(std::string& name, sf::Vector2f& position, sf::Color& color, float velocityX, float velocityY, float width, float height)
{
    Shape rect;
    rect.sf_shape = std::make_shared<sf::RectangleShape>(sf::Vector2f(width, height));
    initializeShape(rect, name, position, color, velocityX, velocityY);
}

void ShapeManager::createCircle(std::string& name, sf::Vector2f& position, sf::Color& color, float velocityX, float velocityY, float radius)
{
    Shape circle;
    circle.sf_shape = std::make_shared<sf::CircleShape>(radius);
    initializeShape(circle, name, position, color, velocityX, velocityY);
}

void ShapeManager::initializeShape(Shape& shape, std::string& name, sf::Vector2f& position, sf::Color& color, float velocityX, float velocityY)
{
    shape.sf_shape->setPosition(position);
    shape.sf_shape->setFillColor(color);
    shape.velocityX = velocityX;
    shape.velocityY = velocityY;

    shape.sf_text = std::make_shared<sf::Text>();
    shape.sf_text->setFont(m_font);
    shape.sf_text->setFillColor(m_fontColor);
    shape.sf_text->setCharacterSize(m_fontSize);
    shape.sf_text->setString(name);

    float textPosX = position.x + (shape.sf_shape->getLocalBounds().width / 2) - (shape.sf_text->getLocalBounds().width / 2);
    float textPosY = position.y + (shape.sf_shape->getLocalBounds().height / 2) - (shape.sf_text->getLocalBounds().height / 2);
    shape.sf_text->setPosition(sf::Vector2f(textPosX, textPosY));

    shapes.push_back(shape);
}