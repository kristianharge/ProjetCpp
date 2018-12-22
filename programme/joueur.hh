#pragma once
#include <SFML/Graphics.hpp>
#include "personnage.hh"
#include "vie.hh"
#include "map.hh"
//#include "force.hh"

class Joueur{

public:
	Joueur(Personnage & p);
	~Joueur(){};
	//methodes du moteur de jeu
	void update(Map * map);
	void render(sf::RenderWindow & w);
	//autres methodes
	void gravite(Map * map);
	virtual void bouger(Map * map) = 0;

	

protected:
	Vie *vie;
	//Force force;
	Personnage perso;

	//variables sf
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Vector2f direction;//direction sous forme de vecteur vitesse en pixels/s

};