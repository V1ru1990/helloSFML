#include <SFML/Graphics.hpp>
#include "Engine/Platform.h"
#include "Engine/World.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_LENGTH, WINDOW_WIDTH), "HELLO SFML!");
    window.setFramerateLimit(1);
    

    Platform firstPlatform;
    firstPlatform.loadTexture("images/platform.png");

    if (!firstPlatform.isTextureLoaded())
    {
        return -1;
    }

    firstPlatform.setRandomPosition();
    firstPlatform.showPosition();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        firstPlatform.reset();
        firstPlatform.showPosition();
        firstPlatform.draw(window);

        window.display();

        
    }

    return 0;
}