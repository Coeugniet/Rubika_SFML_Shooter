#pragma once

#include "Ennemy.h"

class EnnemyHorizontal : public Ennemy
{
public:
	EnnemyHorizontal(sf::Vector2f scale, float speed);
	~EnnemyHorizontal();
	void update(float deltaTime);
protected:
	sf::Clock _clock;
	sf::Time _time;
	float _speed;
};

