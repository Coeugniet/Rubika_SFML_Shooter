#pragma once

#include "SpaceShip.h"

class Player : public SpaceShip
{
public:
	Player(sf::Vector2f scale, float x, float y);
	~Player();

	void update(float deltaTime);
	void shoot();
	void setPosition(float x, float y);
	void virtual collisionsTest();
	void reset();

	sf::Vector2f getOrigin() { return _sprite.getOrigin(); }

private:
	float _speed;
};

