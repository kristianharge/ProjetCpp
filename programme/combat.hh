#pragma once
#include "map.hh"
#include "joueur.hh"

class Combat{
	public:
		Combat();
		~Combat(){};
		void processInput(){};
		void update(){};
		void render(sf::RenderWindow & window);

	private:
		Map *map;
		Joueur *p1;
		Joueur *p2;
};