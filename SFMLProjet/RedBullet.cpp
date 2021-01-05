#include "RedBullet.h"

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Bullet.h"
#include "GameEngine.h"

using namespace std;

RedBullet::RedBullet(sf::Vector2f scale, SpaceShip* shooter, sf::Vector2f direction, float speed, float x, float y) : Bullet(scale, shooter, direction, speed, x, y) {
	loadSprite("Ressources/Bullet/red_bullet.png");
	setPosition(getX() - (_sprite.getLocalBounds().width * scale.x) / 2, getY() - (_sprite.getLocalBounds().height * scale.y) / 2);
}

RedBullet::~RedBullet() {

}

void RedBullet::collisionsTest() {
	Player* player = GameEngine::getInstance()->getPlayer();
	if (getGlobalBounds().intersects(player->getGlobalBounds())) {
		if (player->isAlive()) player->setAlive(false);
	}
}
