#include "Boid.h"

// https://people.ece.cornell.edu/land/courses/ece4760/labs/s2021/Boids/Boids.html#:~:text=Boids%20is%20an%20artificial%20life,very%20simple%20set%20of%20rules.

Boid::Boid(int width, int height, int id)
{
    _id = id;
    _width = width;
    _height = height;
    _pos.x = rand() % _width;
    _pos.y = rand() % _height;
    _dir.x = 2 * (rand() / (1.f * RAND_MAX)) - 1;
    _dir.y = 2 * (rand() / (1.f * RAND_MAX)) - 1;
    _sprite = sf::CircleShape(10.f);
    if (id == 0)
    {
        _sprite.setFillColor(sf::Color::Magenta);
    }
    _sprite.setPosition(_pos);
}

void Boid::update(Vector2f *distances, Vector2f *velocities, int size)
{
    if (_id == 0)
    {
        _dir.x = 0;
        _dir.y = 0;

        separation(distances, size);
    }

    _pos.x += _dir.x;
    _pos.y += _dir.y;

    if (_pos.x > _width)
        _pos.x -= _width;
    if (_pos.y > _height)
        _pos.y -= _height;
    if (_pos.x < 0)
        _pos.x += _width;
    if (_pos.y < 0)
        _pos.y += _height;

    _sprite.setPosition(_pos);
}
void Boid::separation(Vector2f *distances, int size)
{
    Vector2f close;
    close.x = 0;
    close.y = 0;
    float dist;
    for (int i = 0; i < size; i++)
    {
        dist = sqrt(distances[i].x * distances[i].x + distances[i].y * distances[i].y);
        if (dist < _separationRange)
        {
            close.x += _pos.x - distances[i].x;
            close.y += _pos.y - distances[i].y;
        }
        _dir.x += _avoidFactor * close.x;
        _dir.y += _avoidFactor * close.y;
    }
}
void Boid::alignment(Vector2f *velocities, int size)
{
    Vector2f nVel;
    nVel.x = 0;
    nVel.y = 0;
    int neighbours = 0;

    float dist;
    for (int i = 0; i < size; i++)
    {
        dist = sqrt(velocities[i].x * velocities[i].x + velocities[i].y * velocities[i].y);
        if (dist < _alignemntRange)
        {
        }

    }


}
void Boid::cohesion(Vector2f *distances, int size)
{
}

sf::CircleShape Boid::draw()
{
    return _sprite;
}
