#include "selectionperso.hh"


SelectionPerso::SelectionPerso(sf::RenderWindow & window){
	nbPerso = 4;//nombre de personnages
	int width = 300, height = 300;

	//window.clear();
	positions = (sf::Vector2f*) malloc(sizeof(sf::Vector2f)*nbPerso);
	positions[0] = sf::Vector2f(WIDTH/2 - width, HEIGHT/2 - height);
	positions[1] = sf::Vector2f(WIDTH/2, HEIGHT/2 - height);
	positions[2] = sf::Vector2f(WIDTH/2 - width, HEIGHT/2);
	positions[3] = sf::Vector2f(WIDTH/2, HEIGHT/2);

	flechesPos = 0;
	qsdzPos = 1;

	if (!flechesTexture.loadFromFile("../Images/SelectionPerso/arrowselector.png"))
	{
	    std::cout << "Error in line " << __LINE__ << " of file " << __FILE__ << std::endl;
	}
	if (!qsdzTexture.loadFromFile("../Images/SelectionPerso/QSDZselector.png"))
	{
	    std::cout << "Error in line " << __LINE__ << " of file " << __FILE__ << std::endl;
	}
	//update
	//window.display();
}

SelectionPerso::~SelectionPerso(){
	free(positions);
}

void SelectionPerso::select(){
	switch(flechesPos){
		case 0:
			persoFleches = (Personnage *) new Cuddles();
			break;
		case 1:
			persoFleches = (Personnage *) new Bob();
			break;
		case 2:
			persoFleches = (Personnage *) new Homer();
			break;
		case 3:
			persoFleches = (Personnage *) new Pb();
			break;
	}

	switch(qsdzPos){
		case 0:
			persoQsdz = (Personnage *) new Cuddles();
			break;
		case 1:
			persoQsdz = (Personnage *) new Bob();
			break;
		case 2:
			persoQsdz = (Personnage *) new Homer();
			break;
		case 3:
			persoQsdz = (Personnage *) new Pb();
			break;
	}
	nextScreen = 1;
}


void SelectionPerso::render(sf::RenderWindow & window){
	static bool interrupt = false;//nous permet de controler le bouton attaque courte comme interruption

	window.clear();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		if(!interrupt){
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
			interrupt = true;
		}
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		if(!interrupt){
			if(flechesPos - qsdzPos == -1 || (qsdzPos == 0 && flechesPos == nbPerso - 1)){//on est juste à gauche
				if(flechesPos == nbPerso - 2)
					flechesPos = 0;
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
			interrupt = true;
		}
	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
		if(!interrupt){
			if(qsdzPos - flechesPos == 1 || (flechesPos == nbPerso - 1 && qsdzPos == 0)){//on est juste à gauche
				if(qsdzPos == 0)
					qsdzPos = nbPerso - 2;
				else if(qsdzPos == 1)
					qsdzPos = nbPerso - 1;
				else
					qsdzPos -= 2;
			}
			else{
				if(qsdzPos == 0)
					qsdzPos = nbPerso - 1;
				else
					qsdzPos--;
			}
			interrupt = true;
		}
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		if(!interrupt){
			if(qsdzPos - flechesPos == -1 || (flechesPos == 0 && qsdzPos == nbPerso - 1)){//on est juste à droite
				if(qsdzPos == nbPerso - 2)
					qsdzPos = 0;
				else if(qsdzPos == nbPerso - 1)
					qsdzPos = 1;
				else
					qsdzPos += 2;
			}
			else{
				if(qsdzPos == nbPerso - 1)
					qsdzPos = 0;
				else
					qsdzPos++;
			}
			interrupt = true;
		}
	}else if (interrupt)
		interrupt = false;


	flechesSelector.setTexture(flechesTexture);
	flechesSelector.setPosition(positions[flechesPos]);
	window.draw(flechesSelector);
	qsdzSelector.setTexture(qsdzTexture);
	qsdzSelector.setPosition(positions[qsdzPos]);
	window.draw(qsdzSelector);
	window.display();

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		select();
	}

   sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}