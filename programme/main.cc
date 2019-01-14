#include <unistd.h>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "ecran.hh"
#include "gameover.hh"
#include "combat.hh"
#include "variablesGlobales.hh"

using namespace std;

typedef std::chrono::high_resolution_clock Time;
typedef std::chrono::microseconds us;

int main()
{
    //ecran
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");//defined in map.hh
    Ecran *ec = (Ecran*) new Combat();

    //gestion du temps
    int usOfWait;

    while (window.isOpen())
    {

        //gestion du temps
        auto t0 = Time::now();
        switch(ec->nextScreen){
            case 2:
                delete ec;
                ec = (Ecran*) new GameOver(window, ((Combat*)ec)->winner, ((Combat*)ec)->looser);
                break;
            default:
                ec->processInput();
                ec->update();
                ec->render(window);
        }
        usOfWait = US_PER_FRAME - std::chrono::duration_cast<us>(Time::now() - t0).count();
        if (usOfWait < 0)
            usOfWait = 0;
        
        usleep(usOfWait);
    }
    delete ec;

    return 0;
}