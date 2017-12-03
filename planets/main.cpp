#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "ViewBase.hpp"

int main()
{    

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    settings.majorVersion = 3;
    settings.minorVersion = 0;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "planets", sf::Style::Default, settings);

	ViewBase viewBase;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
		window.draw(viewBase);
        window.display();
    }

    return 0;
}