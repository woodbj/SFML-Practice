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
    BoidType bt[_size];

    // get position of all boids
    for (int j = 0; j < _size; j++)
    {
        pos[j] = _boids[j]->getPos();
        vel[j] = _boids[j]->getVel();
        bt[j] = _boids[j]->getBoidType();
    }

    // update all boids 
    for (int i = 0; i < _size; i++)
    {
        _boids[i]->update(pos, vel, bt, _size);
    }
}

Flock::Flock(FlockConfig fc, sf::RenderWindow *window)
{
    _size = fc.playCount + fc.predCount + fc.preyCount;
    _window = window;
    _boids = new Boid *[_size];

    for (int i = 0; i < fc.preyCount; i++)
    {
        _boids[i] = new PreyBoid(i, window);
    }

    
}

Flock::~Flock()
{
    delete[] _boids;
}
