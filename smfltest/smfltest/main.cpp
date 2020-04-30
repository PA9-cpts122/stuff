#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#define PI 3.14159265
int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Eric lol");
/*
	sf::RectangleShape player(sf::Vector2f(150, 200));
	player.setPosition(75, 350);
	player.setOrigin(75, 150);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("epic.png");
	player.setTexture(&playerTexture);
	
	sf::RectangleShape ground1(sf::Vector2f(350, 50));
	ground1.setFillColor(sf::Color::Green);
	ground1.setPosition(0, 400);

	sf::RectangleShape ground2(sf::Vector2f(350, 50));
	ground2.setFillColor(sf::Color::Green);
	ground2.setPosition(650, 400);
	*/
	/*
	sf::CircleShape ball1(30, 20);
	ball1.setFillColor(sf::Color::White);
	ball1.setPosition(100, 100);

	sf::CircleShape ball2(30, 20);
	ball2.setFillColor(sf::Color::White);
	ball2.setPosition(100, 40);

	sf::RectangleShape shaft(sf::Vector2f(300, 30));
	shaft.setFillColor(sf::Color::White);
	shaft.setPosition(130, 85);

	sf::CircleShape tip(15, 20);
	tip.setFillColor(sf::Color::White);
	tip.setPosition(415, 85);

	sf::CircleShape pee(30, 20);
	pee.setFillColor(sf::Color::Yellow);
	int x = 430, y = 85;
	pee.setPosition(x, y);
	float dy = 0;
	*/
	
	sf::RectangleShape base(sf::Vector2f(40, 50));
	base.setFillColor(sf::Color::Red);
	base.setOrigin(20, 25);
	base.setPosition(640, 360);

	sf::RectangleShape cannon(sf::Vector2f(10, 45));
	cannon.setFillColor(sf::Color::Yellow);
	cannon.setOrigin(5, 40);
	cannon.setPosition(640, 360);
	
	sf::Event event;
	double baseAngle = base.getRotation();
	float speed = .25;
	while (window.isOpen())
	{
		double baseAngle = (base.getRotation() * PI /180) + PI / 2;
		
		//Move the ball
		/*
		sf::Vector2f pPos = pee.getPosition();
		int dx = rand() % 3;

		pee.move(0, dy);
		dy += .001;
		//x = x + dx;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			pee.move(-0.1, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			pee.move(.1, 0);

		if (pPos.y > 720)
		{
			dy = 0;
			x = 430;
			y = 85;
			pee.setPosition(x, y);
			//window.clear();
		}
		*/
		/*sf::Vector2f playerPos = player.getPosition();
		//((playerPos.x >= -75 && playerPos.x <= 425) || (playerPos.x >= 575 && playerPos.x <= 925))
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			player.move(-0.2, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			player.move(.2, 0);
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			while (vel < 1)
			{
				player.move(0, vel);
				playerPos = player.getPosition();
				vel += .1;
			}
		}
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && playerPos.y == 350 && ((playerPos.x >= 0 && playerPos.x <= 350) || (playerPos.x >= 650 && playerPos.x <= 1000)))
		{
			double vel = 1;
			player.move(0, -vel);
			playerPos = player.getPosition();
			while (playerPos.y != 350)// || !((playerPos.x >= 0 && playerPos.x <= 350) || (playerPos.x >= 650 && playerPos.x <= 1000)))
			{
				vel -= .1;
				
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
					player.move(-0.2, -vel);
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
					player.move(.2, -vel);
				else
					player.move(0, -vel);
				playerPos = player.getPosition();
			}
		}
		*/
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			base.rotate(-.125);
			//printf(" %.2lf", base.getRotation());
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			base.rotate(.125);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			base.move(speed * ::cos(baseAngle), speed * ::sin(baseAngle));
			cannon.setPosition(base.getPosition());
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			base.move(speed * ::cos(baseAngle) * -1, speed * ::sin(baseAngle) * -1);
			cannon.setPosition(base.getPosition());
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			cannon.rotate(.125);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			cannon.rotate(-.125);
		}
			

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.clear();
		window.draw(base);
		window.draw(cannon);
		/*window.draw(ground1);
		window.draw(ground2);
		window.draw(player);
		/*
		window.draw(ball1);
		window.draw(shaft);
		window.draw(tip);
		window.draw(ball2);
		window.draw(pee);
		*/
		window.display();
	}
	return 0;
}