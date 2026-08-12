#include <SFML/Graphics.hpp>
#include "Engine/Platform.h"
#include "Engine/Player.h"
#include "Engine/World.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_LENGTH, WINDOW_WIDTH), "HELLO SFML!");
    window.setFramerateLimit(60);
    
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        window.display();

        
    }

    return 0;
}