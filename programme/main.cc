#include <unistd.h>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "combat.hh"
#define US_PER_FRAME 1000000

using namespace std;

typedef std::chrono::high_resolution_clock Time;
typedef std::chrono::microseconds us;

int main()
{
    //ecran
    sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!");
    Combat combat;//classe qui gere le combat

    //gestion du temps
    int usOfWait;

    while (window.isOpen())
    {
        //gestion du temps
        auto t0 = Time::now();
        combat.processInput();
        combat.update();
        combat.render(window);
        usOfWait = US_PER_FRAME - std::chrono::duration_cast<us>(Time::now() - t0).count();
        if (usOfWait < 0)
            usOfWait = 0;
        
        usleep(usOfWait);
    }
    return 0;
}