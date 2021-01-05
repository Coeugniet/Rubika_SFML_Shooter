#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>

#include "GameEngine.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML Shooter", sf::Style::Titlebar | sf::Style::Close); // creation de la fenetre avec les dimensions du bureau

	/* Reduit la taille de la fenetre pour laisser passer les bordures */
	sf::Vector2u bureau = window.getSize();
	sf::Vector2u fenetre = sf::Vector2u(1360, 800);
	window.setSize(fenetre);
	window.setPosition(sf::Vector2i((bureau.x - fenetre.x) / 2, (bureau.y - fenetre.y) / 2));

	sf::Clock clock;
	sf::Time time = clock.restart();
	double deltaTime = 0.01;
	cout << "creation instance" << endl;
	GameEngine::createInstance(window.getView().getSize());
	GameEngine* game = GameEngine::getInstance();
	cout << "creation fini" << endl;

	while (window.isOpen())
	{
		deltaTime = ((double)clock.restart().asSeconds());
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//updates
		game->update(deltaTime);

		//renders
		window.clear();
		game->render(window);
		window.display();
	}
	return EXIT_SUCCESS;
}
