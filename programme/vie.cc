#include <SFML/Graphics.hpp>
#include "vie.hh"

sf::Vector2f operator-(sf::Vector2f const& v, float f){
	return sf::Vector2f(v.x - f, v.y - f);
};

Vie::Vie(float x, float y){
	background = sf::RectangleShape (sf::Vector2f(160, 32));
	background.setFillColor (sf::Color(150, 150, 150));

	//on le rentre dans background
	foreground = sf::RectangleShape (sf::Vector2f(152, 24));
	foreground.setFillColor (sf::Color(100, 255, 100));

	position = sf::Vector2f(x, y);

	background.setPosition(position - 4.f);
	foreground.setPosition(position);

	level = 100.f;

}

void Vie::setLevel(float l){
	level = l;
}

//on change les parametres
void Vie::update(float diff){
	
	level -= diff;
	foreground.setSize(sf::Vector2f(152*level/100.f, 24));
}

void Vie::render(sf::RenderWindow & window){
	window.draw(background);
	window.draw(foreground);
}