#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include "creatures/Hero.h"
#include "Map.h"
constexpr static int WIDTH = 1280;
constexpr static int HEIGHT = 720;

int main()
{
    Object::add_texture(":/images/fireball.png");
    Object::add_texture(":/images/iceArrow.png");
    Object::add_texture(":/images/wall.png");
    Object::add_texture(":/images/wizard.png");
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Game");
    Map map;
    map.set_level(1);
    Hero *hero = new Hero(map);
    hero->set_position(24,48);
    hero->set_speed(0.7);

    while (window.isOpen()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000/60));
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        map.draw(window);
        window.display();
    }
    return 0;
}