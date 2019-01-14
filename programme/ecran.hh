#pragma once
#include <SFML/Graphics.hpp>

class Ecran{

public:
	Ecran(){nextScreen = -1;};
	virtual ~Ecran(){};
	
	virtual void processInput() = 0;
	virtual void update() = 0;
	virtual void render(sf::RenderWindow & window) = 0;

	//Permet de changer d'écran, -1 on change pas, 0 Demarrage, 1 jeu, 2, gameOver
	int nextScreen;
};