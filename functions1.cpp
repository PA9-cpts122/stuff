#include "Tank.h"
void fire(double x, double y, double r, sf::CircleShape ball1)
{
	
	ball1.setFillColor(sf::Color::White);
	ball1.setPosition(x, y);
	int x2 = ball1.getPosition().x, y2 = ball1.getPosition().y;
	while ((x2 > 0 && x2 < 1280) && (y2 > 0 && y2 < 720))
	{
		ball1.move(::cos(r), ::sin(r));
		x2 = ball1.getPosition().x;
		y2 = ball1.getPosition().y;
	}
}