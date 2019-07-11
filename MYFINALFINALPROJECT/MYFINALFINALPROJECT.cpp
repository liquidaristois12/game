// MYFINALFINALPROJECT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp> 
using namespace std;

sf::Vector2f velocity(0, 0);


const int WIDTH = 1000, HEIGHT = 800;

int Scoreboard = 0;
int HighScore = 0;


sf::Texture playerTex;
sf::Texture upTex;
sf::Texture downTex;
sf::Text myText;
sf::Texture backgroundTex;
sf::Texture aboveTex;
sf::Texture belowTex;
sf::Texture lupTex;
sf::Texture ldownTex;


void jump()
{
	velocity.y = -1;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Flappy Astronaut!");

	playerTex.loadFromFile("Textures/PixelArt.png");
	upTex.loadFromFile("Textures/up.png");
	downTex.loadFromFile("Textures/down.png");
	backgroundTex.loadFromFile("Textures/space.png");
	aboveTex.loadFromFile("Textures/up2.png");
	belowTex.loadFromFile("Textures/down2.png");
	lupTex.loadFromFile("Textures/above3.png");
	ldownTex.loadFromFile("Textures/below3.png");

	bool movingRight = false;


	sf::Font myFont;
	myFont.loadFromFile("Fonts/Candal.ttf");


	sf::Sprite ldownSprite;
	ldownSprite.setTexture(ldownTex);
	ldownSprite.setScale(0.8, 0.8);
	ldownSprite.setOrigin(0, 350);
	ldownSprite.setPosition(950, HEIGHT);


	sf::Sprite lupSprite;
	lupSprite.setTexture(lupTex);
	lupSprite.setPosition(850, 0);
	lupSprite.setScale(0.8, 0.8);

	sf::Sprite belowSprite;
	belowSprite.setTexture(belowTex);
	belowSprite.setOrigin(0, 337);
	belowSprite.setScale(0.8, 0.8);
	belowSprite.setPosition(400, HEIGHT);


	sf::Sprite aboveSprite;
	aboveSprite.setTexture(aboveTex);
	aboveSprite.setPosition(400, 0);
	aboveSprite.setScale(0.7, 0.7);


	myText.setFont(myFont);
	myText.setCharacterSize(40);
	myText.setFillColor(sf::Color::Yellow);
	myText.setPosition(650, 0);

	sf::Sprite backgroundSprite;
	backgroundSprite.setTexture(backgroundTex);
	backgroundSprite.setOrigin(0, 0);
	backgroundSprite.setScale(3, 3);

	sf::Sprite upSprite;
	upSprite.setTexture(upTex);
	upSprite.setScale(0.5, 0.5);

	sf::Sprite downSprite;
	downSprite.setTexture(downTex);
	downSprite.setScale(0.5, 0.5);
	downSprite.setOrigin(0, 337);
	downSprite.setPosition(0, HEIGHT);

	sf::Sprite playerSprite;
	playerSprite.setTexture(playerTex);
	playerSprite.setScale(0.5, 0.5);
	playerSprite.setPosition(100, HEIGHT / 2);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::W) {
					jump();
				}
			}

		}

		myText.setString("Score: " + std::to_string(Scoreboard) +"\nHigh Score: " + std::to_string(HighScore));


		if (
			playerSprite.getGlobalBounds().intersects(upSprite.getGlobalBounds()) ||
			playerSprite.getGlobalBounds().intersects(downSprite.getGlobalBounds()) ||
			playerSprite.getGlobalBounds().intersects(aboveSprite.getGlobalBounds()) ||
			playerSprite.getGlobalBounds().intersects(lupSprite.getGlobalBounds()) ||
			playerSprite.getGlobalBounds().intersects(ldownSprite.getGlobalBounds()) ||
			playerSprite.getGlobalBounds().intersects(belowSprite.getGlobalBounds())
			) {
			playerSprite.setPosition(100, HEIGHT / 2);
			Scoreboard = 0;

		}




		velocity.y += 0.005;


		//if the astro is falling past the ground, make its velocity zero
		if (playerSprite.getPosition().y > HEIGHT && velocity.y > 0)
			velocity.y = 0;

		//apply the velocity to the ball
		playerSprite.move(velocity);

		upSprite.move(-1, 0);
		downSprite.move(-1, 0);
		aboveSprite.move(-1, 0);
		belowSprite.move(-1, 0);
		lupSprite.move(-1, 0);
		ldownSprite.move(-1, 0);

		upSprite.getPosition().x;
		downSprite.getPosition().x;
		aboveSprite.getPosition().x;
		belowSprite.getPosition().x;
		lupSprite.getPosition().x;
		ldownSprite.getPosition().x;

		if (ldownSprite.getPosition().x < -500)
			ldownSprite.move(WIDTH + 600, 0);

		if (belowSprite.getPosition().x < -500)
			belowSprite.move(WIDTH + 600, 0);

		if (lupSprite.getPosition().x < -500)
			lupSprite.move(WIDTH + 600, 0);

		if (upSprite.getPosition().x < -500)
			upSprite.move(WIDTH + 600, 0);

		if (aboveSprite.getPosition().x < -500)
			aboveSprite.move(WIDTH + 600, 0);

		if (downSprite.getPosition().x < -500) {
			Scoreboard++;
			if (Scoreboard > HighScore)
				HighScore = Scoreboard;
			downSprite.move(WIDTH + 600, 0);
		}



		window.clear();
		window.draw(backgroundSprite);
		window.draw(ldownSprite);
		window.draw(lupSprite);
		window.draw(belowSprite);
		window.draw(aboveSprite);
		window.draw(upSprite);
		window.draw(myText);
		window.draw(downSprite);
		window.draw(playerSprite);
		window.display();
	}
}