#include <SFML/Graphics.hpp>
#include "Boid.h"
#include "Flock.h"

#include <iostream>

int main()
{
    int w = 1920;
    int h = 1080;
    int bc = 2;

    sf::RenderWindow window(sf::VideoMode(w, h), "BOIDS!");
    Flock *flock = new Flock(bc, &window);
    sf::Event event;

    while (window.isOpen())
    {
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // window.clear();
        flock->update();

        window.display();
    }

    delete flock;

    return 0;
}