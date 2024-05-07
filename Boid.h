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
    sf::RenderWindow *_window;
    int _width;
    int _height;
    int _id;
    float _maxVel = 3;
    float _boidSize = 1;
    // Separation
    bool _separate = true;
    float _sr = 50;  // separation range
    float _sf = 0.0005f;        // separation factor
    // Alignment
    bool _align = true;
    float _ar = 350.f;          // alignment range
    float _af = 0.02f;          // alignment factor
    // Cohesion
    bool _cohere = true;
    float _cr = _ar;            // cohesion range
    float _cf = 0.00005f;       // cohesion factor
    // Margins
    float _ml = 100;             // margin to turn from
    float _mr;
    float _mt;
    float _mb;
    float _tf = 0.2;            // turn factor

    void scaleVector(Vector2f *, float scale);
    void constrainPosition();
    float getMagnitude(Vector2f);

public:
    Boid(int, sf::RenderWindow *);
    Vector2f getPos() { return _pos; }
    Vector2f getVel() { return _dir; }
    void setDir(Vector2f dir) { _dir = dir; }
    void update(Vector2f *distances, Vector2f *velocities, int count);
    void separation(Vector2f *distances, int count);
    void alignment(Vector2f *dist, Vector2f *vel, int size);
    void cohesion(Vector2f *distances, int count);
    void margins();
    void toggleSeparation() { _separate = !_separate; }
    void toggleAlignment() { _align = !_align; }
    void toggleCohesion() { _cohere = !_cohere; }
    void draw();
};

#endif