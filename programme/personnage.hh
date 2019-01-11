#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
//#include "attaquecourte.hh"

class Personnage{

public:
	Personnage(){};
	~Personnage(){};
	//getters
	std::string getTexturePath() { return path; };
	float getVitesse() const { return vitesse; };
	float getPtsAttaque() {return ptsAttaque;};
	

protected:
	float ptsAttaque; //points d'attaque
	float vitesse; //vitesse deplacement
	std::string path; //image du personnage
};