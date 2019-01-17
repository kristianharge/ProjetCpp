#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include "joueur.hh"
#include "variablesGlobales.hh"

//pour le debug
std::ostream &operator<<(std::ostream & out, sf::Vector2f v){
	return out << "x= " << v.x << " y= " << v.y;
};

std::ostream &operator<<(std::ostream & out, Direction & d){
	switch(d){
		case n:
			return out << "nord";
		case ne:
			return out << "nord est";
		case e:
			return out << "est";
		case se:
			return out << "sud est";
		case s:
			return out << "sud";
		case sw:
			return out << "sud ouest";
		case w:
			return out << "ouest";
		case nw:
			return out << "nord ouest";
		default:
			return out << "null";
	}
};

Joueur::Joueur(Personnage & p){
	perso = p;//on copie le personnage
	
	//on initialise les touches
	actions[gauche] = false;
	actions[droite] = false;
	actions[haut] = false;
	actions[bas] = false;

	speedVector = sf::Vector2f(0.f,0.f);
	buffers.push_back(sf::SoundBuffer());

	if (!buffers[0].loadFromFile("../musique/Sounds/punch.wav"))
    std::cout << "Error in line " << __LINE__ << " of file " << __FILE__ << std::endl;

	anim = new Animator(std::string("../Images/Perso/Cuddles"));
}

Joueur::~Joueur(){
	delete anim;
	delete vie;
};

//methods
void Joueur::decreaseLife(float diff){
	if(vie->getLevel() - diff < 0)
		vie->setLevel(0);
		//gameover
	else
		vie->update(diff);
}

//on applique les affets de la gravite
void Joueur::gravite(){
	float g = 0.1f;
	
	if(speedVector.y != 4.f)
		speedVector.y += g;
	
}

char Joueur::typeDeTile(sf::Vector2f point, sf::Vector2f dir, Map * map, char axe){
	//on renvoi la valeur de la tile sur l'axe demmandé
	sf::Vector2f futpos = point + dir;
	char nbtile;

	if(axe == 'x'){
		nbtile = map->numberOfTile(sf::Vector2f((futpos).x, point.y));
	}
	else if(axe == 'y'){
		nbtile = map->numberOfTile(sf::Vector2f(point.x, (futpos).y));
	}
	else{
		std::cout << "Erreur dans les axes " << __LINE__ << " " << __FUNCTION__ << std::endl;
		return 255;
	}

	if(nbtile > 99)//traversable
			return 1;
	else if(nbtile < 50)//vide
		return 0;
	else if(nbtile > 49 && nbtile < 100)//solide
		return 2;
	else{
		std::cout << "Erreur dans la tile " << __LINE__ << " " << __FUNCTION__ << std::endl;
		return 255;
	}
}

sf::Vector2f Joueur::vecteurContraintes(sf::Vector2f dir, Map * map){
	sf::Vector2f contrainte(0.f,0.f);
	bool cx = false, cy = false;

	for(int i = 0; i < 3; i++){
		for (int j = 0; j < 4; j++){
			if(typeDeTile(realPosition + sf::Vector2f(i*COTE, j*COTE), dir, map, 'x') == 2 ||
			 typeDeTile(realPosition + sf::Vector2f(i*COTE, j*COTE), dir, map, 'x') == 1)//alors contrainte sur x
				cx = true;
			if(typeDeTile(realPosition + sf::Vector2f(i*COTE, j*COTE), dir, map, 'y') == 2 ||
			typeDeTile(realPosition + sf::Vector2f(i*COTE, j*COTE), dir, map, 'y') == 1)//alors contrainte sur y
				cy = true;
		}
	}
	if(cx)//alors contrainte sur x
		contrainte += sf::Vector2f(-dir.x, 0.f);
	if(cy)
		contrainte += sf::Vector2f(0.f, -dir.y);
	return contrainte;
}

void Joueur::mouvement(Map * map){
	//speedVector = sf::Vector2f(0.f,0.f);
	speedVector.x = 0.f;
	gravite();//gravité
	if(actions[gauche]){
		speedVector.x = -4.f; 
	}
	else if(actions[droite]){
		speedVector.x = 4.f; 
	}

	if(actions[haut]){
		if(vecteurContraintes(speedVector, map).y < 0.f){//contrainte vers le haut donc on touche par terre
			speedVector += sf::Vector2f(0.f,-5.f);
		}
	}

	//on mets a jour avec les contraintes
	speedVector += vecteurContraintes(speedVector, map);
	realPosition += speedVector;

}

void Joueur::attaqueCourte(){
	sf::Vector2f positionCible = adversaire->getPosition();

	if(actions[ac]){
		//on agis sur une tile adjacente
		if(positionCible.x + TAILLEPERSO_X + COTE >= realPosition.x && positionCible.x <= realPosition.x + TAILLEPERSO_X + COTE)//traitement horizontal
			if(positionCible.y + TAILLEPERSO_Y >= realPosition.y &&	positionCible.y <= realPosition.y + TAILLEPERSO_Y){//traitement vertical
				sound.setBuffer(buffers[0]);
				sound.play();
				adversaire->decreaseLife(perso.getPtsAttaque());
			}
	}
}

//on traite la dinamique (mouvements, vie, etc)
void Joueur::update(Map * map){
	vie->update(0.f);//on rafraichit la vie
	mouvement(map);
	attaqueCourte();
}

void Joueur::render(sf::RenderWindow & w, Map * map){
	vie->render(w);
	anim->render(realPosition,w);
}

bool Joueur::mort(){
	if (vie->getLevel() == 0)
		return true;
	return false;
}