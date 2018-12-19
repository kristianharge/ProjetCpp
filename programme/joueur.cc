#include "joueur.hh"

Joueur::Joueur(Personnage & p){
	perso = &p;//on copie le personnage
	//position = new sf::Vector2f(WIDTH/2, HEIGHT/2);
}