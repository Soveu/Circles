#include "MovableObj.hpp"

void MovableObj::timeSync(){
    timePoint = clock();
}

//Constructors

MovableObj::MovableObj() {};
MovableObj::MovableObj(const MovableObj& m) :
    speedVec(m.speedVec) {};
MovableObj::MovableObj(const Vector& v) :
    speedVec(v) {};