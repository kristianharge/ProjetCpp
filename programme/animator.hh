#include <SFML/Graphics.hpp>
#include <iostream>


class Animator{
	public:
		Animator(std::string str);//path du dossier incluant les images
		~Animator();
		void render(sf::Vector2f position, sf::RenderWindow & w);
	private:
		sf::Texture ** textures;
		sf::Sprite *sprite;
		int size;
};