#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "attaque.hh"

class Personnage{

public:
	Personnage(){};
	~Personnage(){};
	std::string getTexturePath() { return path; };
	

protected:
	//std::vector<Attaque> Attaques; //ensemble d'attaques
	float defense; //points de defense
	std::string path; //image du personnage
};