#define _USE_MATH_DEFINES
#define DOUBLE_PI 6.283185307179586

#include <cmath>
#include "Angle.hpp"

int Angle::Degree(Angle a){
    return a.angle;
}

double Angle::Radian(Angle a){
    return a.angle * M_PI / 180;
}

void Angle::setDegree(int a){
    if (a < 0){
        angle = (360 + a) % 360;
    } else {
        angle = a % 360;
    }
}

void Angle::setRadian(double a){
    if (a < 0){
        angle = fmod((DOUBLE_PI - a), DOUBLE_PI);
    } else {
        angle = fmod(a, DOUBLE_PI);
    }
}

//Construcors

Angle::Angle() : angle(0){}; //default constructor
Angle::Angle(int x) : angle(x){}; //please use 0-359
Angle::Angle(double x) : angle(x){}; //WARNING -> constructor for radians
Angle::Angle(const Angle& a) : angle(a.angle){}; //copy constructor