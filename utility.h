//
// Created by konstantin on 22.08.22.
//

#ifndef GAME_UTILITY_H
#define GAME_UTILITY_H
#include <SFML/Graphics.hpp>
#include <forward_list>
#include <memory>
#include "Projectile.h"
sf::Texture load_texture_from_file(std::string_view path);
void draw_projectiles(std::forward_list<std::unique_ptr<Projectile>>& projectiles, sf::RenderWindow& window);
#endif //GAME_UTILITY_H
