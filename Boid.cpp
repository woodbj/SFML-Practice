#include "Boid.h"

// https://people.ece.cornell.edu/land/courses/ece4760/labs/s2021/Boids/Boids.html#:~:text=Boids%20is%20an%20artificial%20life,very%20simple%20set%20of%20rules.

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
    _sprite = sf::CircleShape(5.f);
    if (id == 0)
    {
        _sprite.setFillColor(sf::Color::Magenta);
    }
    _sprite.setPosition(_pos.x, _pos.y);
}

void Boid::normaliseVelocity()
{
    float vel = sqrt(_dir.x * _dir.x + _dir.y * _dir.y);
    _dir.x /= vel;
    _dir.y /= vel;
    _dir.x *= _maxVel;
    _dir.y *= _maxVel;
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

void Boid::scaleVector(Vector2 *v, float len)
{
    float vel = sqrt(v->x * v->x + v->y * v->y);
    v->x /= vel;
    v->y /= vel;
    v->x *= len;
    v->y *= len;
}

void Boid::drawVelocity(Vector2 pos, Vector2 vel)
{
    scaleVector(&vel, 50);
    sf::VertexArray lines(sf::LinesStrip, 2);
    lines[0].position = sf::Vector2f(pos.x + 10, pos.y + 10);
    lines[1].position = sf::Vector2f(pos.x + vel.x, _pos.y + vel.y);
    _window->draw(lines);
}

void Boid::update(Vector2 *positions, Vector2 *velocities, int size)
{
    separation(positions, size);
    alignment(positions, velocities, size);
    cohesion(positions, size);

    _pos.x += _dir.x;
    _pos.y += _dir.y;

    normaliseVelocity();
    constrainPosition();

    _sprite.setPosition(_pos.x, _pos.y);
}

void Boid::separation(Vector2 *positions, int size)
{
    Vector2 close;
    close.x = 0;
    close.y = 0;

    for (int i = 0; i < size; i++)
    {
        float dx = _pos.x - positions[i].x;
        float dy = _pos.y - positions[i].y;
        float dist = sqrt(dx * dx + dy * dy);
        if (dist < _sr)
        {
            close.x += _pos.x - positions[i].x;
            close.y += _pos.y - positions[i].y;
        }
        _dir.x += _sf * close.x;
        _dir.y += _sf * close.y;
    }
}

void Boid::alignment(Vector2 *positions, Vector2 *vel, int size)
{
    if (!_align)
        return;
    Vector2 avgVel;
    avgVel.x = 0;
    avgVel.y = 0;
    int neighbours = 0;

    for (int i = 0; i < size; i++)
    {
        float dx = _pos.x - positions[i].x;
        float dy = _pos.y - positions[i].y;
        float dist = sqrt(dx * dx + dy * dy);
        if (dist < _ar)
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

void Boid::cohesion(Vector2 *positions, int size)
{
    if (!_cohere)
        return;
    Vector2 avgPos;
    avgPos.x = 0;
    avgPos.y = 0;
    int neighbours = 0;

    for (int i = 0; i < size; i++)
    {
        float dx = _pos.x - positions[i].x;
        float dy = _pos.y - positions[i].y;
        float dist = sqrt(dx * dx + dy * dy);
        if (dist < _cr)
        {
            avgPos.x += positions[i].x;
            avgPos.y += positions[i].y;
            neighbours++;
        }
    }
    if (neighbours > 0)
    {
        avgPos.x /= neighbours;
        avgPos.y /= neighbours;
        _dir.x += (_pos.x - avgPos.x) * _cf;
        _dir.y += (_pos.y - avgPos.y) * _cf;

        // if (_id == 0)
        // {
        //     sf::CircleShape centre = sf::CircleShape(10.f);
        //     centre.setFillColor(sf::Color::Green);
        //     centre.setPosition(avgPos.x, avgPos.y);
        //     _window->draw(centre);
        // }
    }
}

sf::CircleShape Boid::draw()
{
    return _sprite;
}
