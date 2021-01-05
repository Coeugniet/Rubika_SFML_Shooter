#include "EnnemyPack.h"
#include "GameEngine.h"
#include "EnnemyVertical.h"
#include "EnnemyHorizontal.h"

const int EnnemyPack::_schemas[7][3][3] = { {
		{0, 1, 0},
		{1, 0, 1},
		{0, 1, 0}
}, {
		{1, 0, 1},
		{0, 0, 0},
		{1, 0, 1}
}, {
		{1, 0, 1},
		{0, 1, 0},
		{1, 0, 1}
}, {
		{0, 0, 0},
		{1, 1, 1},
		{0, 0, 0}
}, {
		{0, 1, 0},
		{0, 1, 0},
		{0, 1, 0}
}, {
		{1, 0, 1},
		{0, 0, 0},
		{0, 1, 0}
}, {
		{0, 0, 1},
		{1, 0, 0},
		{0, 0, 1}
} };

EnnemyPack::EnnemyPack(sf::Vector2f scale, string schema, float ennemyWidth, float ennemyHeight, float ennemySpeed, float speed) : _speed(speed) {
	float startx = GameEngine::getInstance()->getView().x;
	int starty = rand() % (int)(GameEngine::getInstance()->getView().y - (ennemyHeight * 3 + 50));

	double ennemyType = ((double)rand() / (RAND_MAX));

	int schemaId = rand() % (sizeof(_schemas) / sizeof(int)) / 9;
	if (schema == "diamond") schemaId = 0;
	if (schema == "square") schemaId = 1;
	if (schema == "cross") schemaId = 2;
	if (schema == "line") schemaId = 3;
	if (schema == "column") schemaId = 4;
	if (schema == "v") schemaId = 5;
	if (schema == "arrow") schemaId = 6;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (_schemas[schemaId][i][j] == 1) {
				Ennemy* e;
				if (ennemyType > 0.5) e = new EnnemyVertical(scale, ennemySpeed);
				else e = new EnnemyHorizontal(scale, ennemySpeed);
				e->setPosition(startx + i * (ennemyWidth + 10), starty + j * (ennemyHeight + 10));
				_ennemys.push_back(e);
			}
		}
	}
}

EnnemyPack::~EnnemyPack() {
	list<Ennemy*>::iterator it = _ennemys.begin();
	while (it != _ennemys.end()) {
		_ennemys.erase(it++);
	}
}

void EnnemyPack::update(float deltaTime) {
	list<Ennemy*>::iterator it = _ennemys.begin();
	while (it != _ennemys.end()) {
		(*it)->update(deltaTime);
		(*it)->setPosition((*it)->getX() - _speed * deltaTime, (*it)->getY());
		if (!(*it)->isActive()) _ennemys.erase(it++);
		else ++it;
	}
}

void EnnemyPack::render(sf::RenderWindow& window) {
	for (list<Ennemy*>::iterator it = _ennemys.begin(); it != _ennemys.end(); ++it) {
		(*it)->render(window);
	}
}

void EnnemyPack::clean() {
	list<Ennemy*>::iterator it = _ennemys.begin();
	while (it != _ennemys.end()) {
		delete(*it);
		_ennemys.erase(it++);
	}
}
