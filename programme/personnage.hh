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
	float getVitesse() const { return vitesse; };
	

protected:
	//std::vector<Attaque> Attaques; //ensemble d'attaques
	float defense; //points de defense
	float vitesse; //vitesse deplacement
	std::string path; //image du personnage
};