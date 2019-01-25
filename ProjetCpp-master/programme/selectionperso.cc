#include "selectionperso.hh"


SelectionPerso::SelectionPerso(sf::RenderWindow & window){
	nbPerso = 4;//nombre de personnages
	int width = 300, height = 300;
	sprites = (sf::Sprite **) malloc(sizeof(sf::Sprite*)*nbPerso);
	textures = (sf::Texture **) malloc(sizeof(sf::Texture*)*nbPerso);

	positions = (sf::Vector2f *) malloc(sizeof(sf::Vector2f)*nbPerso);
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
	//afficher les perso
	for (int i = 0; i <= nbPerso; i++)
		textures[i] = new sf::Texture();
	for (int i = 0; i < nbPerso; i++)
		sprites[i] = new sf::Sprite();
	if (!textures[0]->loadFromFile("../Images/SelectionPerso/cuddles.png"))
	{
	    std::cout << "Error in line " << __LINE__ << " of file " << __FILE__ << std::endl;
	}
	sprites[0]->setTexture(*textures[0]);
	sprites[0]->setPosition(positions[0] + sf::Vector2f(25.f, 25.f));
	if (!textures[1]->loadFromFile("../Images/SelectionPerso/spongeBob.png"))
	{
	    std::cout << "Error in line " << __LINE__ << " of file " << __FILE__ << std::endl;
	}
	sprites[1]->setTexture(*textures[1]);
	sprites[1]->setPosition(positions[1] + sf::Vector2f(25.f, 25.f));
	if (!textures[2]->loadFromFile("../Images/SelectionPerso/homer.png"))
	{
	    std::cout << "Error in line " << __LINE__ << " of file " << __FILE__ << std::endl;
	}
	sprites[2]->setTexture(*textures[2]);
	sprites[2]->setPosition(positions[2] + sf::Vector2f(25.f, 25.f));
	if (!textures[3]->loadFromFile("../Images/SelectionPerso/pb.png"))
	{
	    std::cout << "Error in line " << __LINE__ << " of file " << __FILE__ << std::endl;
	}
	sprites[3]->setTexture(*textures[3]);
	sprites[3]->setPosition(positions[3] + sf::Vector2f(25.f, 25.f));
	if (!textures[4]->loadFromFile("../Images/SelectionPerso/bg.png"))
	{
	    std::cout << "Error in line " << __LINE__ << " of file " << __FILE__ << std::endl;
	}

	music = new sf::Music();

    if (!music->openFromFile("../musique/SelectionRocky.ogg"))
        std::cout << "Error in line " << __LINE__ << " of file " << __FILE__ << std::endl;

    music->play();
}

SelectionPerso::~SelectionPerso(){
	free(positions);
	free (sprites);
	free (textures);
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
	nextScreen = 3;
}


void SelectionPerso::render(sf::RenderWindow & window){
	static bool interrupt = false;//nous permet de controler le bouton attaque courte comme interruption

	window.clear();
	sf::Sprite bgSprite(*textures[nbPerso]);
	window.draw(bgSprite);
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
	for(int i = 0; i < nbPerso; i++){
		window.draw(*sprites[i]);
	}
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