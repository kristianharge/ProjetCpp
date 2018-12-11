#include <iostream>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}

/*#include <unistd.h>
#include <SFML/Graphics.hpp>
#define US_PER_FRAME 16000

using namespace std;

void processInput(){}
void update(){
	cout << 1 << endl;
}
void render(){}

int main()
{
	//code plus lisible
    typedef std::chrono::high_resolution_clock Time;
    typedef std::chrono::microseconds us;
    int usOfWait;

    //boucle jeu
    while(1){
	    auto t0 = Time::now();
	    processInput();
  		update();
  		render();
  		usOfWait = US_PER_FRAME - std::chrono::duration_cast<us>(Time::now() - t0).count();
  		if (usOfWait < 0)
  			usOfWait = 0;

	    usleep(usOfWait);
	}
}*/