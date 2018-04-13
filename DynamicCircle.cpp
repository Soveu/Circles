#include "DynamicCircle.h"

void DynamicCircle::convertVectorToXY()
{
	horizontalSpeed = cos(vectorAngle * 3.14159265359 / 180) * vectorSpeed;
	verticalSpeed = sin(vectorAngle * 3.14159265359 / 180) * vectorSpeed;
}

void DynamicCircle::changeAngle(int a)
{
	if (a < 0) vectorAngle = 360 + (a % 360);
	else vectorAngle = a % 360;
}

void DynamicCircle::move()
{		
	deltaTime = clock() - timePoint;
	kolo.move(deltaTime * horizontalSpeed / CLOCKS_PER_SEC, deltaTime * verticalSpeed / CLOCKS_PER_SEC);

	timePoint = clock();
}

void DynamicCircle::drawObj()
{
	w->draw(kolo);
}

void DynamicCircle::ObjectCollision(int a)
{
	changeAngle(rand() % 120 + a + 60);
	//std::cout << "int a: " << a << " vectorAngle: " << vectorAngle << std::endl <<  std::endl;
	convertVectorToXY();
}

void DynamicCircle::WallCollision()
{
	if ((kolo.getRadius() >= kolo.getPosition().x) && (vectorAngle < 270 || vectorAngle > 90)) {
		changeAngle(180 - vectorAngle); convertVectorToXY(); 
	}
	if ((kolo.getPosition().x + kolo.getRadius() >= w->getSize().x) && (vectorAngle > 270 || vectorAngle < 90)) {
		changeAngle(180 - vectorAngle); convertVectorToXY(); 
	} 

	
	if ((kolo.getRadius() >= kolo.getPosition().y) && (vectorAngle > 180)) {
		changeAngle(360 - vectorAngle); convertVectorToXY(); 
	}
	if ((kolo.getPosition().y + kolo.getRadius() >= w->getSize().y) && (vectorAngle < 180)) {
		changeAngle(360 - vectorAngle); convertVectorToXY(); 
	}
}

/*void DynamicCircle::debug()
{
	//std::cout << kolo.getPosition().x << " " << kolo.getPosition().y << std::endl;
	//std::cout << w->getSize().x << " " << w->getSize().y << std::endl;
}*/

DynamicCircle::DynamicCircle(int radius, int posx, int posy, int vspeed, int vangle, sf::RenderWindow* wpoint)
{
	kolo.setRadius(radius);
	kolo.setOrigin(radius, radius);
	kolo.setPosition(posx, posy);
	kolo.setFillColor(sf::Color(
		rand() % 127 + 127, 
		rand() % 127 + 127, 
		rand() % 127 + 127)
	);

	changeAngle(vangle);
	vectorSpeed = vspeed;
	convertVectorToXY();

	timePoint = clock();
	w = wpoint;
}


DynamicCircle::~DynamicCircle()
{
}

sf::CircleShape* DynamicCircle::getCircle() {
	return &kolo;
}
