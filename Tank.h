#pragma once
#include "header.h"

class Tank
{
private:
	double baseAngle;
	double cannonAngle;
	sf::RectangleShape base;
	sf::RectangleShape cannon;
public:
	Tank(int x, int y);
	void setBaseAngle();
	void move(double speed, int dir);
	void rotate(int dir);
	void rotateCannon(int dir);
	void setCannonAngle();
	sf::RectangleShape getBase();
	sf::RectangleShape getCannon();
};

