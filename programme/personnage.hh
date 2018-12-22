#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "attaque.hh"
#define TAILLEPERSO_Y 96
#define TAILLEPERSO_X 64

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