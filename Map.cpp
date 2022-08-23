//
// Created by konstantin on 23.08.22.
//
#include <QFile>
#include <iostream>
#include "Map.h"
#include "Object.h"
Map::Map() {
    levels.emplace(1,":/levels/level1");
}

void Map::draw(sf::RenderWindow &window) {
    for (int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            window.draw(field[i][j].Sprite());
        }
    }
    for (auto& obj : objects) {
        obj->update();
        window.draw(obj->Sprite());
    }
    auto cur = objects.begin();
    while (cur != objects.end()) {
        auto t = cur;
        cur++;
        float x, y;
        std::tie(x,y) = t->get()->Position();
        if (x <= 0 or x >= window.getSize().x) {
            objects.remove(*t);
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

void Map::add_object(Object* object) {
    objects.push_front(static_cast<std::unique_ptr<Object>>(object));
}
