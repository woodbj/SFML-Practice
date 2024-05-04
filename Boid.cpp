#include "Boid.h"

Boid::Boid(int width, int height)
{
    _width = width;
    _height = height;
    _pos.x = rand() % _width;
    _pos.y = rand() % _height;
    _dir.x = 2 * rand() / (1.f * RAND_MAX) - 1;
    _dir.y = 2 * rand() / (1.f * RAND_MAX) - 1;
    _sprite = sf::CircleShape(10.f);
    _sprite.setPosition(_pos);
    // std::cout << "New Boid x " << _pos.x << " y " << _pos.y << " vx " << _dir.x << " vy " << _dir.x << '\n';
}

Boid::~Boid()
{
}

void Boid::update()
{
    // _pos.x += _dir.x;
    _pos += _dir;
    // _pos.x++;

    if (_pos.x > _width) _pos.x -= _width;
    if (_pos.y > _height) _pos.y -= _height;
    if (_pos.x < 0) _pos.x += _width;
    if (_pos.y < 0) _pos.y += _height;

    _sprite.setPosition(_pos);
}

sf::CircleShape Boid::draw()
{
    return _sprite;
}
