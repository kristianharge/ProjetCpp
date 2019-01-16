#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "variablesGlobales.hh"
#include "personnage.hh"
#include "vie.hh"
#include "map.hh"
//#include "force.hh"

class Joueur{

public:
	Joueur(Personnage & p);
	virtual ~Joueur();
	//methodes du moteur de jeu
	virtual void processInput() = 0;
	void update(Map * map);
	void render(sf::RenderWindow & w, Map * map);
	//seters
	void setAdversaire(Joueur * j){adversaire = j;}
	//geters
	sf::Vector2f getPosition() const{return realPosition;};
	sf::Texture *getTexture() const{return texture;};
	//autres methodes
	void decreaseLife(float diff);
	bool mort();

private:
	char typeDeTile(sf::Vector2f point, sf::Vector2f dir, Map * map, char axe);
	sf::Vector2f vecteurContraintes(sf::Vector2f dir, Map * map);
	void gravite();
	void mouvement(Map * map);
	void attaqueCourte();

protected:
	Vie *vie;
	Joueur *adversaire;
	Personnage perso;
	std::map<Touche, bool> actions;//actions lies aux touches


	//variables sf
	sf::Texture * texture;
	sf::Sprite sprite;
	sf::Vector2f realPosition;//position reelle dans la map
	sf::Vector2f speedVector;//vecteur vitesse
	std::vector<sf::SoundBuffer> buffers;
	sf::Sound sound;
};