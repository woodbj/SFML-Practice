#ifndef BOID_H
#define BOID_H
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>

using sf::Vector2f;

class Boid
{
private:
    Vector2f _pos;
    Vector2f _dir;
    sf::CircleShape _sprite;
    int _width;
    int _height;
    int _id;
    // Separation
    float _separationRange = 100.f;
    float _avoidFactor = 0.001f;
    // Alignment
    float _alignemntRange = 200.f;
    float _matchingFactor = 0.2f;


public:
    Boid(int, int, int);
    Vector2f getPos(){return _pos;}
    Vector2f getDir(){return _dir;}
    void setDir(Vector2f dir){_dir = dir;}
    void update(Vector2f *distances, Vector2f *velocities, int count);
    void separation(Vector2f *distances, int count);
    void alignment(Vector2f *distances, int count);
    void cohesion(Vector2f *distances, int count);

    sf::CircleShape draw();
};




#endif