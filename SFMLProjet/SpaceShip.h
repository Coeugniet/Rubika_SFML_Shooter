#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "GameObject.h"

using namespace std;

class SpaceShip : public GameObject
{
public:
	SpaceShip();
	~SpaceShip();
	virtual void shoot() = 0;
	virtual void update(float deltaTime);
	void setPosition(float x, float y);
	void die(float deltaTime);

	void setAlive(bool value) { _alive = value; }
	bool isAlive() { return _alive; }

protected:
	sf::Clock _clock;
	sf::Time _lastShoot;
	float _shootRate;
	bool _alive;
};

