#ifndef MAP_HH
#define MAP_HH
#include <SFML/Graphics.hpp>

class Map{//convention 0->9  traversable, 10->19 solide, 20->29 plateforme travesable par le bas
	public:
		Map();
		~Map();

		//methods
		void printMap();

	protected:
		int taille[2];
		char* matrix;
		sf::Texture* textures;
};

#endif