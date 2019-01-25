#include <iostream>
#include <SFML/Graphics.hpp>
#include "combat.hh"
#include "map.hh"
#include "rickmap.hh"
#include "p1.hh"
#include "p2.hh"
#include "vie.hh"
#include "cuddles.hh"
#include "simpmap.hh"



Combat::Combat(Personnage * pp1, Personnage * pp2, Map * m){
    map = m;
    p1 = new P1(pp1);
    p2 = new P2(pp2);
    p1->setAdversaire(p2);
    p2->setAdversaire(p1);
    music = new sf::Music();

    if (!music->openFromFile("../musique/CombatStarWars.ogg"))
        std::cout << "Error in line " << __LINE__ << " of file " << __FILE__ << std::endl;

    music->play();
}

Combat::~Combat(){
    delete map;
    //p1 et p2 sont delete dans gameOver
}

void Combat::processInput(){
    p1->processInput();
    p2->processInput();
}

void Combat::update(){
    p1->update(map);
    p2->update(map);

    if(p1->mort()){
        winner = p2;
        looser = p1;
        nextScreen = 4;
    }
    else if(p2->mort()){
        winner = p1;
        looser = p2;
        nextScreen = 4;
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
    p1->render(window, map);
    p2->render(window, map);
    window.display();
}
