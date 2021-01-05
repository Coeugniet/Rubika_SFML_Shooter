#include "UIManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameEngine.h"

using namespace std;

UIManager::UIManager(sf::Vector2f gameView) {
	_gameView.x = gameView.x;
	_gameView.y = gameView.y;
	loadFont("Ressources/Font/Lilian.ttf");
	_score.setFont(_font);
	_score.setCharacterSize(60);
	_gameOver.setFont(_font);
	_gameOver.setCharacterSize(80);
	_gameOver.setString("Press  'R'  to restart the game !");
	_gameOver.setPosition(370.f, (gameView.y / 2.f) - (_gameOver.getCharacterSize() / 2.f));
}

UIManager::~UIManager() {

}

void UIManager::render(sf::RenderWindow& window) {
	string s = to_string(GameEngine::getInstance()->getScore());
	_score.setString(s);
	_score.setPosition((_gameView.x / 2 ) - ((s.size() * _score.getCharacterSize()) / 2.f), 0.f);
	window.draw(_score);
	if (!GameEngine::getInstance()->getPlayer()->isActive()) window.draw(_gameOver);
}

void UIManager::loadFont(string path) {
	if (!_font.loadFromFile(path)) {
		cout << "erreur dans le chargement de la police d'ecriture" << endl;
	}
}
