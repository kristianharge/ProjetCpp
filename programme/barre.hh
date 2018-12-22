#pragma once
#include <SFML/Graphics.hpp>

class Barre{

public:
	Barre(){}
	~Barre(){}
	virtual void update(float diff) = 0;
	virtual void render(sf::RenderWindow & window) = 0;

protected:
	sf::RectangleShape background;
	sf::RectangleShape foreground;
	sf::Vector2f position;
	float level;

};