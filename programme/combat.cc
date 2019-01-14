#include <iostream>
#include <SFML/Graphics.hpp>
#include "combat.hh"
#include "map.hh"
#include "rickmap.hh"
#include "p1.hh"
#include "p2.hh"
#include "vie.hh"
#include "cuddles.hh"

Combat::Combat(){
	map = new RickMap();
    Personnage p = Cuddles();
    p1 = new P1(p);
	p2 = new P2(p);
    p1->setAdversaire(p2);
    p2->setAdversaire(p1);
}

Combat::~Combat(){
    delete map;
    //p1 et p2 sont delete dans gameOver
}

/*void Combat::processInput(){

}*/

void Combat::update(){
    p1->update(map);
    p2->update(map);

    if(p1->mort()){
        winner = p2;
        looser = p1;
        nextScreen = 2;
    }
    else if(p2->mort()){
        winner = p1;
        looser = p2;
        nextScreen = 2;
    }
}

void Combat::render(sf::RenderWindow & window){

   sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    window.clear();
    map->drawMap(window);
    //manipulation des joueurs
    p1->render(window);
    p2->render(window);
    window.display();
}