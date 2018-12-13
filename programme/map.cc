#include <stdlib.h>
#include <iostream>
#include "map.hh"
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

void Map::printMap(){
    int i,j;

    for (i = 0; i < taille[1]; i++){
        for (j = 0; j < taille[0]; j++){
            std::cout << (int)*(matrix + i + j);
        }
        std::cout << std::endl;
    }
}