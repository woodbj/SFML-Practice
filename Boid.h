#ifndef BOID_H
#define BOID_H
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <iostream>
#include <ctime>

using sf::Vector2f;

class Boid
{
private:
    Vector2f _pos;
    Vector2f _dir;
    sf::CircleShape _sprite;
    int _width;
    int _height;

public:
    Boid(int, int);
    ~Boid();
    void update();
    Vector2f getPos(){return _pos;}
    void setDir(Vector2f dir){_dir = dir;}
    sf::CircleShape draw();
};




#endif