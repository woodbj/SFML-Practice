#ifndef BOID_H
#define BOID_H
#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>

class Boid
{
private:
    Vector2 _pos;
    Vector2 _dir;
    sf::CircleShape _sprite;
    int _width;
    int _height;
    int _id;
    // Separation
    float _separationRange = 50.f;
    float _avoidFactor = 0.001f;
    // Alignment
    float _alignemntRange = 200.f;
    float _matchingFactor = 0.2f;

public:
    Boid(int, int, int);
    float getxPos() { return _pos.x; }
    float getyPos() { return _pos.y; }
    float getxVel() { return _dir.x; }
    float getyVel() { return _dir.y; }
    void setDir(Vector2 dir) { _dir = dir; }
    void update(Vector2 *distances, Vector2 *velocities, int count);
    void update();
    void separation(Vector2 *distances, int count);
    void alignment(Vector2 *distances, int count);
    void cohesion(Vector2 *distances, int count);

    sf::CircleShape draw();
};

#endif