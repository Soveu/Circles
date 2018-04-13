#include "Vector.hpp"

#include <ctime>

class MovableObj{
protected:
    clock_t timePoint;
    Vector speedVec;
public:
    virtual static bool isColliding();
    virtual void collisionAction();

    virtual void move() = 0;
    void timeSync();

    MovableObj();
    MovableObj(const MovableObj&);
    MovableObj(const Vector&);
}