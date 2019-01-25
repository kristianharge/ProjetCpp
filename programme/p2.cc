#include <SFML/Graphics.hpp>
#include <iostream>
#include "p2.hh"
#include "variablesGlobales.hh"

P2::P2(Personnage * p) : Joueur(p){
	vie = new Vie (WIDTH - 9*32, 2*32);
	realPosition = sf::Vector2f(WIDTH - 7*32, 5*32);
}

P2::~P2(){
}

void P2::processInput(){
	static bool acInterrupt = false;//nous permet de controler le bouton attaque courte comme interruption
	static bool ac2Interrupt = false;
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		actions[gauche] = true;
	else
		actions[gauche] = false;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		actions[droite] = true;
	else
		actions[droite] = false;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		actions[haut] = true;
	else
		actions[haut] = false;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		actions[bas] = true;
	else
		actions[bas] = false;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
		if(!acInterrupt){
			actions[ac] = true;
			acInterrupt = true;
		}else
			actions[ac] = false;
	}else if (acInterrupt) {
		actions[ac] = false;
		acInterrupt = false;
	}
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::T)){
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
