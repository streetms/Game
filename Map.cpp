//
// Created by konstantin on 23.08.22.
//
#include <QFile>
#include <iostream>
#include "Map.h"

Map::Map() {
    levels.emplace(1,":/levels/level1");
}

void Map::draw(sf::RenderWindow &window) {
    for (int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            window.draw(field[i][j].Sprite());
            //printf("(%d;%d)\n",i*48+24, j*48+24);
        }
    }
}

void Map::set_level(int level) {
    level_ = level;
    QFile file;
    file.setFileName(levels.find(1)->second.data());
    file.open(QIODevice::ReadOnly);
    for (int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH;j++){
            char ch;
            file.getChar(&ch);
            if (ch != '\n' and ch != -1) {
                field[j][i] = ch;
                field[j][i].set_position(j * 48 + 24, i * 48 + 24);
            } else {
                j++;
            }
        }
    }
    std::cout<< std::endl;
}
