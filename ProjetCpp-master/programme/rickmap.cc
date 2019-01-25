#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "rickmap.hh"

RickMap::RickMap(){
	int i = 0;

	std::ifstream file("rickmap.txt");
  	std::string s;
  	while( file >> s)
    {
      	matrix.push_back(std::make_pair(std::stoi(s), sf::Vector2f(COTE*i % WIDTH, (i/taille[0])*COTE)));
      	i++;
    }
  	file.close();

	//set Textures
	//background
	for (i = 0; i < 39; i++){
		sf::Texture texture;
		std::string path = "../Images/Maps/RickMap/bg/" + std::to_string(i);
		if (!texture.loadFromFile(path + ".png"))
		{
		    std::cout << "Error in line " << __LINE__ << " of file " << __FILE__ << std::endl;
		}
		textures [i] = texture;
	}

	//solid
	for (i = 50; i < 73; i++){
		sf::Texture texture;
		std::string path = "../Images/Maps/RickMap/solid/" + std::to_string(i);
		if (!texture.loadFromFile(path + ".png"))
		{
		    std::cout << "Error in line " << __LINE__ << " of file " << __FILE__ << std::endl;
		}
		textures [i] = texture;
	}

	//traversable
	for (i = 100; i < 103; i++){
		sf::Texture texture;
		std::string path = "../Images/Maps/RickMap/traversable/" + std::to_string(i);
		if (!texture.loadFromFile(path + ".png"))
		{
		    std::cout << "Error in line " << __LINE__ << " of file " << __FILE__ << std::endl;
		}
		textures [i] = texture;
	}
}

RickMap::~RickMap(){}