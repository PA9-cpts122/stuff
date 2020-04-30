#include "Tank.h"

void Tank::setBaseAngle()
{
	baseAngle = (base.getRotation() * PI / 180) + PI / 2;
}
void Tank::move(double speed, int dir)
{
	base.move(speed * ::cos(baseAngle) * dir, speed * ::sin(baseAngle) * dir);
	cannon.setPosition(base.getPosition());

}
void Tank::rotate(int dir)
{
	base.rotate(.125 * dir); 
}

void Tank::rotateCannon(int dir)
{
	cannon.rotate(.125 * dir);
}
void Tank::setCannonAngle()
{
	cannonAngle = (cannon.getRotation() * PI / 180) + PI / 2;
}
void Tank::draww(sf::RenderWindow window)
{
	window.draw(base);
	window.draw(cannon);
}
sf::RectangleShape Tank::getBase()
{
	return base;
}
sf::RectangleShape Tank::getCannon()
{
	return cannon;
}
Tank::Tank(int x, int y)
{
    base.setSize(sf::Vector2f(40,50));
	//sf::RectangleShape base(sf::Vector2f(40, 50));
	base.setFillColor(sf::Color::Red);
	base.setOrigin(20, 25);
	base.setPosition(x, y);

	cannon.setSize(sf::Vector2f(10, 45));
	cannon.setFillColor(sf::Color::Yellow);
	cannon.setOrigin(5, 40);
	cannon.setPosition(x, y);
	baseAngle = 0;
	cannonAngle = 0;
}