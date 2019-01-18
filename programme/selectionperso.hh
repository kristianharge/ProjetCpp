#pragma once
#include <iostream>
#include "personnage.hh"
#include "cuddles.hh"
#include "bob.hh"
#include "homer.hh"
#include "pb.hh"
#include "ecran.hh"
#include "variablesGlobales.hh"

class SelectionPerso : Ecran{
	public:
		SelectionPerso(sf::RenderWindow & window);
		~SelectionPerso();
		void processInput(){};
		void update(){};
		void render(sf::RenderWindow & window);

		Personnage * persoFleches;
		Personnage * persoQsdz;

	private:
		void select();

		sf::Vector2f *positions;
		int nbPerso;

		sf::Sprite flechesSelector;
		sf::Texture flechesTexture;
		int flechesPos;

		sf::Sprite qsdzSelector;
		sf::Texture qsdzTexture;
		int qsdzPos;
};