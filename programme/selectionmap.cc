#include "selectionmap.hh"


SelectionMap::SelectionMap(sf::RenderWindow & window){
	nbMap = 2;//nombre de cartes
	int width = 300, height = 300;
	

	//window.clear();
	positions = (sf::Vector2f*) malloc(sizeof(sf::Vector2f)*nbMap);
	positions[0] = sf::Vector2f(WIDTH/2 - width, HEIGHT/2 - height);
	positions[1] = sf::Vector2f(WIDTH/2, HEIGHT/2 - height);
	

	positions_map = (sf::Vector2f*) malloc(sizeof(sf::Vector2f)*nbMap);
	positions_map[0] = sf::Vector2f(WIDTH/2 - width/1.7, HEIGHT/2 - (0.6*height));
	positions_map[1] = sf::Vector2f(WIDTH/1.75, HEIGHT/2 - (0.6*height));
	
	
	flechesPos = 0;

	if (!flechesTexture.loadFromFile("../Images/SelectionMap/arrowselector.png"))
	{
	    std::cout << "Error in line " << __LINE__ << " of file " << __FILE__ << std::endl;
	}
	if (!R.loadFromFile("../Images/SelectionMap/rickmap.png"))
	{
	    std::cout << "Error in line " << __LINE__ << " of file " << __FILE__ << std::endl;
	}
	if (!S.loadFromFile("../Images/SelectionMap/simpmap.png"))
	{
	    std::cout << "Error in line " << __LINE__ << " of file " << __FILE__ << std::endl;
	}
	if (!bgTexture.loadFromFile("../Images/SelectionMap/bg.png"))
	{
	    std::cout << "Error in line " << __LINE__ << " of file " << __FILE__ << std::endl;
	}

	music = new sf::Music();

    if (!music->openFromFile("../musique/MainSuperSmash.ogg"))
        std::cout << "Error in line " << __LINE__ << " of file " << __FILE__ << std::endl;
    music->play();
}

SelectionMap::~SelectionMap(){
	free(positions);
}

void SelectionMap::select(){
	switch(flechesPos){
		case 0:
			mapFleches = (Map *) new RickMap();
			break;
		case 1:
			mapFleches = (Map *) new SimpMap();
			break;
	}
	nextScreen = 2;	
}

void SelectionMap::processInput(){
	static bool interrupt = false;//nous permet de controler le bouton attaque courte comme interruption

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		if(!interrupt){
			flechesPos = 0;
		}
			interrupt = true;
	}
	
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		if(!interrupt){
			flechesPos = 1;
		}
			interrupt = true;
	}
	
	
	else if (interrupt)
		interrupt = false;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)){
		select();
	}
}

void SelectionMap::render(sf::RenderWindow & window){

	window.clear();
	bgSprite.setTexture(bgTexture);
	window.draw(bgSprite);
		
	r.setTexture(R);
	r.setPosition(positions_map[0]);
	window.draw(r);
	
	s.setTexture(S);
	s.setPosition(positions_map[1]);
	window.draw(s);
	
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
