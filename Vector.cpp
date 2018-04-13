#include "Vector.hpp"

void Vector::vecToXY(){
    x = cos(angle * M_PI / 180) * vectorValue;
    y = sin(angle * M_PI / 180) * vectorValue;
}

//Constructors

Vector::Vector() : vectorValue(0) {};
Vector::Vector(const int& x, const Angle& a) :
    vectorValue(x),
    Angle(a) {
        vecToXY();
    };

Vector::Vector(const Vector& v){
    angle = v.angle;
    vectorValue = v.vectorValue;
    x = v.x;
    y = v.y;
}