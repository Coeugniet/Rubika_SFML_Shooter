#include "SpaceShip.h"

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "GameObject.h"

using namespace std;


SpaceShip::SpaceShip() : GameObject() {
    _lastShoot = _clock.getElapsedTime();
    _alive = true;
}

SpaceShip::~SpaceShip() {

}

void SpaceShip::setPosition(float x, float y) {
    if (!_alive) return;
    GameObject::setPosition(x, y);
}

void SpaceShip::update(float deltaTime) {
    GameObject::update(deltaTime);
    if (!_alive) die(deltaTime);
}

void SpaceShip::die(float deltaTime) {
    if (_alive) _alive = false;
    if (_sprite.getColor().a <= 0.) _active = false;
    else {
        sf::Color c = _sprite.getColor();
        c.a -= 0.001 * deltaTime;
        _sprite.setColor(c);
    }
}
