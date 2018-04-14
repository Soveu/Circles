#include "MovableShape.hpp"

void MovableShape::move(){
    clock_t deltaTime;
    
    m_position.x = deltaTime * speedVec.x / CLOCKS_PER_SEC;
    m_position.y = deltaTime * speedVec.y / CLOCKS_PER_SEC;
}

//Constructors

MovableShape::MovableShape() {};

MovableShape::MovableShape(const sf::Shape& s, const MovableObj& m) :
    sf::Shape(s),
    MovableObj(m) {};

MovableShape::MovableShape(const MovableShape& ms) :
    MovableObj(ms.speedVec),
    sf::Shape() {};