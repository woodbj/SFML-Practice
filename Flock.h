#ifndef FLOCK_H
#define FLOCK_H
#include "Boid.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Flock
{
private:
    int _size;
    Boid **_boids;
    sf::RenderWindow *_window;
public:
    Flock(int size, int width, int height, sf::RenderWindow *window);
    ~Flock();
    void update();
    void updateOld();
    Boid* getBoid(int index);
    void toggleAlignment();
    void toggleSeparation();
    void toggleCohesion();
};



#endif