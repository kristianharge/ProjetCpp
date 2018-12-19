#include <SFML/Graphics.hpp>
#include "cuddles.hh"

Cuddles::Cuddles(){
	defense = 0.8f;

	sf::Texture texture;
		std::string path = "../Images/Perso/Cuddles/normal.png";
		if (!texture.loadFromFile(path))
		{
		    std::cout << "Error in line " << __LINE__ << " of file " << __FILE__ << std::endl;
		}
	sprite = sf::Sprite(texture);
}