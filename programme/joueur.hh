#pragma once
#include <SFML/Graphics.hpp>
#include "personnage.hh"
//#include "vie.hh"
//#include "force.hh"

class Joueur{

public:
	Joueur(Personnage & p);
	~Joueur();
	//virtual void bouger();
	

protected:
	//Vie vie;
	//Force force;
	Personnage *perso;
	//sf::Vector2f position;

};