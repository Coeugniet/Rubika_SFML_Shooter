#include "BackgroundLayer.h"
#include "GameEngine.h"

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

BackgroundLayer::BackgroundLayer(sf::Vector2f viewSize, string filePath, float speed) :_viewSize(viewSize), _speed(speed) {
    loadSprite(filePath);
    _width = _sprite.getGlobalBounds().width;
}

BackgroundLayer::~BackgroundLayer() {

}

int BackgroundLayer::loadSprite(string filePath) {
    if (!_texture.loadFromFile(filePath)) {
        cerr << "Erreur durant le chargement de la texture d'un background layer" << endl;
        return EXIT_FAILURE;
    }

    cout << "Background layer charger avec succes ! -- " << filePath << endl;
    _sprite.setTexture(_texture);
    _scale = sf::Vector2f(_viewSize.x / _texture.getSize().x, _viewSize.y / _texture.getSize().y);
    _sprite.setScale(_scale);
}

void BackgroundLayer::render(sf::RenderWindow& window) {
    window.draw(_sprite);
    if (getX() <= -_width) setPosition(0., getY());
    _sprite.setPosition(getX() + _sprite.getGlobalBounds().width, getY());
    window.draw(_sprite);
    _sprite.setPosition(getX() - _sprite.getGlobalBounds().width, getY());
}
