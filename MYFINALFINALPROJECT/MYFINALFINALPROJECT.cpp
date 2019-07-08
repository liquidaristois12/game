// MYFINALFINALPROJECT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp> 
using namespace std;

sf::Vector2f velocity(0, 0);


const int WIDTH = 1000, HEIGHT = 800;

sf::Texture playerTex;
sf::Texture upTex;
sf::Texture downTex;

void jump()
{
	velocity.y = -1;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Jumping!");

	playerTex.loadFromFile("Textures/astronaut.jpg");
	upTex.loadFromFile("Textures/up.png");
	downTex.loadFromFile("Textures/down.png");


	sf::Sprite upSprite;
	upSprite.setTexture(upTex);
	upSprite.setScale(0.5, 0.5);

	sf::Sprite downSprite;
	downSprite.setTexture(downTex);
	downSprite.setScale(0.5, 0.5);
	downSprite.setOrigin(0, 832);
	downSprite.setPosition(0, HEIGHT);

	sf::Sprite playerSprite;
	playerSprite.setTexture(playerTex);
	playerSprite.setScale(0.3, 0.3);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::W) {
					//only jump when the ball is not moving (it's on the ground)
					//if (velocity.y == 0)
						jump();
				}
			}

		}
		//apply gravity to the velocity
		//you can change this number to change the falling speed
		velocity.y += 0.005;

		
		//if the astro is falling past the ground, make its velocity zero
		if (playerSprite.getPosition().y > HEIGHT / 2 && velocity.y > 0)
			velocity.y = 0;

		//apply the velocity to the ball
		playerSprite.move(velocity);

		window.clear();
		window.draw(upSprite);
		window.draw(downSprite);
		window.draw(playerSprite);
		window.display();
	}
}