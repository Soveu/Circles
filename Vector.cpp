#include "Vector.hpp"

void Vector::vectorToXY(){
    x = cos(_angle * M_PI / 180) * vectorValue;
    y = sin(_angle * M_PI / 180) * vectorValue;
}