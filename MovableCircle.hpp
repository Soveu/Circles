#include "MovableShape.hpp"
#include <SFML/CircleShape.hpp>
#include <cmath>

class MovableCircle : MovableShape, sf::CircleShape{
public:
    static bool isColliding(const sf::CircleShape&, const sf::CircleShape&);
    void collisionAction(const Angle&); //argument is collision angle

    MovableCircle();
    MovableCircle(const MovableShape&, const sf::CircleShape&);
    MovableCircle(const MovableCircle&);
}