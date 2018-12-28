#pragma once
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include "variablesGlobales.hh"

class Map{//convention 0->49  traversable, 50->99 solide, 100->255 plateforme travesable par le bas
	public:
		Map();
		~Map();

		//methods
		void printMap() const;
		void drawMap(sf::RenderWindow & window);
		char numberOfTile(sf::Vector2f const & v); //renvoi le numero de la tile sur la quelle on pointe
		char typeDeTileParIndex(int i) const;

	protected:
		int taille[2]; //contitnet la taille de la map en nombre de tiles
		std::vector<std::pair<char, sf::Vector2f>> matrix; //contient les valeurs des cases en premier et les coordonees en deuxieme
		std::map<int, sf::Texture> textures; //contient les textures du tiled map
};