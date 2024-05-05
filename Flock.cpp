#include "Flock.h"

Boid *Flock::getBoid(int index)
{
    if (index >= _size)
        return nullptr;
    return _boids[index];
}

void Flock::updateOld()
{
    for (int i = 0; i < _size; i++)
    {
        _boids[i]->update();
    }
}

void Flock::update()
{
    Vector2 dist[_size];
    Vector2 vel[_size];
    Vector2 thisBoid;
    for (int i = 0; i < _size; i++)
    {
        thisBoid.x = _boids[i]->getxPos();
        thisBoid.y = _boids[i]->getyPos();
        for (int j = 0; j < _size; j++)
        {
            dist[j].x = _boids[j]->getxPos();
            dist[j].y = _boids[j]->getyPos();
            vel[j].x = _boids[j]->getxVel();
            vel[j].y = _boids[j]->getyVel();
        }
        _boids[i]->update(dist, vel, _size);
    }
}

Flock::Flock(int size, int width, int height)
{
    std::cout << "Building flock\n";
    _size = size;
    _boids = new Boid*[_size];

    for (int i = 0; i < _size; i++)
    {
        _boids[i] = new Boid(width, height, i);
    }
    std::cout << "Flock built\n";
}

Flock::~Flock()
{
    delete[] _boids;
}
