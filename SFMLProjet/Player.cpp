#include "Player.h"

#include "GameEngine.h"
#include "SpaceShip.h"
#include <math.h>
#include "BlueBullet.h"
#include "RedBullet.h"

using namespace std;

Player::Player(sf::Vector2f scale, float x, float y) : SpaceShip() {
	loadSprite("Ressources/Spaceship/vaisseaux_120.png");
	_sprite.setScale(scale);
	_speed = 300.f;
	_shootRate = 0.6f;
	_position.x = x;
	_position.y = y - (_sprite.getGlobalBounds().width / 2.);
}

Player::~Player() {

}

void Player::update(float deltaTime) {
	SpaceShip::update(deltaTime);

	sf::Vector2f direction(0.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) direction.x += 1.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) direction.x -= 1.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) direction.y += 1.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) direction.y -= 1.f;

	setPosition(getX() + direction.x * _speed * deltaTime, getY() - direction.y * _speed * deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (_clock.getElapsedTime() - _lastShoot).asSeconds() > _shootRate) {
		_lastShoot = _clock.getElapsedTime();
		shoot();
	}
}

void Player::shoot() {
	GameEngine::getInstance()->getBullets()->push_back(new BlueBullet(GameEngine::getInstance()->getGameScale(),
		this, sf::Vector2f(1, 0), 400.f,
		getX() + (_sprite.getLocalBounds().width * _sprite.getScale().x) / 2,
		getY() + (_sprite.getLocalBounds().height * _sprite.getScale().y) / 2));
}

void Player::setPosition(float x, float y) {
	if (x <= 0.) x = 0.;
	if (x >= (GameEngine::getInstance()->getView().x - (_sprite.getLocalBounds().width * _sprite.getScale().x))) x = (GameEngine::getInstance()->getView().x - (_sprite.getLocalBounds().width * _sprite.getScale().x));
	if (y <= 0.) y = 0.;
	if (y >= (GameEngine::getInstance()->getView().y - (_sprite.getLocalBounds().height * _sprite.getScale().y))) y = (GameEngine::getInstance()->getView().y - (_sprite.getLocalBounds().height * _sprite.getScale().y));
	SpaceShip::setPosition(x, y);
}

void Player::reset() {
	_active = true;
	_alive = true;
	sf::Color c = _sprite.getColor();
	c.a = 255;
	_sprite.setColor(c);
}

void Player::collisionsTest() {

}
