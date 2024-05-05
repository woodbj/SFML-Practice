#include "Boid.h"

// https://people.ece.cornell.edu/land/courses/ece4760/labs/s2021/Boids/Boids.html#:~:text=Boids%20is%20an%20artificial%20life,very%20simple%20set%20of%20rules.

void Boid::normaliseVelocity()
{
    float vel = sqrt(_dir.x * _dir.x + _dir.y * _dir.y);
    _dir.x /= vel;
    _dir.y /= vel;
}

void Boid::constrainPosition()
{

    if (_pos.x > _width)
        _pos.x -= _width;
    if (_pos.y > _height)
        _pos.y -= _height;
    if (_pos.x < 0)
        _pos.x += _width;
    if (_pos.y < 0)
        _pos.y += _height;
}

float Boid::getDist(Vector2 otherBoid)
{
    float dx = _pos.x - otherBoid.x;
    float dy = _pos.y - otherBoid.y;
    return sqrt(dx * dx + dy * dy);
}

Boid::Boid(int width, int height, int id, sf::RenderWindow *window)
{
    _id = id;
    _width = width;
    _height = height;
    _window = window;
    _pos.x = rand() % _width;
    _pos.y = rand() % _height;
    _dir.x = 2 * (rand() / (1.f * RAND_MAX)) - 1;
    _dir.y = 2 * (rand() / (1.f * RAND_MAX)) - 1;
    Boid::normaliseVelocity();
    _sprite = sf::CircleShape(10.f);
    if (id == 0)
    {
        _sprite.setFillColor(sf::Color::Magenta);
    }
    _sprite.setPosition(_pos.x, _pos.y);
}

void Boid::update(Vector2 *distances, Vector2 *velocities, int size)
{

    separation(distances, size);
    alignment(distances, velocities, size);
    cohesion(distances, size);

    _pos.x += _dir.x;
    _pos.y += _dir.y;

    normaliseVelocity();
    constrainPosition();

    _sprite.setPosition(_pos.x, _pos.y);
}
void Boid::separation(Vector2 *distances, int size)
{
    Vector2 close;
    close.x = 0;
    close.y = 0;
    float dist;

    for (int i = 0; i < size; i++)
    {
        float dx = _pos.x - distances[i].x;
        float dy = _pos.y - distances[i].y;
        dist = sqrt(dx * dx + dy * dy);
        if (dist < _sr)
        {
            close.x += _pos.x - distances[i].x;
            close.y += _pos.y - distances[i].y;
        }
        _dir.x += _sf * close.x;
        _dir.y += _sf * close.y;
    }
    dist = sqrt(_dir.x * _dir.x + _dir.y * _dir.y);
}
void Boid::alignment(Vector2 *dist, Vector2 *vel, int size)
{
    Vector2 avgVel;
    avgVel.x = 0;
    avgVel.y = 0;
    int neighbours = 0;

    for (int i = 0; i < size; i++)
    {
        if (getDist(dist[i]) < _ar)
        {
            avgVel.x += vel[i].x;
            avgVel.y += vel[i].y;
            neighbours++;
        }
    }
    if (neighbours > 0)
    {
        avgVel.x /= neighbours;
        avgVel.y /= neighbours;
        _dir.x += (avgVel.x - _dir.x) * _af;
        _dir.y += (avgVel.y - _dir.y) * _af;
    }
}
void Boid::cohesion(Vector2 *distances, int size)
{
    // Vector2 avgPos;
    // avgPos.x = 0;
    // avgPos.y = 0;
    // int neighbours = 0;

    // for (int i = 0; i < size; i++)
    // {
    // }
}
sf::CircleShape Boid::draw()
{
    return _sprite;
}
