#include "Vector.hpp"

void Vector::vecToXY(){
    x = cos(angle * M_PI / 180) * vectorValue;
    y = sin(angle * M_PI / 180) * vectorValue;
}

void Vector::setDegree(int a){
    if (a < 0){
        angle = (360 + a) % 360;
    } else {
        angle = a % 360;
    }
    vecToXY();
}

void Vector::setRadian(double a){
    if (a < 0){
        angle = fmod((DOUBLE_PI - a), DOUBLE_PI);
    } else {
        angle = fmod(a, DOUBLE_PI);
    }
    vecToXY();
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