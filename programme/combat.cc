#include <iostream>
#include <SFML/Graphics.hpp>
#include "combat.hh"
#include "map.hh"
#include "rickmap.hh"
#include "p1.hh"
#include "vie.hh"
#include "cuddles.hh"

Combat::Combat(){
	map = new RickMap();
    Personnage p = Cuddles();
    p1 = new P1(p);
	//p2 = new Joueur();
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
    p1->update(map);
    p1->render(window);
    window.display();

    //Tests
    //std::cout << (int)map->numberOfTile(sf::Vector2f(0,32)) << std::endl;
}