#pragma once

#include <list>
#include <vector>
#include "EnnemyPack.h"
#include "Bullet.h"
#include "Background.h"
#include "Player.h"
#include "UIManager.h"

using namespace std;

class GameEngine
{
public:
	~GameEngine();

	void update(float deltaTime);
	void render(sf::RenderWindow& window);
	void setSpaceshipsTexturesPaths(string repertoryPath);
	void restart();

	static GameEngine* getInstance() { return _instance; }
	sf::Vector2f getView() { return _view; }
	vector<string>* getSpaceshipsTexturesPaths() { return &_spaceshipsTexturesPaths; }

	static void createInstance(sf::Vector2f viewSize) {
		if (!_instance) _instance = new GameEngine(viewSize);
	}
	void setGameScale(sf::Vector2f gameScale) {
		_gameScale.x = gameScale.x;
		_gameScale.y = gameScale.y;
	}
	list<Bullet*>* getBullets() { return &_bullets; }
	list<EnnemyPack*>* getEnnemys() { return &_ennemys; }
	sf::Vector2f getGameScale() { return _gameScale; }
	Player* getPlayer() { return _player; }
	void addScore(int value) { _score += value; }
	int getScore() { return _score; }

protected:
	sf::Clock _clock;
	sf::Time lastSpawn;
	Player *_player;
	Background *_background;
	list<EnnemyPack*> _ennemys;
	list<Bullet*> _bullets;
	int _score;
	sf::Vector2f _view;
	sf::Vector2f _gameScale;
	vector<string> _spaceshipsTexturesPaths;
	UIManager *_ui;

private:
	static GameEngine* _instance;
	GameEngine(sf::Vector2f viewSize);
};

