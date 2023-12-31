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