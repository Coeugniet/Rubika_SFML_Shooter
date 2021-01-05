#pragma once

#include "Ennemy.h"

class EnnemyVertical : public Ennemy
{
public:
	EnnemyVertical(sf::Vector2f scale, float speed);
	~EnnemyVertical();
	void update(float deltaTime);
protected:
	sf::Clock _clock;
	sf::Time _time;
	float _speed;
};

