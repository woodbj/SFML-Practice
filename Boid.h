#ifndef BOID_H
#define BOID_H
#include <SFML/System/Vector2.hpp>
using sf::Vector2f;

typedef enum BoidType{
    PREY,
    PREDATOR
} BoidType;

class Boid
{
private:
    /* data */
public:
    virtual void update(Vector2f*, Vector2f*, BoidType*, int) = 0;
    virtual Vector2f getPos() = 0;
    virtual Vector2f getVel() = 0;
    virtual BoidType getBoidType() = 0;
    virtual void draw() = 0;
};


#endif