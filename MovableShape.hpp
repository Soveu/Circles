#include "MovableObj.hpp"
#include <SFML/Shape.hpp>
#include <ctime>

class MovableShape : sf::Shape, MovableObj{
public:
    void move();
    
    MovableShape();
    MovableShape(const sf::Shape&, const MovableObj&);
    //MovableShape(const MovableShape&); //TODO
}