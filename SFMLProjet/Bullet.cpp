#include "Bullet.h"

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

Bullet::Bullet(sf::Vector2f scale, SpaceShip* shooter, sf::Vector2f direction, float speed, float x, float y) : _shooter(shooter), _speed(speed), _direction(direction) {
	setPosition(x, y);
	_sprite.setScale(scale);
}

Bullet::~Bullet() {

}

void Bullet::update(float deltaTime) {
	GameObject::update(deltaTime);
	setPosition(getX() + _direction.x * _speed * deltaTime, getY() + _direction.y * _speed * deltaTime);
}
