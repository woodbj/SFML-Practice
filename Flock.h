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
    Vector2f *_otherDistances;
    Vector2f *_otherVelocities;
public:
    Flock(int size, int width, int height);
    ~Flock();
    void update();
    Boid* getBoid(int index);


};



#endif