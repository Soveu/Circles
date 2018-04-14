#include "Angle.hpp"
#include <cmath>
#include <SFML/Vector2.hpp>

typedef Vector2<double> Vector2d;

class Vector : Angle, Vector2d{
protected:
    int vectorValue;
    //Vector2d vals; //vector splitted to X and Y coordinates

    void vecToXY();
public:
    void setDegree(int);
    void setRadian(double);

    Vector();
    Vector(const int&, const Angle&);
    Vector(const Vector&);
};