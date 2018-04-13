#include "DynamicCircle.h"

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

bool isCircleColliding(sf::CircleShape* A, sf::CircleShape* B) {
	return (pow(A->getPosition().x - B->getPosition().x, 2) + pow(A->getPosition().y - B->getPosition().y, 2)) <= pow(A->getRadius() + B->getRadius(), 2);
}

int collisionAngle(sf::CircleShape* A, sf::CircleShape* B) {
	/*atan zwraca wartosci od radianu kata -90 do 90 i ten fragment kodu "poszerza" to do 360 stopni (tak, zeby pasowalo do reszty programu)*/
	float ax = A->getPosition().x;
	float ay = A->getPosition().y;
	float bx = B->getPosition().x;
	float by = B->getPosition().y;

	if (ax >= bx && ay >= by) {
		return 180 + (atan((ay - by) / (ax - bx)) * 180 / 3.14159265359);
	}
	else if (ax >= bx && ay <= by) {
		return 90 + (atan((ax - bx) / (by - ay)) * 180 / 3.14159265359);
	}
	else if (ax <= bx && ay >= by) {
		return 360 - (atan((ay - by) / (bx - ax)) * 180 / 3.14159265359);
	}
	else {
		return 90 - (atan((bx - ax) / (by - ay)) * 180 / 3.14159265359);
	}
}

int main()
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(1280, 720, 32), "Praca na szesc", sf::Style::Close); 
	//window.setFramerateLimit(120);
	
	sf::Event zdarzenie;

	std::vector <DynamicCircle> Kola;
	Kola.push_back(DynamicCircle(50, 300, 300, 200, 120, &window));
	Kola.push_back(DynamicCircle(100, 500, 500, 100, 300, &window));

	while (window.isOpen()) {
		window.clear(sf::Color::Black);
		
		while (window.pollEvent(zdarzenie)) {
			if (zdarzenie.type == sf::Event::Closed) window.close(); //zamykanie okna
		}

		for (int i = 0; i < Kola.size(); ++i) 
		{ 
			Kola[i].WallCollision(); //powoduje kolizje ze scianami okna
			
			for (int j = 0; j < Kola.size(); ++j) { //sprawdza czy nie zachodzi kolizja z innymi objektami (kolami)
				if (j != i) {
					if (isCircleColliding(Kola[i].getCircle(), Kola[j].getCircle())) { 
						Kola[i].ObjectCollision(collisionAngle(Kola[i].getCircle(), Kola[j].getCircle()));
						Kola[j].ObjectCollision(collisionAngle(Kola[j].getCircle(), Kola[i].getCircle()));
						break;
					}
				}
			}


			Kola[i].move(); //funkcja odpowiadajaca za ruch objektu
			Kola[i].drawObj();  //funkcja rysujaca objekt
		}

		window.display();
	}
	
	return 0;
}

