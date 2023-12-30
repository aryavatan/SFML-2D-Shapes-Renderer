#include <SFML/Graphics.hpp>
#include "configurationLoader.h"
#include "shapeManager.h"

int main()
{
    ShapeManager shapeManager;
    ConfigurationLoader configuration("../../configuration.txt", shapeManager);
    
    auto window = sf::RenderWindow{ { configuration.getWindowWidth(), configuration.getWindowHeight() }, "SFML-2D-Shapes-Renderer" };
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        
        window.clear();

        shapeManager.tick(window);
        for(Shape& shape : shapeManager.shapes)
        {
            window.draw(*shape.sf_shape);
        }

        window.display();
    }
}