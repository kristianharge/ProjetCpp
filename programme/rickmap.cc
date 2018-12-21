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

	/*std::filebuf ofile;
  	ofile.open ("rickmap.txt",std::ios::out);
 	std::ostream os(&ofile);
  
  	for(i = 0; i < taille[1]*taille[0]; i++)
	{
		if(i != 0 && i%taille[0] == 0){
			os << std::endl;
		}


		if((i/taille[0]) % 3 == 0){
	 		os << i % 3 << " ";
	 	}
	 	else if((i/taille[0]) % 3 == 1){
	 		os << (i + 1) % 3 + 3 << " ";
		}
		else{
			os << (i + 2) % 3 + 6 << " ";
		}
	}
  	ofile.close();*/

	//creer la matrice avec les numeros de case
	/*for(i = 0; i < taille[1]*taille[0]; i++)
	{
		if((i/taille[0]) % 3 == 0){
	 		matrix.push_back(std::make_pair(i % 3, sf::Vector2f(COTE*i % WIDTH, (i/taille[0])*COTE)));
	 	}
	 	else if((i/taille[0]) % 3 == 1){
	 		matrix.push_back(std::make_pair((i + 1) % 3 + 3, sf::Vector2f(COTE*i % WIDTH, (i/taille[0])*COTE)));
		}
		else{
			matrix.push_back(std::make_pair((i + 2) % 3 + 6, sf::Vector2f(COTE*i % WIDTH, (i/taille[0])*COTE)));
		}
	}*/

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