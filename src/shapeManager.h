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

    private:
        void collisionCheck(Shape& shape, sf::Vector2u& windowSize);
        void updatePosition(Shape& shape);
};

#endif