#include "Flock.h"

Boid* Flock::getBoid(int index)
{
    if(index >= _size) return nullptr;
    return _boids[index];
}

void Flock::update()
{
    Vector2f avg;
    avg.x = 0;
    avg.y = 0;

    for (int i = 0; i < _size; i++){
        _boids[i]->update();
    }
}

Flock::Flock(int size, int width, int height)
{
    _size = size;
    _boids = new Boid*;
    for (int i = 0; i < _size; i++){
        _boids[i] = new Boid(width, height);
    }

}

Flock::~Flock()
{
    delete[] _boids;
}
