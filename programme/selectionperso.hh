#pragma once
#include <iostream>
#include "ecran.hh"

class SelectionPerso : Ecran{
	public:
		SelectionPerso(sf::RenderWindow & window);
		~SelectionPerso();
		void processInput(){};
		void update(){};
		void render(sf::RenderWindow & window);

	private:
		sf::Vector2f *positions;
		int nbPerso;

		sf::Sprite flechesSelector;
		sf::Texture flechesTexture;
		int flechesPos;

		sf::Sprite qsdzSelector;
		sf::Texture qsdzTexture;
		int qsdzPos;
};