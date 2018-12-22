#include <SFML/Graphics.hpp>
#include <iostream>
#include "p1.hh"

P1::P1(Personnage & p) : Joueur(p){
	vie = new Vie (4*32, 2*32);
	position = sf::Vector2f(5*32, 5*32);

	
	if (!texture.loadFromFile(p.getTexturePath()))
	{
	    std::cout << "Error in line " << __LINE__ << " of file " << __FILE__ << std::endl;
	}
	sprite.setTexture(texture);
}

void P1::bouger(Map * map){

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		direction.x = -200.f;
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		direction.x = 200.f;
	else
		direction.x = 0.f;
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		//je regarde si je touche par terre
		if(map->numberOfTile(sf::Vector2f(position.x, position.y + TAILLEPERSO_Y)) > 49 ||
		map->numberOfTile(sf::Vector2f(position.x + TAILLEPERSO_X, position.y + TAILLEPERSO_Y)) > 49)
			direction.y = -250.f;
	}
}