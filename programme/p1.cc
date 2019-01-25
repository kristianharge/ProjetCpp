#include <SFML/Graphics.hpp>
#include <iostream>
#include "p1.hh"
//#include "variablesGlobales.hh"

P1::P1(Personnage * p) : Joueur(p){
	vie = new Vie (4*32, 2*32);
	realPosition = sf::Vector2f(5*32, 5*32);
}

P1::~P1(){
}

void P1::processInput(){
	static bool acInterrupt = false;//nous permet de controler le bouton attaque courte comme interruption
	static bool ac2Interrupt = false;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		actions[gauche] = true;
	else
		actions[gauche] = false;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		actions[droite] = true;
	else
		actions[droite] = false;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		actions[haut] = true;
	else
		actions[haut] = false;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		actions[bas] = true;
	else
		actions[bas] = false;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::L)){
		if(!acInterrupt){
			actions[ac] = true;
			acInterrupt = true;
		}else
			actions[ac] = false;
	}else if (acInterrupt) {
		actions[ac] = false;
		acInterrupt = false;
	}
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)){
		if(!ac2Interrupt){
			actions[ac2] = true;
			ac2Interrupt = true;
		}else
			actions[ac2] = false;
	}else if (ac2Interrupt) {
		actions[ac2] = false;
		ac2Interrupt = false;
	}
	
	
}
