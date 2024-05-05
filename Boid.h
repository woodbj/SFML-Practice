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
    sf::RenderWindow* _window;
    int _width;
    int _height;
    int _id;
    float _maxVel = 5;
    // Separation
    float _sr = 25.f;
    float _sf = 0.0005f;
    // Alignment
    float _ar = 100.f;
    float _af = 0.05f;
    // Cohesion
    float _cr = 100;
    float _cf = 0.005;

    void normaliseVelocity();
    void constrainPosition();
    float getDist(Vector2);

public:
    Boid(int, int, int, sf::RenderWindow *);
    float getxPos() { return _pos.x; }
    float getyPos() { return _pos.y; }
    float getxVel() { return _dir.x; }
    float getyVel() { return _dir.y; }
    void setDir(Vector2 dir) { _dir = dir; }
    void update(Vector2 *distances, Vector2 *velocities, int count);
    void separation(Vector2 *distances, int count);
    void alignment(Vector2 *dist, Vector2 *vel, int size);
    void cohesion(Vector2 *distances, int count);

    sf::CircleShape draw();
};

#endif