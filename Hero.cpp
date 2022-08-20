//
// Created by konstantin on 20.08.22.
//

#include "Hero.h"
#include <QFile>
Hero::Hero(std::string_view path) {
    life = true;
    height = 100;
    max_height = 100;
    QFile file;
    file.setFileName(path.data());
    file.open(QIODevice::ReadOnly);
    texture.loadFromMemory(file.readAll().data(),file.size());
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::Rect(50,120,96,130));
    sprite.setScale(2/3.,2/3.);
    current_frame = 0;
    _x = 0;
    _y = 0;
    speed = 0.5;
}

sf::Sprite Hero::Sprite() {
    return sprite;
}

void Hero::set_position(float x, float y) {
    sprite.setPosition(x,y);
    _x = x;
    _y = y;
}

void Hero::update() {
    sprite.setTextureRect(sf::Rect(50,120,96,130));//stay
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        _x-=speed;
        current_frame += speed/3;
        sprite.setTextureRect(move_left_frame[static_cast<int>(current_frame)%move_right_frame.size()]);
        sprite.setPosition(_x,_y);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        _x+=speed;
        current_frame += speed/3;
        sprite.setTextureRect(move_right_frame[static_cast<int>(current_frame)%move_right_frame.size()]);
        sprite.setPosition(_x,_y);
    }
}
