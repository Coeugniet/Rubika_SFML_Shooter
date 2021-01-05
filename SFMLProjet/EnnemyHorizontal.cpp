#include "EnnemyHorizontal.h"

EnnemyHorizontal::EnnemyHorizontal(sf::Vector2f scale, float speed) : Ennemy(scale) {
	_time = _clock.getElapsedTime();
	_speed = speed;
}

EnnemyHorizontal::~EnnemyHorizontal() {

}

void EnnemyHorizontal::update(float deltaTime) {
	Ennemy::update(deltaTime);
	if ((_clock.getElapsedTime() - _time).asSeconds() > 1.5f) {
		_time = _clock.getElapsedTime();
		_speed *= -1;
	}
	setPosition(getX() + _speed * deltaTime, getY());
}