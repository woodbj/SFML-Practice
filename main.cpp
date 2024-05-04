#include <SFML/Graphics.hpp>
#include "Boid.h"
#include "Flock.h"

#include <iostream>

int main()
{
    int width = 1000;
    int height = width;
    int boidCount = 25;

    sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");

    Flock *flock = new Flock(boidCount, width, height);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear();
        
        // flock->update();

        for (int i = 0; i < boidCount; i++)
        {
            // window.draw(flock->getBoid(i)->draw());
        }

        window.display();
    }

    delete flock;

    return 0;
}