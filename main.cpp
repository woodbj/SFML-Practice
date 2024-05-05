#include <SFML/Graphics.hpp>
#include "Boid.h"
#include "Flock.h"

#include <iostream>

int main()
{
    int w = 1000;
    int h = 1000;
    int bc = 50;

    sf::RenderWindow window(sf::VideoMode(w, h), "SFML works!");
    Flock *flock = new Flock(bc, w, h, &window);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        flock->update();

        for (int i = 0; i < bc; i++)
        {
            window.draw(flock->getBoid(i)->draw());
        }

        window.display();
    }

    delete flock;

    return 0;
}