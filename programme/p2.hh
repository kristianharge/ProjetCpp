#pragma once
#include <SFML/Graphics.hpp>
#include "personnage.hh"
#include "joueur.hh"
//#include "force.hh"

class P2 : public Joueur{

public:
	P2(Personnage & p);
	~P2();

	void processInput();

};