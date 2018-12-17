#ifndef MAP_HH
#define MAP_HH
#include <vector>
#include <SFML/Graphics.hpp>
#define WIDTH 1600
#define HEIGHT 960
#define COTE 32

class Map{//convention 0->49  traversable, 50->99 solide, 100->255 plateforme travesable par le bas
	public:
		Map();
		~Map();

		//methods
		void printMap() const;
		void drawMap(sf::RenderWindow & window);

	protected:
		//contitnet la taille de la map en nombre de tiles
		int taille[2];
		//contient les valeurs des cases en premier et les coordonees en deuxieme
		std::vector<std::pair<char, sf::Vector2f>> matrix;
		//contient les textures du tiled map
		std::vector<sf::Texture> textures;
};

#endif