#pragma once
#include "ecran.hh"
#include "map.hh" 
#include "joueur.hh"

class GameOver : Ecran{
	public:
		GameOver(){};
		GameOver(sf::RenderWindow & window, Joueur * winner, Joueur * looser);
		~GameOver();
		void processInput(){};
		void update(){};
		void render(sf::RenderWindow & window);

	private:
		sf::Sprite image;
		Joueur * winner;
		Joueur * looser;
		
};
