#include "accueil.hh"

Accueil::Accueil(sf::RenderWindow & window){
	window.clear();
	sf::Texture bgTexture;

	if (!bgTexture.loadFromFile("../Images/accueil.PNG"))
	{
	    std::cout << "Error in line " << __LINE__ << " of file " << __FILE__ << std::endl;
	    
	}
	sf::Sprite bgSprite(bgTexture);
	window.draw(bgSprite);
	
	//update
	music = new sf::Music();

    if (!music->openFromFile("../musique/MainSuperSmash.ogg"))
        std::cout << "Error in line " << __LINE__ << " of file " << __FILE__ << std::endl;

    music->play();
	
	window.display();
}

Accueil::~Accueil(){
	delete music;
	
}

void Accueil::processInput(){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		nextScreen = 1;
	}
}


void Accueil::render(sf::RenderWindow & window){

   sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}


		
 
