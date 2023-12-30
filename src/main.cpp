#include <SFML/Graphics.hpp>
#include "configurationLoader.h"

int main()
{
    ConfigurationLoader configuration("../../configuration.txt");
    
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
        window.display();
    }
}