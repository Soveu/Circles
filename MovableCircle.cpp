#include "MovableCircle.hpp"

static bool 
MovableCircle::isColliding(const sf::CircleShape& a, 
    const sf::CircleShape& b)
{
    return (pow(a.m_position.x - b.m_position.x, 2) + 
    pow(a.m_position.y - b.m_position.y, 2)) <= 
    pow(a.m_radius + b.m_radius, 2);
}

void
MovableCircle::collisionAction(const Angle& a){
    speedVec.setDegree(Angle.Degree(a) + rand() % 120 + 60);
}

//Constructors

MovableCircle::MovableCircle() :
    MovableShape(),
    sf::CircleShape() {};

MovableCircle::MovableCircle(const MovableShape& m, 
    const sf::CircleShape& c) :
    MovableShape(m),
    sf::CircleShape(c) {};

MovableCircle::MovableCircle(const MovableCircle& mc) :
    speedVec(mc.speedVec),
    sf::CircleShape(mc.m_radius) {};