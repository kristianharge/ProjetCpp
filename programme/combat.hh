#pragma once
#include "map.hh"
#include "p1.hh"

class Combat{
	public:
		Combat();
		~Combat(){};
		void processInput(){};
		void update(){};
		void render(sf::RenderWindow & window);

	private:
		Map *map;
		P1 *p1;
		//P2 *p2;
};