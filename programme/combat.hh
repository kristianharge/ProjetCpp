#ifndef COMBAT_HH
#define COMBAT_HH
#include "map.hh"

class Combat{
	public:
		Combat();
		~Combat(){};
		void processInput(){};
		void update(){};
		void render(sf::RenderWindow & window);

	private:
		Map *map;
};

#endif