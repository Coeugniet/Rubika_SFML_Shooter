#include "GameObject.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameEngine.h"


using namespace std;

GameObject::GameObject() {
    _position = sf::Vector2f(100.f, 100.f);
    _active = true;
}

GameObject::~GameObject() {

}

int GameObject::loadSprite(string filePath) {
    if (!_texture.loadFromFile(filePath)) {
        cerr << "Erreur durant le chargement de l'image" << endl;
        return EXIT_FAILURE;
    }

    _sprite.setTexture(_texture);
}

void GameObject::render(sf::RenderWindow &window) {
    _sprite.setPosition(_position.x, _position.y);
    window.draw(_sprite);
}

void GameObject::setPosition(float x, float y) {
    float margin = 400.f;
    if (x <= -margin
        || x >= (GameEngine::getInstance()->getView().x + margin)
        || y <= -margin
        || y >= (GameEngine::getInstance()->getView().y + margin)
        ) {
        cout << "Destruction d'un objet hors ecran" << endl;
        _active = false;
    }

    _position.x = x;
    _position.y = y;
}

void GameObject::update(float deltaTime) {
    collisionsTest();
}