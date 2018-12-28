#include <SFML/Graphics.hpp>
#include <iostream>
#include "p1.hh"
//#include "variablesGlobales.hh"

P1::P1(Personnage & p) : Joueur(p){
	vie = new Vie (4*32, 2*32);
	tilePosition = 255;
	futTilePosition = tilePosition;
	realPosition = sf::Vector2f(5*32, 5*32);
	
	if (!texture.loadFromFile(p.getTexturePath()))
	{
	    std::cout << "Error in line " << __LINE__ << " of file " << __FILE__ << std::endl;
	}
	sprite.setTexture(texture);
}

void P1::setTouche(){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		actions[gauche] = true;
	else
		actions[gauche] = false;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		actions[droite] = true;
	else
		actions[droite] = false;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		actions[haut] = true;
	else
		actions[haut] = false;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		actions[bas] = true;
	else
		actions[bas] = false;

}