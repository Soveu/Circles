#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <ctime>

#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>

class DynamicCircle
{
private:
	sf::CircleShape kolo;

	float verticalSpeed;
	float horizontalSpeed;

	int vectorSpeed;
	int vectorAngle;

	clock_t timePoint;

	void convertVectorToXY();
	clock_t deltaTime;
protected:
	sf::RenderWindow* w;
public:
	void changeAngle(int);
	void move();
	void drawObj();
	void ObjectCollision(int);
	void WallCollision();
	
	sf::CircleShape* getCircle();

	//void debug();

	DynamicCircle(int, int, int, int, int, sf::RenderWindow*);
	~DynamicCircle();
};

