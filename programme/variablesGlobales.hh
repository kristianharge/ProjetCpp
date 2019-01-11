#pragma once
#include <SFML/Graphics.hpp>
#define US_PER_FRAME 16000
#define WIDTH 1600 //taille map en pixels
#define HEIGHT 960
#define TILEDWIDTH 50 //taile map en tiles
#define TILEDHEIGHT 40
#define COTE 32
#define TAILLEPERSO_Y 96 //taille perso en pixels
#define TAILLEPERSO_X 64
#define TILEDTAILLEPERSO_Y 3 //taille perso en tiles
#define TILEDTAILLEPERSO_X 2
#define GRAVITY 0.2f

enum Touche {gauche, haut, droite, bas, ac};
enum Direction {n, ne, e, se, s, sw, w, nw, null};//les hit directions du mouvement
