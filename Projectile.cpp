//
// Created by konstantin on 22.08.22.
//
#include "Object.h"
#include "Projectile.h"
#include <iostream>
Projectile::Projectile(std::string_view path, Object* parent) : Object(path) {
    sprite.setOrigin(sprite_width/2,sprite_height/2);
    weighty = false;
    solid = true;
    vulnerability = false;
    parent_ = parent;
    std::tie(_x,_y) = parent_->Position();
    auto [x,y] = parent_->Size();
    _x += x/2+sprite_width/2;
    _y += y/4;
    state = parent_->state;
    speed_ = parent_->Speed()*6;
    if (state == State::move_right) {
        sprite.setTextureRect(sf::Rect(0,0,64,32));
    }
    if (state == State::move_left) {
        speed_ *= -1;
        sprite.setTextureRect(sf::Rect(64,0,-64,32));
    }
    sprite.setScale(96./64, 48./32);
}

void Projectile::update() {
    _x += speed_;
    sprite.setPosition(_x,_y);
}

std::pair<int, int> Projectile::Size() {
    return {sprite_width,sprite_height};
}
