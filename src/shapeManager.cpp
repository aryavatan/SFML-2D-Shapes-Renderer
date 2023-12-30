#include "shapeManager.h"

void ShapeManager::tick()
{
    for(Shape& shape : shapes)
    {
        sf::Vector2f position = shape.sf_shape->getPosition();
        position.x += shape.velocityX;
        position.y += shape.velocityY;
        shape.sf_shape->setPosition(position);
    }
}