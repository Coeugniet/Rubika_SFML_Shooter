#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "SpaceShip.h"
#include "Bullet.h"

class RedBullet : public Bullet
{
public:
	RedBullet(sf::Vector2f scale, SpaceShip* shooter, sf::Vector2f direction, float speed, float x, float y);
	~RedBullet();

	void virtual collisionsTest();
};

