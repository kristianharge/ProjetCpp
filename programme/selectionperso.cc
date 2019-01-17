#include "selectionperso.hh"


SelectionPerso::SelectionPerso(sf::RenderWindow & window){
	nbPerso = 4;//nombre de personnages
	int width = 300, height = 300;

	window.clear();
	positions = (sf::Vector2f*) malloc(sizeof(sf::Vector2f)*nbPerso);
	positions[0] = sf::Vector2f(-width/2, -height/2);
	positions[1] = sf::Vector2f(width/2, -height/2);
	positions[2] = sf::Vector2f(-width/2, height/2);
	positions[3] = sf::Vector2f(width/2, height/2);

	flechesPos = 0;
	qsdzPos = 1;
	/*sf::Texture bgTexture;

	if (!bgTexture.loadFromFile("../Images/SelectionPerso.png"))
	{
	    std::cout << "Error in line " << __LINE__ << " of file " << __FILE__ << std::endl;
	}
	sf::Sprite bgSprite(bgTexture);
	window.draw(bgSprite);*/
	//update
	window.display();
}

SelectionPerso::~SelectionPerso(){
	free(positions);
}


void SelectionPerso::render(sf::RenderWindow & window){
	window.clear();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		if(flechesPos - qsdzPos == 1 || (qsdzPos == nbPerso - 1 && flechesPos == 0)){//on est juste à droite
			if(flechesPos == 0)
				flechesPos = nbPerso - 2;
			else if(flechesPos == 1)
				flechesPos = nbPerso - 1;
			else
				flechesPos -= 2;
		}
		else{
			if(flechesPos == 0)
				flechesPos = nbPerso - 1;
			else
				flechesPos--;
		}
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		if(flechesPos - qsdzPos == -1 || (qsdzPos == 0 && flechesPos == nbPerso - 1)){//on est juste à gauche
			if(flechesPos == nbPerso - 1)
				flechesPos = 2;
			else if(flechesPos == nbPerso - 1)
				flechesPos = 1;
			else
				flechesPos += 2;
		}
		else{
			if(flechesPos == nbPerso - 1)
				flechesPos = 0;
			else
				flechesPos++;
		}
	}
	flechesSelector.setTexture(flechesTexture);
	flechesSelector.setPosition(positions[flechesPos]);
	window.draw(flechesSelector);
	window.display();

   sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}