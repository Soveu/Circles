#include <cstdint>

class Angle{
protected:
    int16_t angle;
public:
    void setDegree(int);
    void setRadian(double);
    
    static int Degree(Angle);
    static double Radian(Angle);

    Angle(int);
    Angle(double);
    Angle();
    Angle(const Angle&);
}