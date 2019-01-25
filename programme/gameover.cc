#include "gameover.hh"


GameOver::GameOver(sf::RenderWindow & window, Joueur * winner, Joueur * looser) : winner(winner), looser(looser){
	window.clear();
	sf::Texture bgTexture;

	if (!bgTexture.loadFromFile("../Images/GameOver.png"))
	{
	    std::cout << "Error in line " << __LINE__ << " of file " << __FILE__ << std::endl;
	}
	sf::Sprite bgSprite(bgTexture);
	window.draw(bgSprite);
	//draw winner and looser
	winner->anim->render(sf::Vector2f((float)WIDTH/4, (float)HEIGHT/2), window);
	looser->anim->render(sf::Vector2f((float)3*WIDTH/4, (float)HEIGHT/2), window);

	//Instructions
	sf::Font font;
	if(!font.loadFromFile("BOUSTOWN SANS.ttf")){
		std::cout << "Error in line " << __LINE__ << " of file " << __FILE__ << std::endl;
	}
	sf::Text inst("Appuyez entre", font, 100);
	sf::FloatRect textRect = inst.getLocalBounds();
	inst.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
	inst.setPosition(sf::Vector2f(WIDTH/2, 3*HEIGHT/4));
	window.draw(inst);
	music = new sf::Music();

    if (!music->openFromFile("../musique/CombatStarWars.ogg"))
        std::cout << "Error in line " << __LINE__ << " of file " << __FILE__ << std::endl;

    music->play();
	//update
	window.display();
}

GameOver::~GameOver(){
	delete winner;
	delete looser;
}


void GameOver::render(sf::RenderWindow & window){

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
		nextScreen = 0;
	}

   sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}