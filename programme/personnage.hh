#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "attaque.hh"

class Personnage{

public:
	Personnage(){};
	~Personnage(){};
	

protected:
	//std::vector<Attaque> Attaques; //ensemble d'attaques
	float defense; //points de defense
	sf::Sprite sprite; //image du personnage
};