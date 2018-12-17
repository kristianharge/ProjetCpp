#include <stdlib.h>
#include <iostream>
#include "map.hh"

Map::Map(){
    taille[0] = WIDTH/COTE;
    taille[1] = HEIGHT/COTE;
}

Map::~Map(){
}

void Map::printMap() const{
    int i,j;

    for (i = 0; i < taille[1]; i++){
        for (j = 0; j < taille[0]; j++){
            std::cout << (int) matrix[i*taille[0] + j].first;
        }
        std::cout << std::endl;
    }
}

void Map::drawMap(sf::RenderWindow & window){
    int i;

    for (i = 0; i < taille[0]*taille[1]; i++){
        sf::Sprite sp;
        sp.setTexture(textures[matrix[i].first]);
        sp.setPosition(matrix[i].second);   
        window.draw(sp);
    }
}