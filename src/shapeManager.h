#ifndef SHAPEMANAGER_H
#define SHAPEMANAGER_H

#include <SFML/Graphics.hpp>
#include <memory>

class Shape 
{
    public:
        std::shared_ptr<sf::Shape> sf_shape;
        std::string name;
        float velocityX, velocityY;
        
        void tick();
};

class ShapeManager
{
    public:
        std::vector<Shape> shapes;

        void tick();
};

#endif