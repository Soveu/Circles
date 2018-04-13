#include "MovableShape.hpp"
#include <SFML/CircleShape.hpp>

class MovableCircle : MovableShape, sf::CircleShape{
public:
    static bool isColliding(sf::CircleShape, sf::CircleShape);
    void collisionAction(Angle); //argument is collision angle

    MovableCircle();
    MovableCircle(const MovableShape&, const sf::CircleShape&);
    MovableCircle(const MovableCircle&);
}