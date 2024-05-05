#include "Flock.h"

Boid *Flock::getBoid(int index)
{
    if (index >= _size)
        return nullptr;
    return _boids[index];
}

void Flock::update()
{
    Vector2f pos[_size];
    Vector2f vel[_size];
    for (int i = 0; i < _size; i++)
    {
        for (int j = 0; j < _size; j++)
        {
            pos[j] = _boids[j]->getPos();
            vel[j] = _boids[j]->getVel();
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

Flock::Flock(int size, sf::RenderWindow *window)
{
    std::cout << "Building flock\n";
    _size = size;
    _window = window;
    _boids = new Boid*[_size];

    for (int i = 0; i < _size; i++)
    {
        _boids[i] = new Boid(i, window);
    }
    std::cout << "Flock built\n";
}

Flock::~Flock()
{
    delete[] _boids;
}
