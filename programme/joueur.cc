#include <SFML/Graphics.hpp>
#include <cmath>
#include "joueur.hh"
#include "variablesGlobales.hh"

//pour le debug
std::ostream &operator<<(std::ostream & out, sf::Vector2f & v){
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
	direction = null;
	
	//on initialise les touches
	actions[gauche] = false;
	actions[droite] = false;
	actions[haut] = false;
	actions[bas] = false;
}

//methods
void Joueur::decreaseLife(float diff){
	if(vie->getLevel() - diff < 0)
		vie->setLevel(0);
		//gameover
	else
		vie->update(diff);
}

//on applique les affets de la gravite
void Joueur::gravite(Map * map){

	//si je peux tomber, alors je tombe.
	if(controleColisionMap(s, map) == 0 || controleColisionMap(s, map) == 0){
		if(vitesseChute < 7)//on limite la vitesse de chute
			vitesseChute += GRAVITY;
	}
	else if(vitesseChute > 0.f){
		vitesseChute = 0.f;
	}
}

char Joueur::controleColisionMap(Direction dir, Map * map){
	//on regarde sur quelle tile serait le joueur, 0 => vide, 1=>traversable, 2 => solide
	std::vector<char> ftt = std::vector<char>();//futur tile type
	std::vector<char>::iterator it;
	bool travesable = false;//indique si on a un traversable


	switch(dir){//on regarde le tile au quel on va se deplacer
		case n:
			if(tilePosition >= TILEDWIDTH){//si on reste dans la map
				ftt.push_back( map->typeDeTileParIndex(tilePosition - TILEDWIDTH) );
				ftt.push_back( map->typeDeTileParIndex(tilePosition - TILEDWIDTH + 1) );
			} else {
				return 2; //cest le haut de la carte
			}
			break;
		case ne:
			if(tilePosition >= TILEDWIDTH && tilePosition % TILEDWIDTH < TILEDWIDTH - 1){//si on reste dans la map
				ftt.push_back( map->typeDeTileParIndex(tilePosition - TILEDWIDTH + TILEDTAILLEPERSO_X) );
				ftt.push_back( map->typeDeTileParIndex(tilePosition + TILEDTAILLEPERSO_X) );
				ftt.push_back( map->typeDeTileParIndex(tilePosition + TILEDWIDTH + TILEDTAILLEPERSO_X) );
			} else {
				return 2; //cest le haut de la carte
			}
			break;
		case e:
			if(tilePosition % TILEDWIDTH < TILEDWIDTH - 1){//si on reste dans la map
				ftt.push_back( map->typeDeTileParIndex(tilePosition + TILEDTAILLEPERSO_X) );
				ftt.push_back( map->typeDeTileParIndex(tilePosition + TILEDTAILLEPERSO_X + TILEDWIDTH) );
				ftt.push_back( map->typeDeTileParIndex(tilePosition + TILEDTAILLEPERSO_X + 2*TILEDWIDTH) );
			} else {
				return 2; //cest la droite de la carte
			}
			break;
		case se:
			if(tilePosition % TILEDWIDTH < TILEDWIDTH - 1 && tilePosition < TILEDWIDTH*TILEDHEIGHT){//si on reste dans la map
				ftt.push_back( map->typeDeTileParIndex(tilePosition + TILEDTAILLEPERSO_X + TILEDWIDTH) );
				ftt.push_back( map->typeDeTileParIndex(tilePosition + TILEDTAILLEPERSO_X + 2*TILEDWIDTH) );
				ftt.push_back( map->typeDeTileParIndex(tilePosition + TILEDTAILLEPERSO_X + 3*TILEDWIDTH) );
			} else {
				if(tilePosition >= TILEDWIDTH*TILEDHEIGHT)
					vie->setLevel(0.f);
				return 2; //cest la droite de la carte
			}
			break;
		case s:
			if(tilePosition < TILEDWIDTH*TILEDHEIGHT){//si on reste dans la map
				ftt.push_back( map->typeDeTileParIndex(tilePosition + TILEDTAILLEPERSO_Y*TILEDWIDTH) );
				ftt.push_back( map->typeDeTileParIndex(tilePosition + TILEDTAILLEPERSO_Y*TILEDWIDTH + 1) );
			} else {
				vie->setLevel(0.f);//on tombe, on est mort
				return 2;
			}
			break;
		case sw:
			if(tilePosition > 0 && tilePosition < TILEDWIDTH*TILEDHEIGHT){//si on reste dans la map
				ftt.push_back( map->typeDeTileParIndex(tilePosition + TILEDWIDTH - 1) );
				ftt.push_back( map->typeDeTileParIndex(tilePosition + 2*TILEDWIDTH - 1) );
				ftt.push_back( map->typeDeTileParIndex(tilePosition + 3*TILEDWIDTH - 1) );
			} else {
				if(tilePosition >= TILEDWIDTH*TILEDHEIGHT)
					vie->setLevel(0.f);
				return 2; //cest la droite de la carte
			}
			break;
		case w:
			if(tilePosition % TILEDWIDTH > 0){//si on reste dans la map
				ftt.push_back( map->typeDeTileParIndex(tilePosition - 1) );
				ftt.push_back( map->typeDeTileParIndex(tilePosition + TILEDWIDTH - 1) );
				ftt.push_back( map->typeDeTileParIndex(tilePosition + 2*TILEDWIDTH - 1) );
			} else {
				return 2; //cest la droite de la carte
			}
			break;
		case nw:
			if(tilePosition > 0 && tilePosition >= TILEDWIDTH){//si on reste dans la map
				ftt.push_back( map->typeDeTileParIndex(tilePosition - TILEDWIDTH - 1) );
				ftt.push_back( map->typeDeTileParIndex(tilePosition - 1) );
				ftt.push_back( map->typeDeTileParIndex(tilePosition + TILEDWIDTH - 1) );
			} else {
				return 2; //cest la droite de la carte
			}
			break;
		default:
			return -1;//on bouge pas
	}

	for (it = ftt.begin(); it != ftt.end(); it++){
		if( *it > 49 && *it < 100)//si la taile est solide
			return 2;
		else if( *it > 99 || *it > 99)//cest un traversable
			travesable = true;
			
	}
	if(travesable)
		return 1;
	else
		return 0;
}

void Joueur::setFutTilePosition(Direction const dir){
	switch(dir){
		case n:
			futTilePosition = tilePosition - TILEDWIDTH;
			break;
		case ne:
			futTilePosition = tilePosition - TILEDWIDTH + 1;
			break;
		case e:
			futTilePosition = tilePosition + 1;
			break;
		case se:
			futTilePosition = tilePosition + TILEDWIDTH + 1;
			break;
		case s:
			futTilePosition = tilePosition + TILEDWIDTH;
			break;
		case sw:
			futTilePosition = tilePosition + TILEDWIDTH - 1;
			break;
		case w:
			futTilePosition = tilePosition - 1;
			break;
		case nw:
			futTilePosition = tilePosition - TILEDWIDTH - 1;
			break;
		default:
			break;
	}
}

void Joueur::deplacementImage(Map * map){
	sf::Vector2f futPosition = sf::Vector2f((futTilePosition % TILEDWIDTH)*COTE, (futTilePosition/TILEDWIDTH)*COTE);
	sf::Vector2f delta = futPosition - realPosition;

	if(realPosition != futPosition){
		if(direction != e && direction != w){
			if(vitesseChute > 0){//cest uniquement un multiplicateur dans le cas du deplacement
				if(direction != s)
					realPosition += delta/((float) sqrt(pow(delta.x, 2) + pow(delta.y, 2)))*vitesseChute*1.5f;//pas idéal mais rapide
				else
					realPosition += delta/((float) sqrt(pow(delta.x, 2) + pow(delta.y, 2)))*vitesseChute;
			}
			else{
				if(direction != n)
					realPosition += delta/((float) sqrt(pow(delta.x, 2) + pow(delta.y, 2)))*(-vitesseChute)*1.5f;
				else
					realPosition += delta/((float) sqrt(pow(delta.x, 2) + pow(delta.y, 2)))*(-vitesseChute);
			}
		}
		else
			realPosition += delta/((float) sqrt(pow(delta.x, 2) + pow(delta.y, 2)))*perso.getVitesse();

		if(sqrt(pow(delta.x, 2) + pow(delta.y, 2)) <= vitesseChute || sqrt(pow(delta.x, 2) + pow(delta.y, 2)) <= perso.getVitesse()){
		//alors on est le plus pres de la position
			realPosition = sf::Vector2f((futTilePosition % TILEDWIDTH)*COTE, (futTilePosition/TILEDWIDTH)*COTE);
			tilePosition = futTilePosition;
		}
	}

}

void Joueur::mouvement(Map * map){

	gravite(map);
	setTouche();
	if(actions[gauche]){
		if(vitesseChute > 0)
			direction = sw;
		else if (vitesseChute == 0)
			direction = w;
		else
			direction = nw;
	}
	else if(actions[droite]){
		if(vitesseChute > 0)
			direction = se;
		else if (vitesseChute == 0)
			direction = e;
		else
			direction = ne;
	}
	else 
		if(vitesseChute > 0)
			direction = s;
		else if (vitesseChute < 0)
			direction = n;
		else
			direction = null;
	if(actions[haut]){
		if(controleColisionMap(s, map) != 0){
			vitesseChute = -6.19f;
		}
	}
	else if(actions[bas]){
		if(controleColisionMap(s, map) == 0 && !actions[gauche] && !actions[droite])
			vitesseChute = 10.f;
		else if (controleColisionMap(s, map) == 1);//TODO : traversable
	}
		//std::cout << (int)controleColisionMap(direction, map) << std::endl;
	if(controleColisionMap(direction, map) == 0){
		if(futTilePosition == tilePosition)
			setFutTilePosition(direction);
	}
	else if (controleColisionMap(direction, map) == 1){
		if((direction == n || direction == ne || direction == nw) && controleColisionMap(n, map) == 1)
			setFutTilePosition(direction);
		else if((direction == s || direction == se || direction == sw) && controleColisionMap(s, map) == 1)
			futTilePosition = tilePosition - TILEDWIDTH*(TILEDTAILLEPERSO_Y+1);
	}


	deplacementImage(map);

}

void Joueur::setTilePosition(){
	tilePosition = realPosition.x/COTE + WIDTH*realPosition.y/(COTE*COTE);
}

void Joueur::attaqueCourte(){
	int positionCible = adversaire->getTilePosition();

	if(actions[ac]){
		//on agis sur une tile adjacente
		if(positionCible % TILEDWIDTH + TILEDTAILLEPERSO_X >= tilePosition % TILEDWIDTH &&
			positionCible % TILEDWIDTH <= tilePosition % TILEDWIDTH + TILEDTAILLEPERSO_X)//traitement horizontal
			if(positionCible / TILEDWIDTH + TILEDTAILLEPERSO_Y >= tilePosition / TILEDWIDTH &&
			positionCible / TILEDWIDTH <= tilePosition / TILEDWIDTH + TILEDTAILLEPERSO_Y){//traitement vertical
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

void Joueur::render(sf::RenderWindow & w){
	vie->render(w);
	sprite.setTexture(texture);
	sprite.setPosition(realPosition);
	w.draw(sprite);
}

void Joueur::mort(){
	if (vie->getLevel() == 0)
		;
}