#include "GameEngine.h"

#include <SFML/Graphics.hpp>
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include <list>
#include <stdlib.h>
#include "Ennemy.h"
#include "EnnemyVertical.h"
#include "Bullet.h"
#include "Background.h"
#include "Player.h"
#include <experimental/filesystem>
#include <vector>

namespace fs = std::experimental::filesystem;
using namespace std;

GameEngine* GameEngine::_instance = nullptr;

GameEngine::GameEngine(sf::Vector2f viewSize) : _view(viewSize) {
	_score = 0;
	_background = new Background(viewSize, "Ressources/Background",
		{ "Sky.png", "Mountains.png", "Forest.png"});
	_gameScale = _background->getLayerScale();
	_player = new Player(_gameScale, 150., viewSize.y / 2);
	setSpaceshipsTexturesPaths("Ressources/Spaceship");
	lastSpawn = _clock.getElapsedTime();
	_ui = new UIManager(viewSize);
}

GameEngine::~GameEngine() {

}

void GameEngine::render(sf::RenderWindow& window) {
	_background->render(window);

	for (list<EnnemyPack*>::iterator it = _ennemys.begin(); it != _ennemys.end(); ++it) {
		(*it)->render(window);
	}

	for (list<Bullet*>::iterator it = _bullets.begin(); it != _bullets.end(); ++it) {
		(*it)->render(window);
	}

	if (_player->isActive()) {
		_player->render(window);
	}

	_ui->render(window);
}

void GameEngine::update(float deltaTime) {
	if ((_clock.getElapsedTime() - lastSpawn).asSeconds() > 5.f) {
		lastSpawn = _clock.getElapsedTime();
		_ennemys.push_back(new EnnemyPack(_gameScale, "random", _player->getGlobalBounds().width, _player->getGlobalBounds().height, 150.f, 120.f));
	}

	_background->update(deltaTime);

	list<EnnemyPack*>::iterator eIt = _ennemys.begin();
	while (eIt != _ennemys.end()) {
		(*eIt)->update(deltaTime);
		if ((*eIt)->isEmpty()) {
			delete (*eIt);
			_ennemys.erase(eIt++);
		}
		else ++eIt;
	}

	list<Bullet*>::iterator bIt = _bullets.begin();
	while (bIt != _bullets.end())
	{
		(*bIt)->update(deltaTime);
		if (!(*bIt)->isActive()) {
			delete (*bIt);
			_bullets.erase(bIt++);
		}
		else ++bIt;
	}

	if (_player->isActive()) _player->update(deltaTime);
	else {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			cout << "restart !" << endl;
			restart();
		}
	}
}

void GameEngine::setSpaceshipsTexturesPaths(string repertoryPath) {
	for (const auto& dirEntry : fs::directory_iterator(repertoryPath)) {
		_spaceshipsTexturesPaths.push_back(dirEntry.path().generic_string());
	}
}

void GameEngine::restart() {
	_score = 0;

	lastSpawn = _clock.getElapsedTime();

	list<EnnemyPack*>::iterator eIt = _ennemys.begin();
	while (eIt != _ennemys.end()) {
		(*eIt)->clean();
		delete (*eIt);
		_ennemys.erase(eIt++);
	}

	list<Bullet*>::iterator bIt = _bullets.begin();
	while (bIt != _bullets.end())
	{
		delete (*bIt);
		_bullets.erase(bIt++);
	}

	_player->reset();
}
