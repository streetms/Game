#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include "Hero.h"
#include "utility.h"
constexpr static int WIDTH = 1280;
constexpr static int HEIGHT = 720;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Game");
    Hero hero(":/images/wizard.png");
    hero.set_position(24,48);
    hero.set_speed(0.7);
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
        draw_projectiles(hero.Projectiles(),window);
        window.display();
    }
    return 0;
}