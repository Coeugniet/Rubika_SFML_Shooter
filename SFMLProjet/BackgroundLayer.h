#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

class BackgroundLayer
{
public:
	BackgroundLayer(sf::Vector2f viewSize, string filePath, float speed);
	~BackgroundLayer();

	int loadSprite(string filePath);
	void render(sf::RenderWindow& window);

	void setPosition(float x, float y) {
		_sprite.setPosition(x, y);
	};

	sf::Vector2f getPosition() {
		return _sprite.getPosition();
	}

	float getX() {
		return _sprite.getPosition().x;
	}

	float getY() {
		return _sprite.getPosition().y;
	}

	float getSpeed() {
		return _speed;
	}

	sf::Vector2f getScale() {
		return _scale;
	}

protected:
	float _speed;
	float _width;
	sf::Texture _texture;
	sf::Sprite _sprite;
	sf::Vector2f _firstPosition;
	sf::Vector2f _secondPosition;
	sf::Vector2f _viewSize;
	sf::Vector2f _scale;
};

