#include <stdlib.h>
#include "RickMap.hh"
#define WIDTH 1200
#define HEIGHT 800
#define COTE 40

Map::Map(){
    taille[0] = WIDTH/COTE;
    taille[1] = HEIGHT/COTE;
    matrix =(char*) malloc(taille[0]*taille[1]*sizeof(char));//tableau des differents motifs
}

Map::~Map(){
    free(matrix);
}