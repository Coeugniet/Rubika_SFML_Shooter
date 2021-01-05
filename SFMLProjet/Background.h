#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "BackgroundLayer.h"

using namespace std;

class Background
{
public:
	Background();
	Background(sf::Vector2f viewSize, string repertoryPath, vector<string> filesNames);
	~Background();

	void render(sf::RenderWindow& window);
	void update(double deltaTime);
	sf::Vector2f getLayerScale() {
		return _layers[0]->getScale();
	}

protected:
	vector<BackgroundLayer*> _layers;
};

