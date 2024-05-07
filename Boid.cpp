#include "Boid.h"

// https://people.ece.cornell.edu/land/courses/ece4760/labs/s2021/Boids/Boids.html#:~:text=Boids%20is%20an%20artificial%20life,very%20simple%20set%20of%20rules.

Boid::Boid(int id, sf::RenderWindow *window)
{
    // initialise variables
    _id = id;
    _window = window;
    _width = _window->getSize().x;
    _height = _window->getSize().y;

    // initialise position
    _pos.x = rand() % _width;
    _pos.y = rand() % _height;
    _dir.x = 2 * (rand() / (1.f * RAND_MAX)) - 1;
    _dir.y = 2 * (rand() / (1.f * RAND_MAX)) - 1;
    float velocity = rand() / (1.f * RAND_MAX);
    scaleVector(&_dir, velocity * _maxVel);

    // initialise boundaries
    _mr = _width - _ml;
    _mt = _ml;
    _mb = _height - _ml;

    // give a shape
    _sprite = sf::CircleShape(_boidSize);
}

float Boid::getMagnitude(Vector2f v)
{
    return sqrt(v.x * v.x + v.y * v.y);
}

void Boid::update(Vector2f *positions, Vector2f *velocities, int size)
{
    separation(positions, size);
    alignment(positions, velocities, size);
    cohesion(positions, size);

    

    margins();

    scaleVector(&_dir, _maxVel);

    _pos += _dir;

    draw();
}

void Boid::separation(Vector2f *positions, int size)
{
    Vector2f close;
    for (int i = 0; i < size; i++)
    {
        if (getMagnitude(_pos - positions[i]) < _sr)
        {
            close += _pos - positions[i];
        }
        _dir += _sf * close;
    }
}

void Boid::alignment(Vector2f *positions, Vector2f *vel, int size)
{
    if (!_align)
        return;
    Vector2f avgVel;
    int neighbours = 0;

    for (int i = 0; i < size; i++)
    {
        if (getMagnitude(_pos - positions[i]) < _ar)
        {
            avgVel += vel[i];
            neighbours++;
        }
    }
    if (neighbours > 0)
    {
        avgVel /= (float)neighbours;
        _dir += (avgVel - _dir) * _af;
    }
}

void Boid::cohesion(Vector2f *positions, int size)
{
    if (!_cohere)
        return;

    Vector2f avgPos;
    int neighbours = 0;

    for (int i = 0; i < size; i++)
    {
        if (getMagnitude(_pos - positions[i]) < _cr)
        {
            avgPos += positions[i];
            neighbours++;
        }
    }
    if (neighbours > 0)
    {
        avgPos /= (float)neighbours;
        _dir += -(_pos - avgPos) * _cf;
    }
}

void Boid::margins()
{
    // Vector2f tl(_ml, _mt);
    // Vector2f tr(_mr, _mt);
    // Vector2f bl(_ml, _mb);
    // Vector2f br(_mr, _mb);

    // sf::VertexArray lines(sf::LinesStrip, 5);
    // lines[0].position = tl;
    // lines[1].position = tr;
    // lines[2].position = br;
    // lines[3].position = bl;
    // lines[4].position = tl;

    // _window->draw(lines);

    if (_pos.x < _ml)
        _dir.x += _tf;
    if (_pos.x > _mr)
        _dir.x -= _tf;
    if (_pos.y > _mb)
        _dir.y -= _tf;
    if (_pos.y < _mt)
        _dir.y += _tf;
}

void Boid::scaleVector(Vector2f *v, float scale)
{
    *v /= (float)sqrt(v->x * v->x + v->y * v->y);
    *v *= scale;
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

void Boid::draw()
{
    _sprite.setPosition(_pos.x, _pos.y);
    _window->draw(_sprite);
}
