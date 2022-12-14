//
// Created by konstantin on 21.08.22.
//
#include <QFile>
#include "Object.h"
std::map<std::string_view,sf::Texture> Object::textures;

Object::State Object::get_state() const {
    return state;
}
std::pair <int,int> Object::Size() const {
  return {sprite_width,sprite_height};
}

std::pair<float, float> Object::Position() const {
    return std::pair{_x,_y};
}
sf::Sprite Object::Sprite() const {
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

float Object::Speed() const {
    return speed_;
}

void Object::add_texture(std::string_view path) {
    textures.emplace(path, load_texture_from_file(path));
}

const sf::Texture &Object::get_texture(std::string_view path) const {
    return textures.find(path)->second;
}

Object::Object() {

}

sf::Texture Object::load_texture_from_file(std::string_view path) {
    sf::Texture texture;
    QFile file;
    file.setFileName(path.data());
    file.open(QIODevice::ReadOnly);
    texture.loadFromMemory(file.readAll().data(),file.size());
    return texture;
}