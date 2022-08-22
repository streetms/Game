//
// Created by konstantin on 20.08.22.
//

#include "Hero.h"
Hero::Hero(std::string_view path) : Object(path){
    sprite.setOrigin(sprite_width/2,sprite_height/2);
    life = true;
    height = 100;
    max_height = 100;
    sprite.setTextureRect(sf::Rect(50,120,96,128));
    sprite.setScale(48./96,96./128);
    current_frame = 0;
    speed_ = 0.5;
    state = State::move_right;
    solid = true;
    weighty = true;
    vulnerability = true;
}
void Hero::update() {
    if (state == State::move_right)
        sprite.setTextureRect(sf::Rect(50,120,96,128));
    else
        sprite.setTextureRect(sf::Rect(146,120,-96,128));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        _x-=speed_;
        current_frame += speed_ / 2;
        sprite.setTextureRect(move_left_frame[static_cast<int>(current_frame)%move_right_frame.size()]);
        sprite.setPosition(_x,_y);
        state = State::move_left;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        _x+=speed_;
        current_frame += speed_ / 2;
        sprite.setTextureRect(move_right_frame[static_cast<int>(current_frame)%move_right_frame.size()]);
        sprite.setPosition(_x,_y);
        state = State::move_right;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
       this->shot(Projectile::Type::fireball);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
        this->shot(Projectile::Type::iceArrow);
    }
}

std::forward_list<std::unique_ptr<Projectile>> &Hero::Projectiles() {
    return projectiles;
}

std::pair<int, int> Hero::Size() {
    return {sprite_width,sprite_height};
}

void Hero::shot(Projectile::Type type) {
    projectiles.push_front(std::make_unique<Projectile>(type,this));
}



