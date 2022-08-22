//
// Created by konstantin on 21.08.22.
//

#include "Object.h"
#include "utility.h"
std::map<std::string_view,sf::Texture> Object::textures;

void Object::fell() {

}

Object::Object(std::string_view path){
    if (textures.find(path) == textures.end()) {
        textures.emplace(path,load_texture_from_file(path));
    }
    texture = &((*(textures.find(path))).second);
    sprite.setTexture(*texture);
}

bool Object::is_weighty() {
    return weighty;
}

bool Object::is_solid() {
    return solid;
}

std::pair<float, float> Object::Position() {
    return std::pair{_x,_y};
}
sf::Sprite Object::Sprite() {
    return sprite;
}

void Object::set_position(float x, float y) {
    sprite.setPosition(x,y);
    _x = x;
    _y = y;
}

void Object::set_speed(float speed) {
    speed_ = speed;
}

float Object::Speed(){
    return speed_;
}