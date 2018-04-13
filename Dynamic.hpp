#include <ctime>

#include "Angle.hpp"

class Dynamic{
private:
	double _verticalSpeed;
	double _horizontalSpeed;

	int _vectorSpeed;
	Angle _vectorAngle;

	clock_t _timePoint;
	clock_t _deltaTime;

    void _vectorToXY();
};