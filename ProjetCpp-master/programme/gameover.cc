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
	//update
	window.display();
}

GameOver::~GameOver(){
	delete winner;
	delete looser;
}


void GameOver::render(sf::RenderWindow & window){

   sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}
