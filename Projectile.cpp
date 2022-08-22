//
// Created by konstantin on 22.08.22.
//
#include "Object.h"
#include "Projectile.h"
Projectile::Projectile(Type type, Object* parent) : Object("") {
    sprite.setOrigin(sprite_width/2,sprite_height/2);
    weighty = false;
    solid = true;
    vulnerability = false;
    parent_ = parent;
    std::tie(_x,_y) = parent_->Position();
    auto [x,y] = parent_->Size();
    _y += y / 4;
    if (parent_->state == State::move_right) {
        _x += x / 2 + sprite_width / 2;
    }
    state = parent_->state;
    speed_ = parent_->Speed()*6;
    switch (type) {
        case Type::fireball:
            fireball();
            break;
        case Type::iceArrow:
            iceArrow();
            break;
    }
}

void Projectile::update() {
    _x += speed_;
    sprite.setPosition(_x,_y);
}

std::pair<int, int> Projectile::Size() {
    return {sprite_width,sprite_height};
}

void Projectile::fireball() {
    sprite.setTexture(get_texture(":/images/fireball.png"));
    if (state == State::move_right) {
        sprite.setTextureRect(sf::Rect(0,0,64,32));
    }
    if (state == State::move_left) {
        speed_ *= -1;
        sprite.setTextureRect(sf::Rect(64,0,-64,32));
    }
    sprite.setScale(96./64, 48./32);
}

void Projectile::iceArrow() {
    sprite.setTexture(get_texture(":/images/iceArrow.png"));
    if (state == State::move_right) {
        sprite.setTextureRect(sf::Rect(0,0,144,48));
    }
    if (state == State::move_left) {
        speed_ *= -1;
        sprite.setTextureRect(sf::Rect(144,0,-144,48));
    }
    sprite.setScale(96./144, 48./48);
}
