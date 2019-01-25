#include "animator.hh"
#include "variablesGlobales.hh"

Animator::Animator(std::string str){
	size = 4;
	textures = (sf::Texture**) malloc(sizeof(sf::Texture*)*size);

	for(int i = 0; i < size; i++){
		textures[i] = new sf::Texture();
		if (!textures[i]->loadFromFile(str + "/" + std::to_string(i) + ".png"))
		{
		    std::cout << "Error in line " << __LINE__ << " of file " << __FILE__ << std::endl;
		}
	}
	sprite = new sf::Sprite();
	animation = 0;
	transition = 0;
	cmp = 0;
	temps = 200000;
}

Animator::~Animator(){
	delete sprite;
	for (int i=0; i < size; i++)
		delete textures[i];
	free(textures);
}

void Animator::update(){//a est comme animation
	if(transition == 1 || transition == 2){//attaque sur le côté
		cmp = temps;
		animation = transition;
		transition = 0;
	} else if (cmp <= 0 || transition == 3){
		animation = transition;
	}

	if(cmp > 0)
		cmp -= US_PER_FRAME;
}

void Animator::render(sf::Vector2f position, sf::RenderWindow & w){
	sprite->setTexture(*textures[animation]);
	sprite->setPosition(position);
	w.draw(*sprite);
}