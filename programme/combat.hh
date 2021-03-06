#pragma once
#include "ecran.hh"
#include "map.hh"
#include "p1.hh"
#include "p2.hh"

class Combat : Ecran{
	public:
		Combat();
		Combat(Personnage * pp1, Personnage * pp2, Map *m);
		~Combat();
		void processInput();
		void update();
		void render(sf::RenderWindow & window);
		Joueur *winner;
		Joueur *looser;

	private:
		Map *map;
		P1 *p1;
		P2 *p2;
};
