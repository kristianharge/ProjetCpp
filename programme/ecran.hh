#pragma once

class Ecran{

public:
	Ecran(){};
	virtual ~Ecran(){};
	
	virtual void processInput() = 0;
	virtual void update() = 0;
	virtual void render(sf::RenderWindow & window) = 0;
};