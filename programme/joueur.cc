#include <SFML/Graphics.hpp>
#include "joueur.hh"
#include "variablesGlobales.hh"

Joueur::Joueur(Personnage & p){
	perso = p;//on copie le personnage
	direction = sf::Vector2f(0.f,0.f);
	//position = new sf::Vector2f(WIDTH/2, HEIGHT/2);
}

//methods
//on applique les affets de la gravite
void Joueur::gravite(Map * map){
	
	//si je peux tomber, alors je tombe.
	if(map->numberOfTile(sf::Vector2f(position.x, position.y + TAILLEPERSO_Y)) < 50 || 
		map->numberOfTile(sf::Vector2f(position.x + TAILLEPERSO_X, position.y + TAILLEPERSO_Y)) < 50){
		if(direction.y <= 400)//on limite la vitesse de chute
			direction.y += 5;
	}
	else {
		direction.y = 0;
	}
}

//on traite la dinamique (mouvements, vie, etc)
void Joueur::update(Map * map){
	vie->update(0.f);//on rafraichit la vie
	gravite(map);//on applique la gravite
	bouger(map);

	//on bouge le perso
	position = position + direction*((float)US_PER_FRAME/1000000);

}

void Joueur::render(sf::RenderWindow & w){
	vie->render(w);

	sprite.setTexture(texture);
	sprite.setPosition(position);
	w.draw(sprite);
}