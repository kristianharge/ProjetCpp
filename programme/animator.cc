#include "animator.hh"

Animator::Animator(std::string str){
	size = 1;
	textures = (sf::Texture**) malloc(sizeof(sf::Texture*)*size);
	textures[0] = new sf::Texture();
	if (!textures[0]->loadFromFile(str + "/0.png"))
	{
	    std::cout << "Error in line " << __LINE__ << " of file " << __FILE__ << std::endl;
	}
	sprite = new sf::Sprite();
}

Animator::~Animator(){
	delete sprite;
	for (int i=0; i < size; i++)
		delete textures[i];
	free(textures);
}

void Animator::render(sf::Vector2f position, sf::RenderWindow & w){
	sprite->setTexture(*textures[0]);
	sprite->setPosition(position);
	w.draw(*sprite);
}