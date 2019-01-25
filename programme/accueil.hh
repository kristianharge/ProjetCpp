#pragma once
#include "ecran.hh"
#include <iostream>


class Accueil : Ecran{
	public:
		Accueil(){};
		Accueil(sf::RenderWindow & window);
		~Accueil();
		void processInput();
		void update(){};
		void render(sf::RenderWindow & window);
		

	private:
		sf::Sprite image;
};
