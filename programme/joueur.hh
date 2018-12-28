#pragma once
#include <SFML/Graphics.hpp>
#include "variablesGlobales.hh"
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
	void setTilePosition();
	void setFutTilePosition(Direction const dir);
	void deplacementImage(Map * map);
	char controleColisionMap(Direction dir, Map * map);
	void mouvement(Map * map);
	virtual void setTouche() = 0;

	

protected:
	Vie *vie;
	//Force force;
	Personnage perso;
	std::map<Touche, bool> actions;//actions lies aux touches
	Direction direction;//direction du mouvement
	float vitesseChute; //vitesse de chute
	int tilePosition; //indice de la tile dans la quelle notre position est
	int futTilePosition; //indice de la future position voulue

	//variables sf
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f realPosition;//position reelle dans la map
};