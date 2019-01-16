#pragma once
#include <SFML/Graphics.hpp>
#include "personnage.hh"
#include "joueur.hh"
//#include "force.hh"

class P1 : public Joueur{

public:
	P1(Personnage & p);
	~P1();

	void processInput();

};