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
public:
    Flock(int size, int width, int height);
    ~Flock();
    void update();
    void updateOld();
    Boid* getBoid(int index);
};



#endif