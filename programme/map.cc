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
    sf::Sprite sp;

    for (i = 0; i < taille[0]*taille[1]; i++){
        //std::cout << " x: " << matrix[i].second.x << " y: " << matrix[i].second.y;
        sp.setTexture(textures.find(matrix[i].first)->second);
        sp.setPosition(matrix[i].second);
        window.draw(sp);
    }
    //std::cout << std::endl;
}

char Map::numberOfTile(sf::Vector2f const & v){
    int x, y;//coordonees en numero de tile

    x = v.x/COTE;
    y = v.y/COTE;

    return matrix[x + y*taille[0]].first;
}