#include <SFML/Graphics.hpp>
#include <iostream>




class Animator{
	public:
		Animator(std::string str);//path du dossier incluant les images
		~Animator();
		void update();
		void render(sf::Vector2f position, sf::RenderWindow & w);

		int transition; //0 normal, 1 attaque droite, 2 attaque gauche, 3 game over
	private:
		sf::Texture ** textures;
		sf::Sprite *sprite;
		int size;
		int cmp; //compteur pour animation en secondes
		int temps; //temps animation secondes
		int animation; //0 normal, 1 attaque droite, 2 attaque gauche, 3 game over
};