#include <iostream>
#include <unistd.h>
#include <SFML/Graphics.hpp>
#include "combat.hh"
#include "map.hh"
#include "rickmap.hh"

Combat::Combat(){
	map = new RickMap();
	//map->printMap();
}

void Combat::render(sf::RenderWindow & window){

	//texture plus rapide a draw que image mais plus lent a load
	sf::Texture texture;
	if (!texture.loadFromFile("../Images/Perso/Cuddles.png"))
	{
	    std::cout << "Error in line " << __LINE__ << " of file " << __FILE__ << std::endl;
	}
	sf::Sprite cuddles;
	cuddles.setTexture(texture);

    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    window.clear();
    map->drawMap(window);
    usleep(100);
    window.display();
}