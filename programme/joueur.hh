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
	virtual ~Joueur(){};
	//methodes du moteur de jeu
	void update(Map * map);
	void render(sf::RenderWindow & w);
	//seters
	void setAdversaire(Joueur * j){adversaire = j;}
	void setTilePosition();
	void setFutTilePosition(Direction const dir);
	//geters
	int getTilePosition() const{return tilePosition;};
	sf::Texture *getTexture() const{return texture;};
	//autres methodes
	void decreaseLife(float diff);
	void gravite(Map * map);
	void deplacementImage(Map * map);
	char controleColisionMap(Direction dir, Map * map);
	void mouvement(Map * map);
	void attaqueCourte();
	virtual void setTouche() = 0;

	bool mort();

protected:
	Vie *vie;
	Joueur *adversaire;
	Personnage perso;
	std::map<Touche, bool> actions;//actions lies aux touches
	Direction direction;//direction du mouvement
	float vitesseChute; //vitesse de chute
	int tilePosition; //indice de la tile dans la quelle notre position est
	int futTilePosition; //indice de la future position voulue


	//variables sf
	sf::Texture * texture;
	sf::Sprite sprite;
	sf::Vector2f realPosition;//position reelle dans la map
};