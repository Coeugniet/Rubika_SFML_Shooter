#include "BlueBullet.h"

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Bullet.h"

using namespace std;

BlueBullet::BlueBullet(sf::Vector2f scale, SpaceShip* shooter, sf::Vector2f direction, float speed, float x, float y) : Bullet(scale, shooter, direction, speed, x, y){
	loadSprite("Ressources/Bullet/blue_bullet.png");
	setPosition(getX() - (_sprite.getLocalBounds().width * scale.x) / 2, getY() - (_sprite.getLocalBounds().height * scale.y) / 2);
}

BlueBullet::~BlueBullet() {

}

void BlueBullet::collisionsTest() {

}