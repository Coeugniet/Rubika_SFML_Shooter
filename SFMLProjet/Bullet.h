#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "SpaceShip.h"

using namespace std;

class Bullet : public GameObject
{
public:
	~Bullet();

	void virtual update(float deltaTime);

protected:
	Bullet(sf::Vector2f scale, SpaceShip* shooter, sf::Vector2f direction, float speed, float x, float y);

	sf::Vector2f _direction;
	float _speed;
	SpaceShip* _shooter;
};

