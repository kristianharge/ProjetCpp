#pragma once
#include <SFML/Graphics.hpp>
#include "barre.hh"

class Vie : Barre{

public:
	Vie(float x, float y);
	~Vie(){}

	//methods
	void setLevel(float l);
	void update(float diff);
	void render(sf::RenderWindow & window);


};