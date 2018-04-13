#include "Vector.hpp"

#include <ctime>

class MovableObj : Vector{
protected:
    clock_t timePoint;
public:
    virtual bool isColliding();
    virtual void collisionAction();

    void move();

    MovableObj();
}