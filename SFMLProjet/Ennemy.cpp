#include "Ennemy.h"
#include "GameEngine.h"
#include <stdlib.h>
#include "RedBullet.h"
#include "BlueBullet.h"

Ennemy::Ennemy(sf::Vector2f scale) : SpaceShip() {
	vector<string> *s = GameEngine::getInstance()->getSpaceshipsTexturesPaths();
	loadSprite(s->at(rand() % s->size()));
	_sprite.setScale(scale);
	_shootRate = ((double)rand() / (RAND_MAX)) * 2.f + 1.f;
}

Ennemy::~Ennemy() {

}

void Ennemy::update(float deltaTime) {
	SpaceShip::update(deltaTime);
	if ((_clock.getElapsedTime() - _lastShoot).asSeconds() > _shootRate) {
		_lastShoot = _clock.getElapsedTime();
		if (GameEngine::getInstance()->getPlayer()->isActive()) shoot();
	}
}

void Ennemy::shoot() {
	sf::Vector2f pos(GameEngine::getInstance()->getPlayer()->getX() - getX(), GameEngine::getInstance()->getPlayer()->getY() - getY());
	float length = sqrt(pos.x * pos.x + pos.y * pos.y);
	if (length != 0) pos /= length;
	GameEngine::getInstance()->getBullets()->push_back(new RedBullet(GameEngine::getInstance()->getGameScale(),
		this, pos, 250.f,
		getX() + (_sprite.getLocalBounds().width * _sprite.getScale().x) / 2,
		getY() + (_sprite.getLocalBounds().height * _sprite.getScale().y) / 2));
}

void Ennemy::collisionsTest() {
	Player* player = GameEngine::getInstance()->getPlayer();
	if (getGlobalBounds().intersects(player->getGlobalBounds()))
		player->setAlive(false);

	list<Bullet*>* bullets = GameEngine::getInstance()->getBullets();
	list<Bullet*>::iterator it = bullets->begin();
	sf::FloatRect ennemyBound = getGlobalBounds();
	while (it != bullets->end())
	{
		if (dynamic_cast<BlueBullet*>((*it)) != nullptr) {
			if (ennemyBound.intersects((*it)->getGlobalBounds())) {
				_alive = false;
				(*it)->setActive(false);
				GameEngine::getInstance()->addScore(10);
			}
		}
		++it;
	}
}