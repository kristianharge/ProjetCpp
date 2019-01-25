#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Ecran{

public:
	Ecran(){nextScreen = -1;};
	virtual ~Ecran(){ delete music;};
	
	virtual void processInput() = 0;
	virtual void update() = 0;
	virtual void render(sf::RenderWindow & window) = 0;

	//Permet de changer d'écran, -1 on change pas, 0 Accueil, 1 Map, 2 Perso, 3 jeu, 4 gameOver
	int nextScreen;
	sf::Music *music;
};
