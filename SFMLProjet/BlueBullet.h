#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "SpaceShip.h"
#include "Bullet.h"

class BlueBullet : public Bullet
{
public:
	BlueBullet(sf::Vector2f scale, SpaceShip* shooter, sf::Vector2f direction, float speed, float x, float y);
	~BlueBullet();

	void virtual collisionsTest();
};

