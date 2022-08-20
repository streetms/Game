#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include "Hero.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Game");
    Hero hero(":/images/wizard.png");
    hero.set_position(120,240);
    while (window.isOpen())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000/60));
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        hero.update();
        window.clear();
        window.draw(hero.Sprite());
        window.display();
    }

    return 0;
}