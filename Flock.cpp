#include "Flock.h"

Boid *Flock::getBoid(int index)
{
    if (index >= _size)
        return nullptr;
    return _boids[index];
}

void Flock::update()
{
    for (int i = 0; i < _size; i++)
    {
        _boids[i]->update();
    }
}

Flock::Flock(int size, int width, int height)
{
    std::cout << "Building flock\n";
    _size = size;
    _boids = new Boid *;
    _otherDistances = new Vector2f[_size];
    _otherVelocities = new Vector2f[_size];
    for (int i = 0; i < _size; i++)
    {
        _boids[i] = new Boid(width, height, i);
    }
    std::cout << "Flock built\n";
}

Flock::~Flock()
{
}
