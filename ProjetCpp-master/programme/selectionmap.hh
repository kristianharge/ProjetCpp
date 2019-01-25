#pragma once
#include <iostream>
#include "map.hh"
#include "rickmap.hh"
#include "simpmap.hh"
#include "ecran.hh"
#include "variablesGlobales.hh"

class SelectionMap : Ecran{
	public:
		SelectionMap(sf::RenderWindow & window);
		~SelectionMap();
		void processInput(){};
		void update(){};
		void render(sf::RenderWindow & window);

		Map * mapFleches;

	private:
		void select();

		sf::Vector2f *positions;
		sf::Vector2f *positions_map;
		int nbMap;

		sf::Sprite flechesSelector;
		sf::Texture flechesTexture;
		int flechesPos;
		
		sf::Texture R;
		sf::Texture S;
	
		sf::Sprite r;
		sf::Sprite s;
		
};
