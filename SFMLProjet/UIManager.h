#pragma once

#include <SFML/Graphics.hpp>

using namespace std;

class UIManager
{
public:
	UIManager(sf::Vector2f gameView);
	~UIManager();

	void render(sf::RenderWindow& window);
	void loadFont(string path);

private:
	sf::Font _font;
	sf::Text _score;
	sf::Text _gameOver;
	sf::Vector2f _gameView;
};

