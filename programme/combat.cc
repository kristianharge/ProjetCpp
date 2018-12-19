#include <iostream>
#include <SFML/Graphics.hpp>
#include "combat.hh"
#include "map.hh"
#include "rickmap.hh"
#include "joueur.hh"

Combat::Combat(){
	map = new RickMap();
	//p1 = new Joueur();
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
    window.display();
}