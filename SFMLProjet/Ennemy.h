#pragma once

#include "SpaceShip.h"

class Ennemy : public SpaceShip
{
public:
	~Ennemy();
	void virtual update(float deltaTime) = 0;
	void virtual collisionsTest();
	void shoot();

protected:
	Ennemy(sf::Vector2f scale);
};

