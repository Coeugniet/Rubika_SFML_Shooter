#pragma once

#include<list>
#include "Ennemy.h"
#include <vector>

class EnnemyPack
{
public:
	EnnemyPack(sf::Vector2f scale, string schema, float ennemyWidth, float ennemyHeight, float ennemySpeed, float speed);
	~EnnemyPack();
	void update(float deltaTime);
	void render(sf::RenderWindow& window);
	list<Ennemy*>* getEnnemys() { return &_ennemys; }
	bool isEmpty() { return _ennemys.empty(); }
	void clean();

protected:
	list<Ennemy*> _ennemys;
	float _speed;
	const static int _schemas[7][3][3];
};

