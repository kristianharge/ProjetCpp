#pragma once
#include <SFML/Graphics.hpp>
#include "barre.hh"

class Vie : public Barre{

public:
	Vie(float x, float y);//position de la vie
	~Vie(){}

	//methods
	void update(float diff);
	void render(sf::RenderWindow & window);


};