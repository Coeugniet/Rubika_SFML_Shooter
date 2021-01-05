#include "EnnemyVertical.h"

EnnemyVertical::EnnemyVertical(sf::Vector2f scale, float speed) : Ennemy(scale) {
	_time = _clock.getElapsedTime();
	_speed = speed;
}

EnnemyVertical::~EnnemyVertical() {

}

void EnnemyVertical::update(float deltaTime) {
	Ennemy::update(deltaTime);
	if ((_clock.getElapsedTime() - _time).asSeconds() > 1.5f) {
		_time = _clock.getElapsedTime();
		_speed *= -1;
	}
	setPosition(getX(), getY() + _speed * deltaTime);
}
