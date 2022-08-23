//
// Created by konstantin on 23.08.22.
//

#ifndef GAME_MAP_H
#define GAME_MAP_H
#include <SFML/Graphics.hpp>
#include <array>
#include "Block.h"
class Map {
    int level_;
    static constexpr int max_level = 1;
    static constexpr int WIDTH = 27;
    static constexpr int HEIGHT = 15;
    std::array<std::array<Block,WIDTH>, WIDTH> field;
    std::map<int,std::string> levels;

public:
    void draw(sf::RenderWindow& window);
    Map(const Map& map) = delete;
    Map operator=(const Map& map) = delete;
    void set_level(int level);
    Map();
};


#endif //GAME_MAP_H
