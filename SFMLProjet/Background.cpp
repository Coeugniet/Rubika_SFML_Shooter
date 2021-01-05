#include "Background.h"

#include <iostream>
#include <vector>
#include "BackgroundLayer.h"

using namespace std;

Background::Background() {
	
}

Background::Background(sf::Vector2f viewSize, string repertoryPath, vector<string> filesNames) {
	for (unsigned int i = 0; i < filesNames.size(); i++) {
		_layers.push_back(new BackgroundLayer(viewSize, repertoryPath + "/" + filesNames[i], (i + 1) * 100.f));
	}
}

Background::~Background() {
	for (unsigned int i = 0; i < _layers.size(); i++) {
		delete(_layers[i]);
	}
}

void Background::render(sf::RenderWindow& window) {
	for (unsigned int i = 0; i < _layers.size(); i++) {
		_layers[i]->render(window);
	}
}

void Background::update(double deltaTime) {
	for (unsigned int i = 0; i < _layers.size(); i++) {
		sf::Vector2f pos = _layers[i]->getPosition();
		_layers[i]->setPosition(pos.x - _layers[i]->getSpeed() * deltaTime, pos.y);
	}
}
