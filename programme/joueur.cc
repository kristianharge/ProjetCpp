#include <SFML/Graphics.hpp>
#include "joueur.hh"
#include "variablesGlobales.hh"

Joueur::Joueur(Personnage & p){
	perso = p;//on copie le personnage
	direction = sf::Vector2f(0.f,0.f);
	
	//on initialise les touches
	actions[gauche] = false;
	actions[droite] = false;
	actions[haut] = false;
	actions[bas] = false;
}

//methods
//on applique les affets de la gravite
void Joueur::gravite(Map * map){
	
	//si je peux tomber, alors je tombe.
	if(map->numberOfTile(sf::Vector2f(position.x + TAILLEPERSO_X/2, position.y + TAILLEPERSO_Y)) < 50){
		if(direction.y < 400)//on limite la vitesse de chute
			direction.y += 5;
	}
	else {
		direction.y = 0;
	}
}


char Joueur::controleColisionMap(Touche cote, Map * map){
	//on regarde si le joueur est en contact avec le cote cote, 0 => non, 1=>traversable, 2 => solide
	int i, size = 8, ptsSol = 0, ptsTrav = 0;
	sf::Vector2f cnt[size];//2 points de chaque cote plus 2 au milieu
	sf::Vector2f futPos = position + direction*((float)US_PER_FRAME/1000000); //position a la prochaine frame


	switch(cote){//initialisation des ponts qu'on veut observer
		case haut:
			for(i = 0; i < 3; i++){//initialisation à gauche
				cnt[i] = futPos;
				cnt[i].x += 8*i;
			}
			cnt[3] = sf::Vector2f(futPos.x + COTE-1, futPos.y);
			cnt[4] = sf::Vector2f(futPos.x + COTE+1, futPos.y);
			for(i = 0; i < 3; i++){//initialisation à droite
				cnt[size - i - 1] = sf::Vector2f(futPos.x + TAILLEPERSO_X - 8*i, futPos.y);
			}
			break;
		case bas:
			for(i = 0; i < 3; i++){//initialisation à gauche
				cnt[i] = sf::Vector2f(futPos.x + 8*i, futPos.y + TAILLEPERSO_Y);
			}
			cnt[3] = sf::Vector2f(futPos.x + COTE-1, futPos.y + TAILLEPERSO_Y);
			cnt[4] = sf::Vector2f(futPos.x + COTE+1, futPos.y + TAILLEPERSO_Y);
			for(i = 0; i < 3; i++){//initialisation à droite
				cnt[size - i - 1] = sf::Vector2f(futPos.x + TAILLEPERSO_X - 8*i, futPos.y + TAILLEPERSO_Y);
			}
			break;
		case gauche:
			for(i = 0; i < 3; i++){//initialisation en haut
				cnt[i] = sf::Vector2f(futPos.x, futPos.y + 8*i);
			}
			cnt[3] = sf::Vector2f(futPos.x, futPos.y + COTE);
			cnt[4] = sf::Vector2f(futPos.x, futPos.y + 2*COTE);
			for(i = 0; i < 3; i++){//initialisation en bas
				cnt[size - i - 1] = sf::Vector2f(futPos.x, futPos.y + TAILLEPERSO_Y - 8*i);
			}
			break;
		case droite:
			for(i = 0; i < 3; i++){//initialisation en haut
				cnt[i] = sf::Vector2f(futPos.x + TAILLEPERSO_X, futPos.y + 8*i);
			}
			cnt[3] = sf::Vector2f(futPos.x + TAILLEPERSO_X, futPos.y + COTE);
			cnt[4] = sf::Vector2f(futPos.x + TAILLEPERSO_X, futPos.y + 2*COTE);
			for(i = 0; i < 3; i++){//initialisation en bas
				cnt[size - i - 1] = sf::Vector2f(futPos.x + TAILLEPERSO_X, futPos.y + TAILLEPERSO_Y - 8*i);
			}
			break;
	}
	//observation
	for(int i = 0; i < 3; i++){
		char tile = map->numberOfTile(cnt[i]);
		if( tile > 49){//cas ou on peux pas monter, alors on rebondis
			if(tile < 100)
				ptsSol++;
			else
				ptsTrav++;
		}
	}
	if((map->numberOfTile(cnt[i]) > 49 && map->numberOfTile(cnt[i]) < 100)){
		return 2;
	}
	for(int i = 0; i < 3; i++){
		char tile = map->numberOfTile(cnt[i]);
		if( tile > 49){//cas ou on peux pas monter, alors on rebondis
			if(tile < 100)
				ptsSol++;
			else
				ptsTrav++;
		}
	}
	if(ptsSol >= 3)
		return 2;
	else if(ptsTrav >= 3)
		return 1;
	else
		return 0;

}

void Joueur::mouvement(Map * map){

	if(controleColisionMap(haut, map) == 2){//cas ou on peux pas monter, alors on rebondis
		actions[haut] = false;
		direction.y = 0;
	}

	//on regarde si on peux aller vers la gauche
	if(controleColisionMap(gauche, map) != 0){//cas ou on peux pas aller a gauche
		actions[gauche] = false;
	}

	//on regarde si on peux aller vers la droite
	if(controleColisionMap(droite, map) != 0){//cas ou on peux pas aller a droite
		actions[droite] = false;
	}

	//on bouge
	if(actions[gauche])
		direction.x = -200.f;
	else if(actions[droite])
		direction.x = 200.f;
	else
		direction.x = 0.f;

	if(actions[haut]){
		//je regarde si je touche par terre
		if(controleColisionMap(bas, map) != 0)
			direction.y = -250.f;
	}

	if(actions[bas]){
		//je regarde si je touche par terre
		if(controleColisionMap(bas, map) != 0){//dans ce cas on regarde s'il y a asses d'espace pour traverser
			std::cout << "bas" << std::endl;
			sf::Vector2f newPos = position + sf::Vector2f(0.f, 2*TAILLEPERSO_Y + COTE);
			if(map->numberOfTile(newPos) > 49)
				position.y += TAILLEPERSO_Y + COTE;
		}
		else{ //dans ce cas on accelere notre descente
			direction.y = 400;
		}
	}
}

//on traite la dinamique (mouvements, vie, etc)
void Joueur::update(Map * map){
	vie->update(0.f);//on rafraichit la vie
	setTouche();
	gravite(map);//on applique la gravite
	//std::cout << direction.y << std::endl;
	mouvement(map);

	//on bouge le perso
	position = position + direction*((float)US_PER_FRAME/1000000);//on mets en frames
}

void Joueur::render(sf::RenderWindow & w){
	vie->render(w);
	sprite.setTexture(texture);
	sprite.setPosition(position);
	w.draw(sprite);
}