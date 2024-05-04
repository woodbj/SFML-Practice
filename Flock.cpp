#include "Flock.h"

Boid *Flock::getBoid(int index)
{
    if (index >= _size)
        return nullptr;
    return _boids[index];
}

void Flock::update()
{
    std::cout << "Updating\n";
    for (int i = 0; i < _size; i++)
    {
        for (int j = 0; j < _size; j++)
        {
            // _otherDistances[j] = _boids[j]->getPos();
            // _otherVelocities[j] = _boids[j]->getDir();
        }
        // _boids[i]->update(_otherDistances, _otherVelocities, _size);
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
