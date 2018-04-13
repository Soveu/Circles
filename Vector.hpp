#include "Angle.hpp"
#include <cmath>
#include <SFML/Vector2.hpp>

// template <typename T>
// struct Coord{
//     T x;
//     T y;

//     Coord(T a, T b) : x(a), y(b);
//     Coord();
// };

class Vector : Angle, Vector2f{
protected:
    void vectorToXY();
public:
    int vectorValue;

    Vector(int, double, double, int);
    Vector(Angle, Vector2f, int);
    Vector(const Vector &);
    Vector(Angle, double, double, int);
    Vector(int, Vector2f, int);
    Vector();
};