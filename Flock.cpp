#include "Flock.h"

Boid *Flock::getBoid(int index)
{
    if (index >= _size)
        return nullptr;
    return _boids[index];
}

void Flock::update()
{
    Vector2 pos[_size];
    Vector2 vel[_size];
    for (int i = 0; i < _size; i++)
    {
        for (int j = 0; j < _size; j++)
        {
            pos[j].x = _boids[j]->getxPos();
            pos[j].y = _boids[j]->getyPos();
            vel[j].x = _boids[j]->getxVel();
            vel[j].y = _boids[j]->getyVel();
        }
        _boids[i]->update(pos, vel, _size);
    }
}

void Flock::toggleAlignment()
{
    for (int i = 0; i < _size; i++)
    {
        _boids[i]->toggleAlignment();
    }
}

void Flock::toggleSeparation()
{
    for (int i = 0; i < _size; i++)
    {
        _boids[i]->toggleSeparation();
    }
}

void Flock::toggleCohesion()
{
    for (int i = 0; i < _size; i++)
    {
        _boids[i]->toggleCohesion();
    }
}

Flock::Flock(int size, int width, int height, sf::RenderWindow *window)
{
    std::cout << "Building flock\n";
    _size = size;
    _window = window;
    _boids = new Boid*[_size];

    for (int i = 0; i < _size; i++)
    {
        _boids[i] = new Boid(width, height, i, window);
    }
    std::cout << "Flock built\n";
}

Flock::~Flock()
{
    delete[] _boids;
}
