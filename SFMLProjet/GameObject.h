#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
//#include "GameEngine.h"

using namespace std;

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	int virtual loadSprite(string filePath);
	void virtual render(sf::RenderWindow &window);
	void virtual setPosition(float x, float y);
	void virtual collisionsTest() = 0;
	void virtual update(float deltaTime);

	float getX() { return _position.x; }
	float getY() { return _position.y; }
	bool isActive() { return _active; }
	void setActive(bool value) { _active = value; }
	sf::FloatRect getGlobalBounds() { return _sprite.getGlobalBounds(); }

protected:
	sf::Sprite _sprite;
	sf::Texture _texture;
	sf::Vector2f _position;
	bool _active;
};

